#ifndef __CHIP8SCREEN__H__
#define __CHIP8SCREEN__H__
#include "config.h"
#include <stdbool.h>

struct chip8_screen {
    bool pixels[CHIP8_HEIGHT][CHIP8_WIDTH];
};

void chip8_screen_set(struct chip8_screen* screen, int x, int y);
bool chip8_screen_is_set(struct chip8_screen* screen, int x, int y);



#endif  //!__CHIP8SCREEN__H__