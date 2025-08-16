#include "InstructionSet.h"
#include "cpu.h"



void (*ExecInstr[512])(void);


void InitInstr(void){
    ExecInstr[0x00] = NOP;
    ExecInstr[0x01];
}


void NOP(void){
    // To complete
}

// LOAD FUNCTIONS
void LD_XY();



