#include <stdio.h>
#include "SDL2/SDL.h"
#include "chip8.h" // include this one, the config will cascade from it
#include "chip8keyboard.h"
#include <stdbool.h>

const char keyboard_map[CHIP8_TOTAL_KEYS] = {
    SDLK_0, SDLK_1, SDLK_2, SDLK_3, 
    SDLK_4, SDLK_5, SDLK_6, SDLK_7,
    SDLK_8, SDLK_9, SDLK_a, SDLK_b, 
    SDLK_c, SDLK_d, SDLK_e, SDLK_f
};

int main(int argc, char **argv){

    struct chip8 chip8;
    
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
            
            switch(event.type){

                case SDL_QUIT:
                    goto out;
                break;

                case SDL_KEYDOWN:
                {
                    char key = event.key.keysym.sym;
                    int vkey = chip8_keyboard_map(keyboard_map, key);
                    // printf("Key is down %x\n", vkey);
                    if(vkey != -1){
                        chip8_keyboard_down(&chip8.keyboard, vkey);
                    }

                }
                break;
                    
                case SDL_KEYUP:  
                {
                    char key = event.key.keysym.sym;
                    int vkey = chip8_keyboard_map(keyboard_map, key);
                    // printf("Key is down %x\n", vkey);
                    if(vkey != -1){
                        chip8_keyboard_up(&chip8.keyboard, vkey);
                    }

                }
                break;
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