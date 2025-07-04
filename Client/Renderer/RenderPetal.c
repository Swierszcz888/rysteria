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

#include <Client/Renderer/ComponentRender.h>

#include <math.h>

#include <Client/Game.h>
#include <Client/Renderer/Renderer.h>
#include <Client/Simulation.h>

#include <Client/Assets/RenderFunctions.h>

void rr_component_petal_render(EntityIdx entity, struct rr_game *game,
                               struct rr_simulation *simulation)
{
    struct rr_renderer *renderer = game->renderer;
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);
    struct rr_component_petal *petal =
        rr_simulation_get_petal(simulation, entity);
    struct rr_component_health *health =
        rr_simulation_get_health(simulation, entity);
    rr_renderer_set_global_alpha(renderer, 1 - physical->deletion_animation);
    rr_renderer_scale(renderer, 1 + physical->deletion_animation * 0.5);
    if (petal->id == rr_petal_id_uranium && physical->on_title_screen)
    {
        rr_renderer_set_fill(renderer, 0x2063bf2e);
        rr_renderer_begin_path(renderer);
        rr_renderer_arc(renderer, 0, 0,
                        (25 + 10 * (petal->rarity > 1 ? petal->rarity - 1 : 1) *
                            (1 + sinf(physical->animation_timer * 3))) *
                            physical->radius / 15);
        rr_renderer_fill(renderer);
    }
    if (petal->rarity >= rr_rarity_id_exotic)
    {
        struct rr_particle_manager *particle_manager =
            &game->default_particle_manager;
        float exotic_coeff = petal->rarity == rr_rarity_id_exotic ? 0.5 : 1;
        float size_coeff =
            physical->on_title_screen ? physical->radius / 20 : 1;
        float colorful_coeff = petal->id == rr_petal_id_fireball ? 2 : 1;
        float pos_offset = 0;
        if (physical->on_title_screen)
        {
            if (petal->id == rr_petal_id_magnet ||
                petal->id == rr_petal_id_crest ||
                petal->id == rr_petal_id_bubble)
                pos_offset = physical->radius * rr_frand();
        }
        struct rr_simulation_animation *particle =
            rr_particle_alloc(particle_manager, rr_animation_type_default);
        particle->x = physical->lerp_x;
        particle->y = physical->lerp_y;
        if (pos_offset > 0)
        {
            struct rr_vector vector;
            rr_vector_from_polar(&vector, pos_offset, 2 * M_PI * rr_frand());
            particle->x += vector.x;
            particle->y += vector.y;
        }
        rr_vector_from_polar(&particle->velocity,
                             (3 + 2 * rr_frand()) * exotic_coeff * size_coeff,
                             2 * M_PI * rr_frand());
        particle->friction = 0.9;
        particle->size = (3 + 2 * rr_frand()) * exotic_coeff * size_coeff;
        particle->opacity = (0.3 + 0.5 * rr_frand()) *
                                exotic_coeff * colorful_coeff;
        particle->disappearance = physical->on_title_screen ? 4 : 6;
        particle->color = 0xffffffff;
        if (petal->id == rr_petal_id_fireball)
        {
            switch (rand() % 3)
            {
            case 0:
                particle->color = 0xffbc0303;
                break;
            case 1:
                particle->color = 0xffce5d0b;
                break;
            case 2:
                particle->color = 0xffd4cc08;
                break;
            }
        }
        else if (petal->id == rr_petal_id_stick)
        {
            particle->size = (3 + 2 * rr_frand()) * exotic_coeff * size_coeff;
            particle->color = rr_frand() > 0.30 ? 0xffbc0303 : rr_frand() > 0.55 ? 0xffce5d0b : 0xffd4cc08;
        }
        else if (petal->id == rr_petal_id_trol)
        {
            particle->friction = 0.7;
            particle->size = (25 + 50 * rr_frand()) * exotic_coeff * size_coeff;
            particle->opacity = 0.99;
        particle->disappearance = physical->on_title_screen ? 20 : 20;
            particle->color = rr_frand() > 0.25 ? 0xffffffc8 : 0xffffff64;
        }
    }
    if (petal->id == rr_petal_id_meteor)
    {
        float pos_offset = 0;
        struct rr_simulation_animation *particle =
            rr_particle_alloc(&game->foreground_particle_manager,
                              rr_animation_type_default);
        float angle =
            rr_vector_theta(&physical->lerp_velocity) + M_PI - 0.5 + rr_frand();
        float dist = rr_frand() * 50;
        struct rr_vector vector;
        
        if (pos_offset > 0)
        {
            rr_vector_from_polar(&vector, pos_offset, 2 * M_PI * rr_frand());
            particle->x += vector.x;
            particle->y += vector.y;
        }
        particle->friction = 0.9;
        particle->x = physical->lerp_x + cosf(angle) * dist;
        particle->y = physical->lerp_y + sinf(angle) * dist;
        particle->size = (4 + rr_frand() * 2);
        particle->opacity = 0.8;
        particle->disappearance = 6;
        particle->color = 0xffab3423;
    }
    if (petal->id == rr_petal_id_stick)
    {
        struct rr_particle_manager *particle_manager =
            petal->id != rr_petal_id_meteor
                ? &game->default_particle_manager
                : &game->foreground_particle_manager;
        float size_coeff =
            physical->on_title_screen ? physical->radius / 20 : 1;
        float pos_offset = 0;
        struct rr_simulation_animation *particle = 
            rr_particle_alloc(particle_manager, rr_animation_type_default);
        particle->x = physical->lerp_x;
        particle->y = physical->lerp_y;
        if (pos_offset > 0)
        {
            struct rr_vector vector;
            rr_vector_from_polar(&vector, pos_offset, 2 * M_PI * rr_frand());
            particle->x += vector.x;
            particle->y += vector.y;
        }
        float angle = rr_vector_theta(&physical->lerp_velocity) + M_PI - 0.5 + rr_frand();
        float dist = 10;
        rr_vector_from_polar(&particle->velocity, (rr_frand() * 5 + 5), angle);
        particle->x = physical->lerp_x + sinf(physical->angle) * dist;
        particle->y = physical->lerp_y - cosf(physical->angle) * dist;
        particle->friction = 0.7;
        particle->size = (1 + rr_frand() * 5);
        particle->opacity = 0.4;
        particle->disappearance = physical->on_title_screen ? 6 : 10;
        particle->color = rr_frand() > 0.25 ? 0xffab3423 : 0xff999999;
    }
    if (petal->id == rr_petal_id_trol)
    {
        struct rr_particle_manager *particle_manager =
            petal->id != rr_petal_id_meteor
                ? &game->default_particle_manager
                : &game->foreground_particle_manager;
        float size_coeff =
            physical->on_title_screen ? physical->radius / 20 : 1;
        float colorful_coeff = petal->id == rr_petal_id_fireball ||
                               petal->id == rr_petal_id_meteor ? 2 : 1;
        float pos_offset = 0;
        struct rr_simulation_animation *particle =
            rr_particle_alloc(particle_manager, rr_animation_type_default);
        particle->x = physical->lerp_x;
        particle->y = physical->lerp_y;
        if (pos_offset > 0)
        {
            struct rr_vector vector;
            rr_vector_from_polar(&vector, pos_offset, 2 * M_PI * rr_frand());
            particle->x += vector.x;
            particle->y += vector.y;
        }
        rr_vector_from_polar(&particle->velocity,
                             (3 + 2 * rr_frand()) * size_coeff,
                             2 * M_PI * rr_frand());
        particle->friction = 0.95;
        particle->size = (5 + 8 * rr_frand()) * size_coeff;
        particle->opacity = (0.7 + 0.9 * rr_frand());
        particle->disappearance = physical->on_title_screen ? 4 : 6;
        particle->color = rr_frand() > 0.25 ? 0xffffffc8 : 0xffffff64;
    }
    if (game->cache.tint_petals)
        rr_renderer_add_color_filter(renderer, RR_RARITY_COLORS[petal->rarity],
                                     0.4);
    rr_renderer_add_color_filter(renderer, 0xffff0000,
                                 0.5 * health->damage_animation);
    rr_renderer_rotate(renderer, physical->lerp_angle);

    rr_renderer_scale(renderer, physical->radius / 10);
    uint8_t use_cache =
        (health->damage_animation < 0.1 || game->cache.low_performance_mode) &&
        !game->cache.tint_petals;
    if (petal->id != rr_petal_id_peas || petal->detached == 1)
        rr_renderer_draw_petal(renderer, petal->id, petal->rarity, use_cache);
    else
        rr_renderer_draw_static_petal(renderer, petal->id, petal->rarity,
                                      use_cache);
}