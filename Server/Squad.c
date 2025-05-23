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

#include <Server/Squad.h>

#include <stdlib.h>
#include <string.h>

#include <Server/Server.h>

void rr_squad_init(struct rr_squad *this, struct rr_server *server, uint8_t pos)
{
    memset(this, 0, sizeof *this);
    this->expose_code = 1;
    for (uint32_t i = 0; i < 6; ++i)
        this->squad_code[i] = (char)(97 + rand() % 26);
    this->squad_code[6] = 0;
    for (uint32_t i = 0; i < RR_MAX_CLIENT_COUNT; ++i)
        rr_bitset_unset(server->clients[i].joined_squad_before, pos);
}

uint8_t rr_squad_has_space(struct rr_squad *this)
{
    return this->member_count < RR_SQUAD_MEMBER_COUNT;
}

void rr_squad_add_client(struct rr_squad *this, struct rr_server_client *client)
{
    for (uint32_t i = 0; i < RR_SQUAD_MEMBER_COUNT; ++i)
    {
        if (this->members[i].in_use)
            continue;
        memset(&this->members[i], 0, sizeof this->members[i]);
        client->squad_pos = i;
        this->members[i].client = client;
        this->member_count += 1;
        this->members[i].in_use = 1;
        this->members[i].is_dev = client->dev;
        this->members[i].level = level_from_xp(client->experience);
        this->members[i].kick_vote_pos = -1;
        return;
    }
}

void rr_squad_remove_client(struct rr_squad *this,
                            struct rr_server_client *client)
{
    struct rr_squad_member *member = &this->members[client->squad_pos];
    if (member->kick_vote_pos != -1)
        this->members[member->kick_vote_pos].kick_vote_count -= 1;
    for (uint8_t i = 0; i < RR_SQUAD_MEMBER_COUNT; ++i)
    {
        member = &this->members[i];
        if (member->in_use && member->kick_vote_pos == client->squad_pos)
            member->kick_vote_pos = -1;
    }
    this->member_count -= 1;
    memset(&this->members[client->squad_pos], 0,
           sizeof(struct rr_squad_member));
    if (this->member_count == 0)
        rr_squad_init(this, client->server, client->squad);
    else if (this->private && this->owner == client->squad_pos)
    {
        uint8_t seed = rand() % this->member_count;
        for (uint8_t i = 0; i < RR_SQUAD_MEMBER_COUNT; ++i)
        {
            member = &this->members[i];
            if (member->in_use && seed-- == 0)
            {
                this->owner = i;
                break;
            }
        }
    }
    client->squad_pos = 0;
    client->in_squad = 0;
}

void rr_client_can_rejoin_squads(struct rr_server *this,
                                 struct rr_server_client *member,
                                 uint8_t chosen)
{
    for (uint8_t i = chosen; i < RR_SQUAD_COUNT; ++i)
    {
        if (this->squads[i].private)
            continue;
        if (this->squads[i].member_count > 0)
            return;
    }

    for (uint8_t i = 0; i < RR_SQUAD_COUNT; ++i)
        if (!this->squads[i].private)
            rr_bitset_unset(member->joined_squad_before, i);
}

uint8_t rr_client_find_squad(struct rr_server *this,
                             struct rr_server_client *member)
{
    for (uint8_t i = 0; i < RR_SQUAD_COUNT; ++i)
        if (rr_squad_has_space(&this->squads[i]) && !this->squads[i].private &&
            !rr_bitset_get(member->joined_squad_before, i))
        {
            rr_client_can_rejoin_squads(this, member, i);
            return i;
        }
    return RR_ERROR_CODE_INVALID_SQUAD;
}

uint8_t rr_client_create_squad(struct rr_server *this,
                               struct rr_server_client *member)
{
    for (uint8_t i = 0; i < RR_SQUAD_COUNT; ++i)
        if (this->squads[i].member_count == 0)
        {
            this->squads[i].private = 1;
            this->squads[i].expose_code = 0;
            this->squads[i].owner = 0;
            for (uint32_t j = 0; j < RR_MAX_CLIENT_COUNT; ++j)
                rr_bitset_unset(this->clients[j].joined_squad_before, i);
            return i;
        }
    return RR_ERROR_CODE_INVALID_SQUAD;
}

uint8_t rr_client_join_squad_with_code(struct rr_server *this,
                                       struct rr_server_client *member,
                                       char *code)
{
    for (uint8_t i = 0; i < RR_SQUAD_COUNT; ++i)
        if (memcmp(this->squads[i].squad_code, code, 6) == 0)
        {
            if (!member->dev && this->squads[i].private &&
                rr_bitset_get(member->joined_squad_before, i))
                return RR_ERROR_CODE_KICKED_FROM_SQUAD;
            if (!rr_squad_has_space(&this->squads[i]))
                return RR_ERROR_CODE_FULL_SQUAD;
            return i;
        }
    return RR_ERROR_CODE_INVALID_SQUAD;
}

uint8_t rr_client_join_squad(struct rr_server *this,
                             struct rr_server_client *member, uint8_t pos)
{
    if (!rr_squad_has_space(&this->squads[pos]))
        return 0;
    rr_squad_add_client(&this->squads[pos], member);
    member->squad = pos;
    member->in_squad = 1;
    if (!this->squads[pos].private)
        rr_bitset_set(member->joined_squad_before, pos);
    return 1;
}

void rr_client_leave_squad(struct rr_server *this,
                           struct rr_server_client *member)
{
    if (!member->in_squad)
        return;
    rr_squad_remove_client(&this->squads[member->squad], member);
    member->squad = 0;
    member->in_squad = 0;
}

struct rr_squad_member *
rr_squad_get_client_slot(struct rr_server *this,
                         struct rr_server_client *member)
{
    if (!member->in_squad)
        return NULL;
    return &this->squads[member->squad].members[member->squad_pos];
}

struct rr_squad *rr_client_get_squad(struct rr_server *this,
                                     struct rr_server_client *member)
{
    if (!member->in_squad)
        return NULL;
    return &this->squads[member->squad];
}