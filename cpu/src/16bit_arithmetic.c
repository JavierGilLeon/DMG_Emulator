#include "16bit_arithmetic.h"
#include "cpu.h"
#include "memory.h"
/*----------------------------------------------------*/
/*---------------- INC reg opcodes -------------------*/
/*----------------------------------------------------*/

void INC_BC(void){
    cpu.BC.all++;
}

void INC_DE(void){
    cpu.DE.all++;
}

void INC_HL(void){
    cpu.HL.all++;
}

void INC_SP(void){
    cpu.SP++;
}


/*----------------------------------------------------*/
/*---------------- DEC reg opcodes -------------------*/
/*----------------------------------------------------*/

void DEC_BC(void){
    cpu.BC.all--;
}

void DEC_DE(void){
    cpu.DE.all--;
}

void DEC_HL(void){
    cpu.HL.all--;
}

void DEC_SP(void){
    cpu.SP--;
}


/*----------------------------------------------------*/
/*---------------- ADD HL reg opcodes ----------------*/
/*----------------------------------------------------*/

void ADD_BC(void){
    word res = cpu.HL.all + cpu.BC.all;
    word low_carry = (cpu.HL.all & 0x0FFF) + (cpu.BC.all & 0x0FFF);

    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (low_carry > 0x0FFF) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.HL.all + cpu.BC.all > 0xFFFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.HL.all = res;
}

void ADD_DE(void){
    word res = cpu.HL.all + cpu.DE.all;
    word low_carry = (cpu.HL.all & 0x0FFF) + (cpu.DE.all & 0x0FFF);

    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (low_carry > 0x0FFF) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.HL.all + cpu.DE.all > 0xFFFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.HL.all = res;
}

void ADD_HL(void){
    word res = cpu.HL.all + cpu.HL.all;
    word low_carry = (cpu.HL.all & 0x0FFF) + (cpu.HL.all & 0x0FFF);

    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (low_carry > 0x0FFF) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.HL.all + cpu.HL.all > 0xFFFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.HL.all = res;
}

void ADD_SP(void){
    word res = cpu.HL.all + cpu.SP;
    word low_carry = (cpu.HL.all & 0x0FFF) + (cpu.SP & 0x0FFF);

    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (low_carry > 0x0FFF) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.HL.all + cpu.SP > 0xFFFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.HL.all = res;
}


/*----------------------------------------------------*/
/*---------------- ADD SP+e reg opcodes ----------------*/
/*----------------------------------------------------*/

void ADD_SP_e(void){
    signed_byte e = getDataFrom(cpu.PC++);
    word res = cpu.SP + e;
    word low_carry = (cpu.SP & 0x0F) + (e & 0x0F);
    word carry = (cpu.SP & 0xFF) + (e & 0xFF);

    // Reset N & Z flags
    cpu.AF.Low &= ~(N_FLAG | Z_FLAG);
    // Update H flag
    (low_carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (carry > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);
}

