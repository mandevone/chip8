/*
 * chip8 is a CHIP-8 emulator done in C
 * Copyright (C) 2015 Dani Rodríguez <danirod@outlook.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <SDL2/SDL_types.h>

extern char hexcodes[];

/**
 * Expand a machine_t bitmap into a SDL 32-bit surface bitmap. This function
 * will work provided some requirements are meet. Both arrays must be 2048
 * positions long. Input array must be a char array where each position is
 * either 0 or 1.
 *
 * Output array will be expanded in a format that is compatible with SDL
 * surfaces. Each 0 on input array will be converted to a 0 on output array,
 * which will result on no pixel being drawn on that position. Each 1 on
 * input array will be converted to a -1 on output array, which being unsigned
 * will result on every single bit of that position being 1 and thus
 * plotting a white pixel.
 *
 * @param from input array where the struct machine_t bitmap is from.
 * @param to output array where the pixels will be blitted.
 */
void expand_screen(char*, Uint32*);

#endif // DISPLAY_H_
