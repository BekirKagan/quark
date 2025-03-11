/*
 *   demo.c Custom allocator interface and implementations written in C.
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
#include <stdio.h>

int main(void) {
    u8 arena_buffer[256] = {0};

    QRK_ArenaAllocator arena = {0};
    QRK_Allocator allocator = qrk_arena_create(&arena);
    qrk_arena_init(&arena, arena_buffer, 256, QRK_ARENA_ALIGNMENT);

    i32* num = allocator.alloc(&arena, sizeof(i32));
    *num = 5;
    printf("%d\n", *num);

    qrk_arena_reset(&arena);
    return 0;
}
