#include <stdio.h>
#include "SDL2/SDL.h"
#include "chip8.h" // include this one, the config will cascade from it

int main(int argc, char **argv){

    struct chip8 chip8;
    
    // Testing the chip8 stack is functional
    // chip8.registers.stack_pointer = 0; 
    // chip8_stack_push(&chip8, 0xff);
    // chip8_stack_push(&chip8, 0xaa);
    // printf("%x\n", chip8_stack_pop(&chip8));
    // printf("%x\n", chip8_stack_pop(&chip8));
    /*
        Chip 8 test responses
        josie@legion2025 MINGW64 ~/Desktop/Chip8 (main)
        $ ./bin/main.exe 
        aa
        ff
    */



    //chip8.registers.V[0x0f] = 50; // Example of setting something in one of the registers
    // chip8_memory_set(&chip8.memory, 0x400, 'z');
    // printf("%c\n", chip8_memory_get(&chip8.memory, 50));

    // Invoke the entirety of the SDL library
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow(
        EMULATOR_WINDOW_TITLE, // Window name
        SDL_WINDOWPOS_UNDEFINED, // X position
        SDL_WINDOWPOS_UNDEFINED, // Y Position
        CHIP8_WIDTH * CHIP8_WINDOW_MULTIPLIER, // Width
        CHIP8_HEIGHT * CHIP8_WINDOW_MULTIPLIER, // Height
        SDL_WINDOW_SHOWN // Flags, show the window
    );

    // renderer, used for drawing pictures to the screen
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, // Expects a window
        -1,     // Index
        SDL_TEXTUREACCESS_TARGET // Flags
    );

    while(1){

        SDL_Event event;

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                goto out;
            }
        }

        // 0 0 0 is black
        SDL_SetRenderDrawColor(
            renderer, // renderer
            0,  // red color
            0,  // green color
            0,  // blue color
            0   // Alpha channel
        );

        // paint over the entire screen with the color black
        SDL_RenderClear(renderer);

        // change the draw color
        SDL_SetRenderDrawColor(
            renderer, // renderer
            255,  // red color
            255,  // green color
            255,  // blue color
            0   // Alpha channel
        );

        // Now we want a white rectangle
        SDL_Rect r;
        r.x = 0;
        r.y = 0;
        r.w = 40;
        r.h = 40;

        // this will draw a simple box on the screen
        // SDL_RenderDrawRect(renderer, &r); //draw the rectangle, give it the address of the rectangle
        
        // This will fill the rectangle
        SDL_RenderFillRect(renderer, &r); //draw the rectangle, give it the address of the rectangle
        SDL_RenderPresent(renderer);

    }



// out label
out:
    // clean up after ourselves
    SDL_DestroyWindow(window);

    return 0;
}