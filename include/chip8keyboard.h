#ifndef __CHIP8KEYBOARD__H__
#define __CHIP8KEYBOARD__H__
#include <stdbool.h>
#include "config.h"

/*
The computers which originally used the Chip-8 Language had a 16-key hexadecimal keypad with the following layout:

1	2	3	C
4	5	6	D
7	8	9	E
A	0	B	F

This layout must be mapped into various other configurations to fit the keyboards of today's platforms.
*/

struct chip8_keyboard{
    bool keyboard[CHIP8_TOTAL_KEYS];
};

int chip8_keyboard_map(const char* map, char key); // take in the key and return from the map
void chip8_keyboard_down(struct chip8_keyboard* keyboard, int key);
void chip8_keyboard_up(struct chip8_keyboard* keyboard, int key);
bool chip8_keyboard_is_down(struct chip8_keyboard* keyboard, int key);



#endif  //!__CHIP8KEYBOARD__H__