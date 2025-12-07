#ifndef __CHIP8REGISTERS__H__
#define __CHIP8REGISTERS__H__
#include "config.h"
// NOTE: There will not be any functions that manage these so there is no implementation file


/*
From http://devernay.free.fr/hacks/chip8/C8TECH10.HTM
Chip-8 has 16 general purpose 8-bit registers, usually referred to as Vx, where x is a hexadecimal digit (0 through F). 
There is also a 16-bit register called I. This register is generally used to store memory addresses, so only the lowest 
(rightmost) 12 bits are usually used.

The VF register should not be used by any program, as it is used as a flag by some instructions. See section 3.0, Instructions for details.

Chip-8 also has two special purpose 8-bit registers, for the delay and sound timers. When these registers are non-zero, they are automatically 
decremented at a rate of 60Hz. See the section 2.5, Timers & Sound, for more information on these.

There are also some "pseudo-registers" which are not accessable from Chip-8 programs. The program counter (PC) should be 16-bit, and is used 
to store the currently executing address. The stack pointer (SP) can be 8-bit, it is used to point to the topmost level of the stack.

The stack is an array of 16 16-bit values, used to store the address that the interpreter shoud return to when finished with a subroutine. 
Chip-8 allows for up to 16 levels of nested subroutines.
*/

struct chip8_registers {
    unsigned char V[CHIP8_TOTAL_REGISTERS]; //Chip-8 has 16 general purpose 8-bit registers
    unsigned short I; //There is also a 16-bit register called I.
    unsigned char delay_timer; //special purpose 8-bit registers
    unsigned char sound_timer; //special purpose 8-bit registers
    unsigned short program_counter; // 16-bit store the currently executing address
    unsigned char stack_pointer; //  8-bit, it is used to point to the topmost level of the stack
};


#endif  //!__CHIP8REGISTERS__H__