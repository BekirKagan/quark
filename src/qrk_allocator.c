/*
 *   qrk_allocator.c - Custom allocator interface and implementations written in C.
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

#include <quark/qrk_allocator.h>
#include <stdlib.h>

void* qrk_alloc(usize size) {
    return malloc(size);
}

void* qrk_resize(void* ptr, usize size) {
    return realloc(ptr, size);
}

void qrk_free(void* ptr) {
    free(ptr);
}
