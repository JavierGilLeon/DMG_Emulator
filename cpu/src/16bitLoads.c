#include "cpu.h"
#include "memory.h"

/*----------------------------------------------------*/
/*---------------- reg <- num opcodes ----------------*/
/*----------------------------------------------------*/

void LD_BC_nn(void){
    byte lsb = getDataFrom(cpu.PC++);
    byte msb = getDataFrom(cpu.PC++);
    cpu.BC.all = (msb << 8) | lsb;
}

void LD_DE_nn(void){
    byte lsb = getDataFrom(cpu.PC++);
    byte msb = getDataFrom(cpu.PC++);
    cpu.DE.all = (msb << 8) | lsb;
}

void LD_HL_nn(void){
    byte lsb = getDataFrom(cpu.PC++);
    byte msb = getDataFrom(cpu.PC++);
    cpu.HL.all = (msb << 8) | lsb;
}

/*----------------------------------------------------*/
/*---------------- POP reg opcodes ------------------*/
/*----------------------------------------------------*/

void POP_BC(void){
    byte lsb = getDataFrom(cpu.SP++);
    byte msb = getDataFrom(cpu.SP++);
   cpu.BC.all = (msb << 8) | lsb;
}

void POP_DE(void){
    byte lsb = getDataFrom(cpu.SP++);
    byte msb = getDataFrom(cpu.SP++);
   cpu.DE.all = (msb << 8) | lsb;
}

void POP_HL(void){
    byte lsb = getDataFrom(cpu.SP++);
    byte msb = getDataFrom(cpu.SP++);
   cpu.HL.all = (msb << 8) | lsb;
}

void POP_AF(void){
    byte lsb = getDataFrom(cpu.SP++);
    byte msb = getDataFrom(cpu.SP++);
    cpu.AF.all = (msb << 8) | (lsb & 0xF0);
}

/*----------------------------------------------------*/
/*---------------- PUSH reg opcodes ------------------*/
/*----------------------------------------------------*/

void PUSH_BC(void){
    writeDataTo(--cpu.SP,cpu.BC.High);
    writeDataTo(--cpu.SP,cpu.BC.Low);
}

void PUSH_DE(void){
    writeDataTo(--cpu.SP,cpu.DE.High);
    writeDataTo(--cpu.SP,cpu.DE.Low);
}

void PUSH_HL(void){
    writeDataTo(--cpu.SP,cpu.HL.High);
    writeDataTo(--cpu.SP,cpu.HL.Low);
}

void PUSH_AF(void){
    writeDataTo(--cpu.SP,cpu.AF.High);
    writeDataTo(--cpu.SP,cpu.AF.Low);
}

/*----------------------------------------------------*/
/*---------------- other opcodes ---------------------*/
/*----------------------------------------------------*/

void LD_nn_SP(void){
    byte lsb = getDataFrom(cpu.PC++);
    byte msb = getDataFrom(cpu.PC++);
    word ADDR = (msb << 8) | lsb;

    writeDataTo(ADDR,cpu.SP & 0xFF);
    writeDataTo(ADDR+1,(cpu.SP >> 8) & 0xFF);
}

void LD_HL_SPe(void){
    signed_byte e = getDataFrom(cpu.PC++);
    word result = cpu.SP + e;
    cpu.HL.all = result;

    // Reset flags Z & N
    cpu.AF.Low &= ~(Z_FLAG | N_FLAG);
    // calculate H flag
    ((cpu.SP & 0x0F) + (e & 0x0F)) > 0x0F ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // calculate C flag
    ((cpu.SP & 0xFF) + (e & 0xFF)) > 0xFF ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);
}

void LD_SP_HL(void){
    cpu.SP = cpu.HL.all;
}

