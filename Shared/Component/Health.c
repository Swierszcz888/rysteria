// Copyright (C) 2024 Paul Johnson
// Copyright (C) 2024-2025 Maxim Nesterov

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <Shared/Component/Health.h>

#include <math.h>
#include <stdio.h>
#include <string.h>

#include <Shared/Entity.h>
#include <Shared/SimulationCommon.h>
#include <Shared/pb.h>

#define FOR_EACH_PUBLIC_FIELD                                                  \
    X(health, float32)                                                         \
    X(flags, uint8)                                                            \
    X(max_health, float32)                                                     \
    X(shield, float32)

enum
{
    state_flags_max_health = 0b001,
    state_flags_flags = 0b010,
    state_flags_health = 0b100,
    state_flags_shield = 0b1000,
    state_flags_all = 0b1111
};

void rr_component_health_init(struct rr_component_health *this,
                              struct rr_simulation *simulation)
{
    memset(this, 0, sizeof *this);
    this->health = 1;
    this->max_health = 1;
}

void rr_component_health_free(struct rr_component_health *this,
                              struct rr_simulation *simulation)
{
}

#ifdef RR_SERVER
#include <Server/Client.h>
#include <Server/Simulation.h>

#include <Shared/StaticData.h>

void rr_component_health_write(struct rr_component_health *this,
                               struct proto_bug *encoder, int is_creation,
                               struct rr_component_player_info *client)
{
    uint64_t state = this->protocol_state | (state_flags_all * is_creation);
    proto_bug_write_varuint(encoder, state, "health component state");
    float tmp_health = this->health;
    float tmp_max = this->max_health;
    if (this->flags & 1)
    {
        this->health = this->max_health = 0;
    }
#define X(NAME, TYPE) RR_ENCODE_PUBLIC_FIELD(NAME, TYPE);
    FOR_EACH_PUBLIC_FIELD
#undef X
    this->health = tmp_health;
    this->max_health = tmp_max;
}

void rr_component_health_do_damage(struct rr_simulation *simulation,
                                   struct rr_component_health *this,
                                   EntityIdx from, float v, uint8_t color_type)
{
    uint8_t no_reduction = this->flags & 4;
    this->flags &= ~4;
    if (dev_cheat_enabled(simulation, this->parent_id, invulnerable))
        return;
    if (this->health == 0)
        return;
    if (v == 0)
        return;
    /*if (rr_simulation_has_mob(simulation, from))
    {
        struct rr_component_mob *from_mob = rr_simulation_get_mob(simulation, from);
        if (from_mob->id == rr_mob_id_edmontosaurus)
            no_reduction = 1; // blame Lans ST
        if (rr_simulation_has_mob(simulation, this->parent_id))
        {
            struct rr_component_mob *mob = rr_simulation_get_mob(simulation, this->parent_id);
            if (mob->id == rr_mob_id_edmontosaurus && from_mob->player_spawned &&
                (from_mob->rarity < mob->rarity || from_mob->rarity - mob->rarity < 2))
                return; // blame Lans ST
        }
    }*/
    if (!no_reduction)
    {
        v *= 1 - this->damage_reduction_ratio;
        v -= this->damage_reduction;
    }
    if (v < 0)
        v = 0;
    v = this->health - v;
    if (v < 0)
        v = 0;
    float damage = this->health - v;
    rr_component_health_set_health(this, v);
    EntityHash p_info_id =
        rr_simulation_get_relations(simulation, from)->root_owner;
    if (!rr_simulation_entity_alive(simulation, p_info_id))
        return;
    if (!rr_simulation_has_player_info(simulation, p_info_id))
        return;
    if (!rr_simulation_has_mob(simulation, this->parent_id) &&
        !rr_simulation_has_flower(simulation, this->parent_id))
        return;
    if (rr_simulation_has_mob(simulation, this->parent_id) &&
        rr_simulation_get_mob(simulation, this->parent_id)->player_spawned)
        return;
    if (is_same_team(
            rr_simulation_get_relations(simulation, this->parent_id)->team,
            rr_simulation_get_relations(simulation, from)->team))
        return;
    struct rr_component_player_info *player_info =
        rr_simulation_get_player_info(simulation, p_info_id);
    this->squad_damage_counter[player_info->squad] += damage;
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, this->parent_id);
    struct rr_simulation_animation *animation =
        &simulation->animations[simulation->animation_length++];
    animation->type = rr_animation_type_damagenumber;
    animation->owner = from;
    animation->x = physical->x;
    animation->y = physical->y;
    animation->damage = ceilf(damage);
    animation->squad = player_info->squad;
    animation->color_type = color_type;
}

void rr_component_health_set_health(struct rr_component_health *this, float v)
{
    if (this->health == 0)
        return;
    if (v > this->max_health)
        v = this->max_health;
    else if (v < 0)
        v = 0;
    if (v < this->health)
        rr_component_health_set_flags(this, this->flags | 2);
    this->protocol_state |= (v != this->health) * state_flags_health;
    this->health = v;
}

RR_DEFINE_PUBLIC_FIELD(health, float, max_health)
RR_DEFINE_PUBLIC_FIELD(health, float, shield)
RR_DEFINE_PUBLIC_FIELD(health, uint8_t, flags)

#endif

#ifdef RR_CLIENT
void rr_component_health_read(struct rr_component_health *this,
                              struct proto_bug *encoder)
{
    uint64_t state = proto_bug_read_varuint(encoder, "health component state");
#define X(NAME, TYPE) RR_DECODE_PUBLIC_FIELD(NAME, TYPE);
    FOR_EACH_PUBLIC_FIELD
#undef X
}
#endif
