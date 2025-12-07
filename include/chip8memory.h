#ifndef CHIP8MEMORY_H
#define CHIP8MEMORY_H
#include "config.h"

struct chip8_memory{
    unsigned char memory[CHIP8_MEMORY_SIZE];
};

// Getter and setter prototypes
// need to make sure we pass in the location of the memory we are going to manipulate
void chip8_memory_set(struct chip8_memory* memory, int index, unsigned char value);
unsigned char chip8_memory_get(struct chip8_memory* memory, int index);



#endif