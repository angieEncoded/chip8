#ifndef __CHIP8STACK__H__
#define __CHIP8STACK__H__
#include "config.h"

struct chip8; // forward declare the chip8 structure, we can't include the chip8 header file in here

struct chip8_stack {
    unsigned short stack[CHIP8_TOTAL_STACK_DEPTH]; // 16, 16 bit values size of an unsigned short is 2 bytes
};

// push our return addresses to the stack
void chip8_stack_push(struct chip8* chip8, unsigned short value);

// pop our values from the stack
unsigned short chip8_stack_pop(struct chip8* chip8);



#endif  //!__CHIP8STACK__H__