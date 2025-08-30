#include "memory.h"
#include <stdio.h>
#include <stdlib.h>


byte getDataFrom(word ADDR){

    if(ADDR < 0 || ADDR > 0xFFFF){
        printf("[ERROR] ADDR out of boundary");
        exit(1);
    }

    if(ADDR > 0xE000 && ADDR < 0xFDFF)
        return memory[ADDR - 0x2000];

    return memory[ADDR];
}


void writeDataTo(word ADDR, byte REG){

    if(ADDR < 0 || ADDR > 0xFFFF){
        printf("[ERROR] ADDR out of boundary");
        exit(1);
    }

    memory[ADDR] = REG;

    if(ADDR > 0xE000 && ADDR < 0xFDFF)
         memory[ADDR - 0x2000] = REG;


}
