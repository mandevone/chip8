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

#ifndef CPU_H_
#define CPU_H_

#include "types.h"

#define MEMSIZ 4096 // How much memory can handle the CHIP-8

/**
 * Main data structure for holding information and state about processor.
 * Memory, stack, and register set is all defined here.
 */
struct machine_t
{
    byte mem[MEMSIZ];         // Memory is allocated as a buffer
    address pc;                // Program Counter

    address stack[16];          // Stack can hold 16 16-bit values
    char sp;                    // Stack Pointer: points to next free cell

    byte v[16];              // 16 general purpose registers
    address i;                 // Special I register
    byte dt, st;             // Timers

    char screen[2048];          // Screen bitmap
    char wait_key;              // Key the CHIP-8 is idle waiting for.
};

void init_machine(struct machine_t*);

void step_machine(struct machine_t*);

#endif // CPU_H_
