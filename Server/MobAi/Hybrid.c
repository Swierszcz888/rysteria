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

#include <Server/MobAi/Ai.h>

#include <math.h>

#include <Server/EntityAllocation.h>
#include <Server/Simulation.h>

void tick_ai_default(EntityIdx entity, struct rr_simulation *simulation,
                     float speed)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);
    if (ai->ai_type == rr_ai_type_none)
        return;
    if (should_aggro(simulation, ai))
    {
        ai->ai_state = rr_ai_state_attacking;
        ai->ticks_until_next_action = 25;
    }

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
        tick_idle(entity, simulation);
        break;

    case rr_ai_state_idle_moving:
        tick_idle_move_default(entity, simulation);
        break;
    case rr_ai_state_attacking:
    {
        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        // struct rr_vector prediction = predict(delta, physical2->velocity, 4);
        float target_angle = rr_vector_theta(&delta);

        rr_component_physical_set_angle(
            physical, rr_angle_lerp(physical->angle, target_angle, 0.4));

        rr_vector_from_polar(&accel, speed, physical->angle);
        rr_vector_add(&physical->acceleration, &accel);
        ai->ticks_until_next_action = 2;
        break;
    }
    default:
        break;
    }
}

void tick_ai_triceratops(EntityIdx entity, struct rr_simulation *simulation)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);

    if (should_aggro(simulation, ai))
    {
        ai->ai_state = rr_ai_state_waiting_to_attack;
        ai->ticks_until_next_action = 18;
    }

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
        tick_idle(entity, simulation);
        break;

    case rr_ai_state_idle_moving:
        tick_idle_move_default(entity, simulation);
        break;
    case rr_ai_state_waiting_to_attack:
    {
        if (ai->ticks_until_next_action == 0)
        {
            ai->ai_state = rr_ai_state_attacking;
            ai->ticks_until_next_action = rand() % 25 + 63;
            break;
        }

        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        struct rr_vector prediction =
            predict(delta, physical2->velocity, ai->has_prediction * 15);
        rr_component_physical_set_angle(physical, rr_vector_theta(&prediction));
        break;
    }
    case rr_ai_state_attacking:
    {
        if (ai->ticks_until_next_action == 0)
        {
            ai->ai_state = rr_ai_state_waiting_to_attack;
            ai->ticks_until_next_action = rand() % 12 + 12;
            break;
        }

        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        struct rr_vector prediction =
            predict(delta, physical2->velocity, ai->has_prediction * 15);
        float target_angle = rr_vector_theta(&prediction);

        rr_component_physical_set_angle(
            physical, rr_angle_lerp(physical->angle, target_angle, 0.25));

        rr_vector_from_polar(&accel, RR_PLAYER_SPEED * 1.3, physical->angle);
        rr_vector_add(&physical->acceleration, &accel);
        break;
    }
    default:
        break;
    }
}

void tick_ai_trex(EntityIdx entity, struct rr_simulation *simulation)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);
    if (should_aggro(simulation, ai))
    {
        ai->ai_state = rr_ai_state_attacking;
        ai->ticks_until_next_action = 300;
    }

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
        tick_idle(entity, simulation);
        break;

    case rr_ai_state_idle_moving:
        tick_idle_move_default(entity, simulation);
        break;
    case rr_ai_state_attacking:
    {
        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        // struct rr_vector prediction = predict(delta, physical2->velocity, 4);
        float target_angle = rr_vector_theta(&delta);

        rr_component_physical_set_angle(
            physical, rr_angle_lerp(physical->angle, target_angle, 0.4));

        rr_vector_from_polar(&accel, RR_PLAYER_SPEED * 1.05, physical->angle);
        rr_vector_add(&physical->acceleration, &accel);
        if (ai->ticks_until_next_action == 0)
        {
            if (rr_simulation_get_mob(simulation, entity)->rarity >=
                rr_rarity_id_exotic)
                ai->ai_state = rr_ai_state_exotic_special;
            ai->ticks_until_next_action = 15;
        }
        break;
    }
    case rr_ai_state_exotic_special:
    {
        if (ai->ticks_until_next_action == 0)
        {
            struct rr_component_mob *mob =
                rr_simulation_get_mob(simulation, entity);
            struct rr_component_relations *relations =
                rr_simulation_get_relations(simulation, entity);
            float angle = rr_frand() * M_PI + M_PI / 2;
            EntityIdx entity1 = rr_simulation_alloc_mob(
                simulation, physical->arena,
                physical->x + physical->radius * cosf(angle),
                physical->y + physical->radius * sinf(angle), rr_mob_id_trex,
                mob->rarity - 2, relations->team);
            EntityIdx entity2 = rr_simulation_alloc_mob(
                simulation, physical->arena,
                physical->x + physical->radius * cosf(2 * M_PI - angle),
                physical->y + physical->radius * sinf(2 * M_PI - angle),
                rr_mob_id_trex, mob->rarity - 2, relations->team);
            struct rr_component_mob *mob1 =
                rr_simulation_get_mob(simulation, entity1);
            struct rr_component_mob *mob2 =
                rr_simulation_get_mob(simulation, entity2);
            mob1->no_drop = mob->no_drop;
            mob2->no_drop = mob->no_drop;
            if (mob->player_spawned)
            {
                rr_component_mob_set_player_spawned(mob1, 1);
                rr_component_mob_set_player_spawned(mob2, 1);
                struct rr_component_relations *relations1 =
                    rr_simulation_get_relations(simulation, entity1);
                struct rr_component_relations *relations2 =
                    rr_simulation_get_relations(simulation, entity2);
                EntityHash owner =
                    rr_simulation_get_entity_hash(simulation, relations->owner);
                rr_component_relations_set_owner(relations1, owner);
                rr_component_relations_set_owner(relations2, owner);
                rr_component_relations_update_root_owner(simulation, relations1);
                rr_component_relations_update_root_owner(simulation, relations2);
            }
            ai->ai_state = rr_ai_state_attacking;
            ai->ticks_until_next_action = 300;
        }
        break;
    }
    default:
        break;
    }
}

void tick_ai_pteranodon(EntityIdx entity, struct rr_simulation *simulation)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);

    if (should_aggro(simulation, ai))
        ai->ai_state = rr_ai_state_attacking;

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
        tick_idle(entity, simulation);
        break;
    case rr_ai_state_idle_moving:
        tick_idle_move_default(entity, simulation);
        break;
    case rr_ai_state_attacking:
    {
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        struct rr_vector prediction =
            predict(delta, physical2->velocity,
                    (ai->has_prediction ||
                     rr_simulation_get_mob(simulation, entity)->rarity >=
                         rr_rarity_id_exotic) *
                        20); // make this less op
        rr_component_physical_set_angle(physical, rr_vector_theta(&prediction));
        if (rr_vector_magnitude_cmp(&delta, 500) == 1)
        {
            struct rr_vector accel;
            rr_vector_from_polar(&accel, RR_PLAYER_SPEED, physical->angle);
            rr_vector_add(&physical->acceleration, &accel);
        }
        if (ai->ticks_until_next_action == 0)
        {
            if (rr_simulation_get_mob(simulation, entity)->rarity >=
                    rr_rarity_id_exotic &&
                rr_frand() < 0.2)
            {
                ai->ai_state = rr_ai_state_exotic_special;
                ai->ticks_until_next_action = 75;
                break;
            }
            ai->ticks_until_next_action = 50;

            struct rr_component_mob *mob =
                rr_simulation_get_mob(simulation, entity);
            // spawn a shell
            EntityIdx petal_id = rr_simulation_alloc_petal(
                simulation, physical->arena, physical->x, physical->y,
                rr_petal_id_shell, mob->rarity, mob->parent_id);
            struct rr_component_physical *physical2 =
                rr_simulation_get_physical(simulation, petal_id);
            struct rr_component_health *health =
                rr_simulation_get_health(simulation, petal_id);
            rr_component_physical_set_angle(physical2, physical->angle);
            rr_component_physical_set_radius(
                physical2, 10 * RR_MOB_RARITY_SCALING[mob->rarity].radius);
            physical2->friction = 0.45f;
            physical2->mass = 5.0f;
            physical2->knockback_scale = 2.5f * (mob->rarity + 1);
            physical2->bearing_angle = physical->angle;
            rr_vector_from_polar(&physical2->velocity, 100, physical->angle);
            rr_component_petal_set_detached(
                rr_simulation_get_petal(simulation, petal_id), 1);
            rr_component_health_set_max_health(
                health, 5 * RR_MOB_RARITY_SCALING[mob->rarity].health);
            rr_component_health_set_health(health, health->max_health);
            health->damage = 10 * RR_MOB_RARITY_SCALING[mob->rarity].damage;
            rr_simulation_get_petal(simulation, petal_id)->effect_delay = 50;
            struct rr_vector recoil;
            rr_vector_from_polar(&recoil, -5,
                                 physical->angle); // recoil
            rr_vector_add(&physical->acceleration, &recoil);
        }
        break;
    }
    case rr_ai_state_exotic_special:
    {
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        struct rr_vector prediction =
            predict(delta, physical2->velocity,
                    ai->has_prediction * 20); // make this less op
        rr_component_physical_set_angle(physical, rr_vector_theta(&prediction));
        if (ai->ticks_until_next_action < 50)
        {
            struct rr_vector accel;
            rr_vector_from_polar(&accel, RR_PLAYER_SPEED * 2, physical->angle);
            rr_vector_add(&physical->acceleration, &accel);
        }
        if (ai->ticks_until_next_action == 0)
        {
            ai->ai_state = rr_ai_state_attacking;
            ai->ticks_until_next_action = 50;
        }
        break;
    }
    default:
        break;
    }
}

void tick_ai_pachycephalosaurus(EntityIdx entity,
                                struct rr_simulation *simulation)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);
    if (should_aggro(simulation, ai))
        ai->ai_state = rr_ai_state_attacking;

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
        tick_idle(entity, simulation);
        break;

    case rr_ai_state_idle_moving:
        tick_idle_move_default(entity, simulation);
        break;
    case rr_ai_state_attacking:
    {
        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        // struct rr_vector prediction = predict(delta, physical2->velocity, 4);
        float target_angle = rr_vector_theta(&delta);

        rr_component_physical_set_angle(physical, target_angle);

        rr_vector_from_polar(&accel, RR_PLAYER_SPEED, physical->angle);
        rr_vector_add(&physical->acceleration, &accel);
        ai->ticks_until_next_action = 25;
        if (rr_vector_magnitude_cmp(&delta, 350) == -1)
            ai->ai_state = rr_ai_state_charging;
        break;
    }
    case rr_ai_state_charging:
    {
        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        rr_vector_from_polar(&accel, RR_PLAYER_SPEED * 1.8, physical->angle);
        rr_vector_add(&physical->acceleration, &accel);
        if (ai->ticks_until_next_action == 0)
        {
            ai->ticks_until_next_action = 25;
            ai->ai_state = rr_ai_state_attacking;
        }
        break;
    }
    default:
        break;
    }
}

void tick_ai_ornithomimus(EntityIdx entity, struct rr_simulation *simulation)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);

    if (should_aggro(simulation, ai))
    {
        ai->ai_state = rr_ai_state_attacking;
        ai->ticks_until_next_action = -1;
    }

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
        tick_idle(entity, simulation);
        break;

    case rr_ai_state_idle_moving:
        tick_idle_move_default(entity, simulation);
        break;
    case rr_ai_state_attacking:
    {
        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        if (rr_simulation_get_mob(simulation, entity)->rarity >=
                rr_rarity_id_exotic ||
            rr_simulation_has_petal(simulation, ai->target_entity) ||
            ai->ai_type == rr_ai_type_aggro)
            physical->bearing_angle = rr_vector_theta(&delta);
        else
            physical->bearing_angle = rr_vector_theta(&delta) + M_PI;

        tick_idle_move_sinusoid(entity, simulation, RR_PLAYER_SPEED);
        break;
    }
    default:
        break;
    }
}

void tick_ai_ankylosaurus(EntityIdx entity, struct rr_simulation *simulation)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);
    if (should_aggro(simulation, ai))
    {
        ai->ai_state = rr_ai_state_attacking;
        ai->ticks_until_next_action = 10;
    }
    physical->knockback_scale = 1;

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
        tick_idle(entity, simulation);
        break;

    case rr_ai_state_idle_moving:
        tick_idle_move_default(entity, simulation);
        break;
    case rr_ai_state_attacking:
    {
        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        // struct rr_vector prediction = predict(delta, physical2->velocity, 4);
        float target_angle = rr_vector_theta(&delta);

        rr_component_physical_set_angle(physical, target_angle);

        rr_vector_from_polar(&accel, RR_PLAYER_SPEED * 1.1, physical->angle);
        rr_vector_add(&physical->acceleration, &accel);
        ai->ticks_until_next_action = 10;
        if (rr_vector_magnitude_cmp(&delta, 100 + physical->radius) == -1)
        {
            ai->ai_state = (rr_simulation_get_mob(simulation, entity)->rarity >=
                                rr_rarity_id_exotic &&
                            rr_frand() < 0.2)
                               ? rr_ai_state_exotic_special
                               : rr_ai_state_charging;
            ai->ticks_until_next_action = 5;
        }
        break;
    }
    case rr_ai_state_charging:
    {
        physical->knockback_scale = 25;
        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        float target_angle = rr_vector_theta(&delta);

        rr_component_physical_set_angle(physical, target_angle);

        rr_vector_from_polar(&accel, RR_PLAYER_SPEED * 1.8, physical->angle);
        rr_vector_add(&physical->acceleration, &accel);
        if (ai->ticks_until_next_action == 0)
        {
            ai->ticks_until_next_action = 10;
            ai->ai_state = rr_ai_state_attacking;
        }
        break;
    }
    case rr_ai_state_exotic_special:
    {
        physical->knockback_scale = -125;
        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        float target_angle = rr_vector_theta(&delta);

        rr_component_physical_set_angle(physical, target_angle + M_PI);

        rr_vector_from_polar(&accel, RR_PLAYER_SPEED * -15.0, physical->angle);
        rr_vector_add(&physical->acceleration, &accel);
        if (ai->ticks_until_next_action == 0)
        {
            ai->ticks_until_next_action = 10;
            ai->ai_state = rr_ai_state_attacking;
        }
        break;
    }
    default:
        break;
    }
}

void tick_ai_meteor(EntityIdx entity, struct rr_simulation *simulation)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
        physical->bearing_angle = rr_frand() * M_PI * 2;
        ai->ai_state = rr_ai_state_idle_moving;
        break;
    case rr_ai_state_idle_moving:
        ai->ticks_until_next_action = 10;
        struct rr_vector normal = {physical->wall_collision.x,
                                   physical->wall_collision.y};
        if (rr_vector_get_magnitude(&normal) != 0)
        {
            float angle = rr_vector_theta(&normal);
            physical->bearing_angle =
                (2 * angle - (M_PI + physical->bearing_angle));
        }

        rr_vector_from_polar(&physical->acceleration, RR_PLAYER_SPEED * 0.15,
                             physical->bearing_angle);
        rr_component_physical_set_angle(physical, physical->angle + 0.1);
        break;
    default:
        break;
    }
}

void tick_ai_quetzalcoaltus(EntityIdx entity, struct rr_simulation *simulation)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);

    if (should_aggro(simulation, ai))
    {
        ai->ai_state = rr_ai_state_attacking;
        ai->ticks_until_next_action = 20;
    }
    physical->knockback_scale = 1;

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
        tick_idle(entity, simulation);
        break;
    case rr_ai_state_idle_moving:
        tick_idle_move_default(entity, simulation);
        break;
    case rr_ai_state_attacking:
    {
        physical->knockback_scale = 10;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        rr_component_physical_set_angle(physical, rr_vector_theta(&delta));
        if (ai->ticks_until_next_action == 0)
        {
            ai->ticks_until_next_action = 20;

            rr_vector_from_polar(&delta, RR_PLAYER_SPEED * 18, physical->angle);
            rr_vector_add(&physical->acceleration, &delta);
        }
        if (rr_vector_magnitude_cmp(&delta, 900 + physical->radius) == 1 && rr_vector_magnitude_cmp(&delta, 1000 + physical->radius) == -1 &&
                            rr_frand() < 0.02)
        {
            ai->ai_state = (rr_simulation_get_mob(simulation, entity)->rarity >=
                                rr_rarity_id_exotic)
                               ? rr_ai_state_exotic_special
                               : rr_ai_state_attacking;
            ai->ticks_until_next_action = 10;
        }
        break;
    }
    case rr_ai_state_exotic_special:
    {
        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        float target_angle = rr_vector_theta(&delta);

        rr_component_physical_set_angle(physical, target_angle);
        if (ai->ticks_until_next_action == 9)
        {
        physical->phasing = 1;
        rr_vector_from_polar(&accel, RR_PLAYER_SPEED * 85.0, physical->angle);
        rr_vector_add(&physical->acceleration, &accel);
        }
        physical->knockback_scale = 50;
        if (ai->ticks_until_next_action == 1)
        {
            physical->phasing = 0;
        }
        if (ai->ticks_until_next_action == 0)
        {
        ai->ai_state = rr_ai_state_attacking;
        ai->ticks_until_next_action = 40;
        }
        break;
    }
    default:
        break;
    }
}

void tick_ai_hornet(EntityIdx entity, struct rr_simulation *simulation)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);

    if (should_aggro(simulation, ai))
        ai->ai_state = rr_ai_state_attacking;

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
        tick_idle(entity, simulation);
        break;
    case rr_ai_state_idle_moving:
        tick_idle_move_default(entity, simulation);
        break;
    case rr_ai_state_attacking:
    {
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        struct rr_vector prediction =
            predict(delta, physical2->velocity,
                    (ai->has_prediction ||
                     rr_simulation_get_mob(simulation, entity)->rarity >=
                         rr_rarity_id_exotic) *
                        20); // make this less op
        rr_component_physical_set_angle(physical, rr_vector_theta(&prediction));
        if (rr_vector_magnitude_cmp(&delta, 500) == 1)
        {
            struct rr_vector accel;
            rr_vector_from_polar(&accel, RR_PLAYER_SPEED * 1.05, physical->angle);
            rr_vector_add(&physical->acceleration, &accel);
        }
        if (ai->ticks_until_next_action == 0)
        {
            if (rr_simulation_get_mob(simulation, entity)->rarity >=
                    rr_rarity_id_exotic &&
                rr_frand() < 0.2)
            {
                ai->ai_state = rr_ai_state_exotic_special;
                ai->ticks_until_next_action = 35;
                break;
            }
            ai->ticks_until_next_action = 25;

            struct rr_component_mob *mob =
                rr_simulation_get_mob(simulation, entity);
            // spawn a missile
            EntityIdx petal_id = rr_simulation_alloc_petal(
                simulation, physical->arena, physical->x, physical->y,
                rr_petal_id_missile, mob->rarity, mob->parent_id);
            struct rr_component_physical *physical2 =
                rr_simulation_get_physical(simulation, petal_id);
            struct rr_component_health *health =
                rr_simulation_get_health(simulation, petal_id);
            rr_component_physical_set_angle(physical2, physical->angle);
            rr_component_physical_set_radius(
                physical2, 5 * RR_MOB_RARITY_SCALING[mob->rarity].radius);
            physical2->friction = 0.75f;
            physical2->mass = 5.0f;
            physical2->knockback_scale = 2.5f * (mob->rarity + 1);
            physical2->bearing_angle = physical->angle;
            rr_vector_from_polar(&physical2->velocity, 10 * (mob->rarity + 1), physical->angle);
            rr_component_petal_set_detached(
                rr_simulation_get_petal(simulation, petal_id), 1);
            rr_component_health_set_max_health(
                health, 1 * RR_MOB_RARITY_SCALING[mob->rarity].health);
            rr_component_health_set_health(health, health->max_health);
            health->damage = 10 * RR_MOB_RARITY_SCALING[mob->rarity].damage;
            rr_simulation_get_petal(simulation, petal_id)->effect_delay = 25;
            struct rr_vector recoil;
            rr_vector_from_polar(&recoil, -5,
                                 physical->angle); // recoil
            rr_vector_add(&physical->acceleration, &recoil);
        }
        break;
    }
    case rr_ai_state_exotic_special:
    {
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        struct rr_vector prediction =
            predict(delta, physical2->velocity,
                    ai->has_prediction * 20); // make this less op
        rr_component_physical_set_angle(physical, rr_vector_theta(&prediction));
        if (ai->ticks_until_next_action < 5)
        {
            struct rr_component_mob *mob =
                rr_simulation_get_mob(simulation, entity);
            // spawn a missile
            EntityIdx petal_id = rr_simulation_alloc_petal(
                simulation, physical->arena, physical->x, physical->y,
                rr_petal_id_missile, mob->rarity, mob->parent_id);
            struct rr_component_physical *physical2 =
                rr_simulation_get_physical(simulation, petal_id);
            struct rr_component_health *health =
                rr_simulation_get_health(simulation, petal_id);
            rr_component_physical_set_angle(physical2, physical->angle);
            rr_component_physical_set_radius(
                physical2, 3 * RR_MOB_RARITY_SCALING[mob->rarity].radius);
            physical2->friction = 0.75f;
            physical2->mass = 5.0f;
            physical2->knockback_scale = 2.5f * (mob->rarity + 1);
            physical2->bearing_angle = physical->angle;
            rr_vector_from_polar(&physical2->velocity, 10 * (mob->rarity + 1), physical->angle);
            rr_component_petal_set_detached(
                rr_simulation_get_petal(simulation, petal_id), 1);
            rr_component_health_set_max_health(
                health, 1 * RR_MOB_RARITY_SCALING[mob->rarity].health);
            rr_component_health_set_health(health, health->max_health);
            health->damage = 25 * RR_MOB_RARITY_SCALING[mob->rarity].damage;
            rr_simulation_get_petal(simulation, petal_id)->effect_delay = 25;
            struct rr_vector recoil;
            rr_vector_from_polar(&recoil, -1,
                                 physical->angle); // recoil
            rr_vector_add(&physical->acceleration, &recoil);
        }
        if (ai->ticks_until_next_action == 0)
        {
            ai->ai_state = rr_ai_state_attacking;
            ai->ticks_until_next_action = 25;
        }
        break;
    }
    default:
        break;
    }
}

void tick_ai_dragonfly(EntityIdx entity, struct rr_simulation *simulation)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);
    if (should_aggro(simulation, ai))
    {
        ai->ai_state = rr_ai_state_attacking;
        ai->ticks_until_next_action = 10;
    }
    physical->phasing = 0;
    physical->knockback_scale = 1;

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
        tick_idle(entity, simulation);
        break;

    case rr_ai_state_idle_moving:
        tick_idle_move_default(entity, simulation);
        break;
    case rr_ai_state_attacking:
    {
        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        // struct rr_vector prediction = predict(delta, physical2->velocity, 4);
        physical->bearing_angle = rr_vector_theta(&delta);

        tick_idle_move_sinusoid(entity, simulation, RR_PLAYER_SPEED * 1.5);
        if (ai->ticks_until_next_action == 0)
        ai->ai_state = rr_ai_state_charging;
        break;
    }
    case rr_ai_state_charging:
    {
        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        // struct rr_vector prediction = predict(delta, physical2->velocity, 4);
        physical->bearing_angle = rr_vector_theta(&delta);

        tick_idle_move_sinusoid(entity, simulation, RR_PLAYER_SPEED * 1.5);
        if (rr_vector_magnitude_cmp(&delta, 75 + physical->radius) == -1)
        {
            ai->ai_state = rr_ai_state_dashing;
            ai->ticks_until_next_action = 1;
        }
        break;
    }
    case rr_ai_state_dashing:
    {
        physical->phasing = 1;
        physical->knockback_scale = 0;
        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        float target_angle = rr_vector_theta(&delta);

        rr_component_physical_set_angle(physical, target_angle);
        if (rr_simulation_get_mob(simulation, entity)->rarity >= rr_rarity_id_exotic)
        rr_vector_from_polar(&accel, RR_PLAYER_SPEED * 40.0, physical->angle);
        else
        rr_vector_from_polar(&accel, RR_PLAYER_SPEED * 25.0, physical->angle);
        rr_vector_add(&physical->acceleration, &accel);
        if (ai->ticks_until_next_action == 0)
        {
            ai->ticks_until_next_action = 25 + rand() % (100 - 25);
            ai->ai_state = rr_ai_state_attacking;
        }
        break;
    }
    default:
        break;
    }
}

void tick_ai_honeybee(EntityIdx entity, struct rr_simulation *simulation)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);

    if (should_aggro(simulation, ai))
    {
        ai->ai_state = rr_ai_state_attacking;
        ai->ticks_until_next_action = -1;
    }

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
        tick_idle(entity, simulation);
        break;

    case rr_ai_state_idle_moving:
        tick_idle_move_default(entity, simulation);
        break;
    case rr_ai_state_attacking:
    {
        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        
        physical->bearing_angle = rr_vector_theta(&delta);

        tick_idle_move_sinusoid(entity, simulation, RR_PLAYER_SPEED * 1.5);
        break;
    }
    default:
        break;
    }
}

void tick_ai_spider(EntityIdx entity, struct rr_simulation *simulation,
                     float speed)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);
    if (ai->ai_type == rr_ai_type_none)
        return;
    if (should_aggro(simulation, ai))
    {
        ai->ai_state = rr_ai_state_attacking;
        ai->ticks_until_next_action = 10;
    }

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
        tick_idle(entity, simulation);
        break;

    case rr_ai_state_idle_moving:
        tick_idle_move_default(entity, simulation);
        break;
    case rr_ai_state_attacking:
    {
        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        // struct rr_vector prediction = predict(delta, physical2->velocity, 4);
        float target_angle = rr_vector_theta(&delta);

        rr_component_physical_set_angle(
            physical, rr_angle_lerp(physical->angle, target_angle, 0.4));

        rr_vector_from_polar(&accel, speed, physical->angle);
        rr_vector_add(&physical->acceleration, &accel);

        if (ai->ticks_until_next_action == 0)
        {
            if (rr_simulation_get_mob(simulation, entity)->rarity >=
                rr_rarity_id_exotic)
                ai->ai_state = rr_ai_state_exotic_special;
        }
        break;
    }
    case rr_ai_state_exotic_special:
    {
        struct rr_component_mob *mob =
            rr_simulation_get_mob(simulation, entity);
        // spawn a web
        EntityIdx petal_id = rr_simulation_alloc_petal(
            simulation, physical->arena, physical->x, physical->y,
            rr_petal_id_web, mob->rarity - 3, mob->parent_id);
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, petal_id);
        rr_component_petal_set_detached(
            rr_simulation_get_petal(simulation, petal_id), 1);
        rr_simulation_get_petal(simulation, petal_id)->effect_delay = 0;

        ai->ai_state = rr_ai_state_attacking;
        ai->ticks_until_next_action = 10;
        break;
    }
    default:
        break;
    }
}

void tick_ai_lanternfly(EntityIdx entity, struct rr_simulation *simulation)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);

    if (should_aggro(simulation, ai))
        ai->ai_state = rr_ai_state_attacking;
    physical->knockback_scale = 1;

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
        tick_idle(entity, simulation);
        break;
    case rr_ai_state_idle_moving:
        tick_idle_move_default(entity, simulation);
        break;
    case rr_ai_state_attacking:
    {
        physical->knockback_scale = -5;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        rr_component_physical_set_angle(physical, rr_vector_theta(&delta));
        if (ai->ticks_until_next_action == 1)
        {
            rr_vector_from_polar(&delta, RR_PLAYER_SPEED * 20, physical->angle);
            rr_vector_add(&physical->acceleration, &delta);
        }
        if (ai->ticks_until_next_action == 0)
        {
            ai->ticks_until_next_action = 2;

            rr_vector_from_polar(&delta, RR_PLAYER_SPEED * -19, physical->angle);
            rr_vector_add(&physical->acceleration, &delta);
        }
        break;
    }
    default:
        break;
    }
}

void tick_ai_pectinodon(EntityIdx entity,
                                      struct rr_simulation *simulation)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);

    if (should_aggro(simulation, ai))
    {
        ai->ai_state = rr_ai_state_attacking;
        ai->ticks_until_next_action = -1;
    }

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
        tick_idle(entity, simulation);
        break;

    case rr_ai_state_idle_moving:
        tick_idle_move_default(entity, simulation);
        break;
    case rr_ai_state_waiting_to_attack:
    {
        if (ai->ticks_until_next_action == 0)
        {
            ai->ai_state = rr_ai_state_attacking;
            ai->ticks_until_next_action = 2;
        }

        if (ai->target_entity == RR_NULL_ENTITY)
        {
            ai->ai_state = rr_ai_state_idle_moving;
            ai->ticks_until_next_action = 25;
            break;
        }

        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        float dist = rr_vector_get_magnitude(&delta) - physical->radius - physical2->radius;
        rr_component_physical_set_angle(physical, rr_vector_theta(&delta));
        if (dist > 300)
        {
            rr_vector_from_polar(&physical->acceleration, RR_PLAYER_SPEED * 0.9, physical->angle);
        }
        else if (dist < 200)
        {
            rr_vector_from_polar(&physical->acceleration, RR_PLAYER_SPEED * 0.75, M_PI + physical->angle);
            ++ai->ticks_until_next_action;
        }
        break;
    }
    case rr_ai_state_attacking:
    {
        struct rr_component_mob *mob =
            rr_simulation_get_mob(simulation, entity);
        // spawn a stick
        EntityIdx petal_id = rr_simulation_alloc_petal(
            simulation, physical->arena, physical->x, physical->y,
            rr_petal_id_stick, mob->rarity, mob->parent_id);
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, petal_id);
        struct rr_component_health *health =
            rr_simulation_get_health(simulation, petal_id);
        rr_component_physical_set_angle(physical2, rr_frand() * 2 * M_PI);
        rr_component_physical_set_radius(
            physical2, 10 * RR_MOB_RARITY_SCALING[mob->rarity].radius);
        physical2->friction = (rr_simulation_get_mob(simulation, entity)->rarity >= rr_rarity_id_mythic) ? 0.87f : 0.8f;
        physical2->mass = 10 * (mob->rarity + 1);
        physical2->bearing_angle = physical->angle;
        rr_vector_from_polar(&physical2->velocity, 150, physical->angle);
        rr_component_petal_set_detached(
            rr_simulation_get_petal(simulation, petal_id), 1);
        rr_component_health_set_max_health(
            health, 3 * RR_MOB_RARITY_SCALING[mob->rarity].health);
        rr_component_health_set_health(health, health->max_health);

        health->damage = 1 * RR_MOB_RARITY_SCALING[mob->rarity].damage;
        health->secondary_damage = 0.5 * RR_MOB_RARITY_SCALING[mob->rarity].damage;
        rr_simulation_get_petal(simulation, petal_id)->effect_delay = 50;

        ai->ai_state = rr_ai_state_waiting_to_attack;
        ai->ticks_until_next_action = 50;

        break;
    }
    default:
        break;
    }
}

void tick_ai_trol(EntityIdx entity, struct rr_simulation *simulation)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);

    if (should_aggro(simulation, ai))
        ai->ai_state = rr_ai_state_attacking;

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
        tick_idle(entity, simulation);
        break;
    case rr_ai_state_idle_moving:
        tick_idle_move_default(entity, simulation);
        break;
    case rr_ai_state_attacking:
    {
        physical->knockback_scale = 0;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        float dist = rr_vector_get_magnitude(&delta) - physical->radius - physical2->radius;
        float target_angle = rr_vector_theta(&delta);

            rr_component_physical_set_angle(physical, target_angle);
            struct rr_vector accel;
            rr_vector_from_polar(&accel, RR_PLAYER_SPEED * 0.001 * dist + 0.05, physical->angle);
            rr_vector_add(&physical->acceleration, &accel);
    }
    default:
        break;
    }
}
 
void tick_ai_test(EntityIdx entity,
                                struct rr_simulation *simulation)
{
    struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);
        
    if (should_aggro(simulation, ai))
    {
        ai->ai_state = rr_ai_state_attacking;
        ai->ticks_until_next_action = 10;
    }

    switch (ai->ai_state)
    {
    case rr_ai_state_idle:
    {
        struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
        struct rr_component_physical *physical =
            rr_simulation_get_physical(simulation, entity);

        if (ai->ticks_until_next_action == 0)
        {
            ai->ticks_until_next_action = rand() % 99 + 75;
            ai->ai_state = rr_ai_state_idle_moving;
            rr_component_physical_set_angle(
                physical, physical->angle + (rr_frand() - 0.5) * M_PI);
            physical->bearing_angle = physical->angle;
        }
        break;
    }

    case rr_ai_state_idle_moving:
    {
        struct rr_component_ai *ai = rr_simulation_get_ai(simulation, entity);
        struct rr_component_physical *physical =
            rr_simulation_get_physical(simulation, entity);
        if (ai->ticks_until_next_action == 0)
        {
            ai->ticks_until_next_action = 1.2 + rr_frand() * 3.7;
            ai->ai_state = rr_ai_state_idle;
        }
        struct rr_vector accel;
        rr_vector_from_polar(&accel, 2.0f, physical->angle);
        rr_vector_add(&physical->acceleration, &accel);
        break;
    }
    case rr_ai_state_attacking:
    {
        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        struct rr_vector delta = {physical2->x, physical2->y};
        struct rr_vector target_pos = {physical->x, physical->y};
        rr_vector_sub(&delta, &target_pos);
        // struct rr_vector prediction = predict(delta, physical2->velocity, 4);
        float target_angle = rr_vector_theta(&delta);

        rr_component_physical_set_angle(physical, target_angle);

        rr_vector_from_polar(&accel, RR_PLAYER_SPEED * 1.45, physical->angle);
        rr_vector_add(&physical->acceleration, &accel);
        if (ai->ticks_until_next_action == 0)
        {
        ai->ticks_until_next_action = 10;
        if (rr_vector_magnitude_cmp(&delta, 750) == -1)
            ai->ai_state = rr_ai_state_charging;
        }
        break;
    }
    case rr_ai_state_charging:
    {
        struct rr_vector accel;
        struct rr_component_physical *physical2 =
            rr_simulation_get_physical(simulation, ai->target_entity);

        rr_vector_from_polar(&accel, RR_PLAYER_SPEED * 6, physical->angle);
        rr_vector_add(&physical->acceleration, &accel);
        if (ai->ticks_until_next_action == 0)
        {
            ai->ticks_until_next_action = 10;
            ai->ai_state = rr_ai_state_attacking;
        }
        break;
    }
    default:
        break;
    }
}
