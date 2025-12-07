#include "chip8memory.h"
#include <assert.h>

// TODO - come back and change this from an assertion to maybe something that has a boolean check
// and returns some feedback to the user 
static void chip8_is_memory_in_bounds(int index){
    assert(index >= 0 && index < CHIP8_MEMORY_SIZE );
}

void chip8_memory_set(struct chip8_memory* memory, int index, unsigned char value){

    // Simple assert library, will throw us out if bad
    chip8_is_memory_in_bounds(index);

    // The variable has the array inside, this is how we invoke it
    memory->memory[index] = value;
}


unsigned char chip8_memory_get(struct chip8_memory* memory, int index){

    chip8_is_memory_in_bounds(index);

    return memory->memory[index];
}

