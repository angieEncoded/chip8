 
 // Original virutal map for demonstration
// const char keyboard_map[CHIP8_TOTAL_KEYS] = {
//     0x00, 0x01, 0x02, 0x03, 
//     0x04, 0x05, 0x06, 0x07,
//     0x08, 0x09, 0x0A, 0x0B, 
//     0x0C, 0x0D, 0x0E, 0x0F
// };

 
 // printf("%x\n", chip8_keyboard_map(keyboard_map, 0xFF));

    // testing the keyboard
    // chip8_keyboard_down(&chip8.keyboard, 0x0f);
    // bool is_down = chip8_keyboard_is_down(&chip8.keyboard, 0x0f);
    // printf("%i\n", (int)is_down);

    // chip8_keyboard_up(&chip8.keyboard, 0x0f);
    // is_down = chip8_keyboard_is_down(&chip8.keyboard, 0x0f);
    // printf("%i\n", (int)is_down);


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


     // 0 0 0 is black
        // SDL_SetRenderDrawColor(
        //     renderer, // renderer
        //     0,  // red color
        //     0,  // green color
        //     0,  // blue color
        //     0   // Alpha channel
        // );

        // // paint over the entire screen with the color black
        // SDL_RenderClear(renderer);

        // // change the draw color
        // SDL_SetRenderDrawColor(
        //     renderer, // renderer
        //     255,  // red color
        //     255,  // green color
        //     255,  // blue color
        //     0   // Alpha channel
        // );


        
                // this will draw a simple box on the screen
                // SDL_RenderDrawRect(renderer, &r); //draw the rectangle, give it the address of the rectangle
                
                // This will fill the rectangle
               // SDL_RenderFillRect(renderer, &r); //draw the rectangle, give it the address of the rectangle