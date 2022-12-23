#ifndef CHIP8_H
#define CHIP8_H

class chip8{
    public:
        chip8();
        void initialize();
        void loadMemory();
        void emulateCycle();
    private:
        unsigned short opcode;
        unsigned char memory[4096];
        unsigned char R[16];
        unsigned short I;
        unsigned short PC;
        unsigned short stack[16];
        unsigned short SP;
        unsigned char screen[2048];
        unsigned char delay_timer;
        unsigned char sound_timer;
        unsigned char key_pad[16];
};

#endif
