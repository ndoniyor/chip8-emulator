#include "chip8.h"
#include <cstring>
#include <iostream>
chip8::chip8(){

}
void chip8::initialize(){
    PC          = 0x200;
    opcode      = 0;
    I           = 0;
    SP          = 0;
    delay_timer = 0;
    sound_timer = 0;
    std::memset(memory, 0, 4096);
    std::memset(stack, 0, 16);
    std::memset(R,0,16);
    std::memset(screen,0,2048);

    //load fontset
    /*for(int i = 0; i < 80; ++i){
        memory[i] = chip8_fontset[i];
    }*/
}
void chip8::loadMemory(){
    //for(int i = 0; i< bufferSize; ++i)
    //    memory[i + 512] = buffer[i];
    memory[PC] = 00;
    memory[PC+1] = 00;
}

void chip8::emulateCycle(){
    opcode = memory[PC] << 8 | memory[PC+1];
    switch(opcode & 0xF000){
        case 0x0000:
            printf("case 1");
        case 0xA000:
            I = opcode & 0x0FFF;
            PC+=2;
            break;
        default:
            std::cout << ("Unknown opcode: 0x%X\n", opcode);
    }
}