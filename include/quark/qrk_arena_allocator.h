/*
 *   qrk_arena_allocator.h - Custom allocator interface and implementations written in C.
 *   Copyright (C) 2025 Bekir Kağan Karaahmetoğlu <kagankaraahmetoglu@hotmail.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "qrk_allocator.h"

#ifndef QRK_ARENA_ALIGNMENT
#define QRK_ARENA_ALIGNMENT sizeof(void*)
#endif

typedef struct qrk_ArenaAllocator {
    u8* buffer;
    usize buffer_size;
    usize prev_offset;
    usize curr_offset;
    usize align;
} QRK_ArenaAllocator;

QRK_Allocator qrk_arena_create(QRK_ArenaAllocator* arena);
void qrk_arena_init(QRK_ArenaAllocator* arena, u8* buffer, usize buffer_size, usize align);
void qrk_arena_deinit(QRK_ArenaAllocator* arena);
void qrk_arena_reset(QRK_ArenaAllocator* arena);
void* qrk_arena_alloc(void* arena, usize size);

#ifdef __cplusplus
}
#endif
