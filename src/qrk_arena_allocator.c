/*
 *   qrk_arena_allocator.c - Custom allocator interface and implementations written in C.
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

#include <quark/qrk_arena_allocator.h>
#include <string.h>

QRK_Allocator qrk_arena_create(QRK_ArenaAllocator* arena) {
    return (QRK_Allocator){
        .context = arena,
        .alloc = qrk_arena_alloc,
        .resize = NULL,
        .remap = NULL,
        .free = NULL,
    };
}

void qrk_arena_init(QRK_ArenaAllocator* arena, u8* buffer, usize buffer_size, usize align) {
    arena->buffer = buffer;
    arena->buffer_size = buffer_size;
    arena->prev_offset = 0;
    arena->curr_offset = 0;
    arena->align = align;
}

void qrk_arena_deinit(QRK_ArenaAllocator* arena) {
    arena->prev_offset = 0;
    arena->curr_offset = 0;
    qrk_free(arena->buffer);
}

void qrk_arena_reset(QRK_ArenaAllocator* arena) {
    arena->prev_offset = 0;
    arena->curr_offset = 0;
}

static uptr qrk_align(uptr ptr, usize align) {
    if ((align & align - 1) != 0) {
        return -1;
    }

    uptr p = ptr;
    uptr a = (uptr)align;
    uptr padding = p & (align - 1);

    if (padding != 0) {
        p += a - padding;
    }

    return p;
}

void* qrk_arena_alloc(void* arena, usize size) {
    QRK_ArenaAllocator* a = (QRK_ArenaAllocator*)arena;
    if (a == NULL) {
        return NULL;
    }

    uptr curr_ptr = (uptr)a->buffer + (uptr)a->curr_offset;
    uptr offset = qrk_align(curr_ptr, a->align);
    offset -= (uptr)a->buffer;

    if (offset + size > a->buffer_size) {
        return NULL;
    }

    void* ptr = &a->buffer[offset];
    a->prev_offset = offset;
    a->curr_offset = offset + size;
    memset(ptr, 0, size);
    return ptr;
}
