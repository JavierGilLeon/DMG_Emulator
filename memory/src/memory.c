#include "memory.h"
#include<stdio.h>
#include<stdlib.h>

byte memory[MEM_SIZE];

void InitMem(void){
    printf("[MEM_INIT] Initializing Memory...\n");
    for(int i = 0; i < MEM_SIZE; i++)
        memory[i] = 0x00;
    printf("\n");
}

byte getDataFrom(word ADDR){

    if(ADDR < 0 || ADDR > 0xFFFF){
        printf("[MEM_ERROR] ADDR out of boundary");
        exit(1);
    }

    if(ADDR > 0xE000 && ADDR < 0xFDFF)
        return memory[ADDR - 0x2000];

    return memory[ADDR];
}


void writeDataTo(word ADDR, byte REG){

    if(ADDR < 0 || ADDR > 0xFFFF){
        printf("[MEM_ERROR] ADDR out of boundary");
        exit(1);
    }

    memory[ADDR] = REG;

    if(ADDR > 0xE000 && ADDR < 0xFDFF)
         memory[ADDR - 0x2000] = REG;


}
