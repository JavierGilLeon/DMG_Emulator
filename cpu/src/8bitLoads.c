#include "cpu.h"
#include "memory.h"

/*----------------------------------------------------*/
/*---------------- reg <- reg opcodes ----------------*/
/*----------------------------------------------------*/

void LD_A_B(void){
    cpu.AF.High = cpu.BC.High;
}

void LD_A_C(void){
    cpu.AF.High = cpu.BC.Low;
}

void LD_A_D(void){
    cpu.AF.High = cpu.DE.High;
}

void LD_A_E(void){
    cpu.AF.High = cpu.DE.Low;
}

void LD_A_H(void){
    cpu.AF.High = cpu.HL.High;
}

void LD_A_L(void){
    cpu.AF.High = cpu.HL.Low;
}


void LD_B_A(void){
    cpu.BC.High = cpu.AF.High;
}

void LD_B_C(void){
    cpu.BC.High = cpu.BC.Low;
}

void LD_B_D(void){
    cpu.BC.High = cpu.DE.High;
}

void LD_B_E(void){
    cpu.BC.High = cpu.DE.Low;
}

void LD_B_H(void){
    cpu.BC.High = cpu.HL.High;
}

void LD_B_L(void){
    cpu.BC.High = cpu.HL.Low;
}


void LD_C_A(void){
    cpu.BC.Low = cpu.AF.High;
}

void LD_C_B(void){
    cpu.BC.Low = cpu.BC.High;
}

void LD_C_D(void){
    cpu.BC.Low = cpu.DE.High;
}

void LD_C_E(void){
    cpu.BC.Low = cpu.DE.Low;
}

void LD_C_H(void){
    cpu.BC.Low = cpu.HL.High;
}

void LD_C_L(void){
    cpu.BC.Low = cpu.HL.Low;
}


void LD_D_A(void){
    cpu.DE.High = cpu.AF.High;
}

void LD_D_B(void){
    cpu.DE.High = cpu.BC.High;
}

void LD_D_C(void){
    cpu.DE.High = cpu.BC.Low;
}

void LD_D_E(void){
    cpu.DE.High = cpu.DE.Low;
}

void LD_D_H(void){
    cpu.DE.High = cpu.HL.High;
}

void LD_D_L(void){
    cpu.DE.High = cpu.HL.Low;
}


void LD_E_A(void){
    cpu.DE.Low = cpu.AF.High;
}

void LD_E_B(void){
    cpu.DE.Low = cpu.BC.High;
}

void LD_E_C(void){
    cpu.DE.Low = cpu.BC.Low;
}

void LD_E_D(void){
    cpu.DE.Low = cpu.DE.High;
}

void LD_E_H(void){
    cpu.DE.Low = cpu.HL.High;
}

void LD_E_L(void){
    cpu.DE.Low = cpu.HL.Low;
}


void LD_H_A(void){
    cpu.HL.High = cpu.AF.High;
}

void LD_H_B(void){
    cpu.HL.High = cpu.BC.High;
}

void LD_H_C(void){
    cpu.HL.High = cpu.BC.Low;
}

void LD_H_D(void){
    cpu.HL.High = cpu.DE.High;
}

void LD_H_E(void){
    cpu.HL.High = cpu.DE.Low;
}

void LD_H_L(void){
    cpu.HL.High = cpu.HL.Low;
}


void LD_L_A(void){
    cpu.HL.Low = cpu.AF.High;
}

void LD_L_B(void){
    cpu.HL.Low = cpu.BC.High;
}

void LD_L_C(void){
    cpu.HL.Low = cpu.BC.Low;
}

void LD_L_D(void){
    cpu.HL.Low = cpu.DE.High;
}

void LD_L_E(void){
    cpu.HL.Low = cpu.DE.Low;
}

void LD_L_H(void){
    cpu.HL.Low = cpu.HL.High;
}


/*----------------------------------------------------*/
/*---------------- reg <- (HL) opcodes ---------------*/
/*----------------------------------------------------*/

void LD_A_HL(void){
    cpu.AF.High = getDataFrom(cpu.HL.all);
}

void LD_B_HL(void){
    cpu.BC.High = getDataFrom(cpu.HL.all);
}

void LD_C_HL(void){
    cpu.BC.Low = getDataFrom(cpu.HL.all);
}

void LD_D_HL(void){
    cpu.DE.High = getDataFrom(cpu.HL.all);
}

void LD_E_HL(void){
    cpu.DE.Low = getDataFrom(cpu.HL.all);
}

void LD_H_HL(void){
    cpu.HL.High = getDataFrom(cpu.HL.all);
}

void LD_L_HL(void){
    cpu.HL.Low = getDataFrom(cpu.HL.all);
}

/*----------------------------------------------------*/
/*---------------- (HL) <- reg opcodes ---------------*/
/*----------------------------------------------------*/

void LD_HL_A(void){
    writeDataTo(cpu.HL.all,cpu.AF.High);
}

void LD_HL_B(void){
    writeDataTo(cpu.HL.all,cpu.BC.High);
}

void LD_HL_C(void){
    writeDataTo(cpu.HL.all,cpu.BC.Low);
}

void LD_HL_D(void){
    writeDataTo(cpu.HL.all,cpu.DE.High);
}

void LD_HL_E(void){
    writeDataTo(cpu.HL.all,cpu.DE.Low);
}

void LD_HL_H(void){
    writeDataTo(cpu.HL.all,cpu.HL.High);
}

void LD_HL_L(void){
    writeDataTo(cpu.HL.all,cpu.HL.Low);
}

/*----------------------------------------------------*/
/*---------------- reg <- num opcodes ----------------*/
/*----------------------------------------------------*/

void LD_A_n(void){
    cpu.AF.High = getDataFrom(cpu.PC++);
}

void LD_B_n(void){
    cpu.BC.High = getDataFrom(cpu.PC++);
}

void LD_C_n(void){
    cpu.BC.Low = getDataFrom(cpu.PC++);
}

void LD_D_n(void){
    cpu.DE.High = getDataFrom(cpu.PC++);
}

void LD_E_n(void){
    cpu.DE.Low = getDataFrom(cpu.PC++);
}

void LD_H_n(void){
    cpu.HL.High = getDataFrom(cpu.PC++);
}

void LD_L_n(void){
    cpu.HL.Low = getDataFrom(cpu.PC++);
}

/*----------------------------------------------------*/
/*---------------- The rest of the LD8 opcodes -------*/
/*----------------------------------------------------*/

void LD_BC_A(void){
    writeDataTo(cpu.BC.all, cpu.AF.High);
}

void LD_A_BC(void){
    cpu.AF.High = getDataFrom(cpu.BC.all);
}

void LD_DE_A(void){
    writeDataTo(cpu.DE.all, cpu.AF.High);
}

void LD_A_DE(void){
    cpu.AF.High = getDataFrom(cpu.DE.all);
}

void LD_HLP_A(void){
    writeDataTo(cpu.HL.all++, cpu.AF.High);
}

void LD_A_HLP(void){
    cpu.AF.High = getDataFrom(cpu.HL.all++);
}

void LD_HLM_A(void){
    writeDataTo(cpu.HL.all--, cpu.AF.High);
}

void LD_A_HLM(void){
    cpu.AF.High = getDataFrom(cpu.HL.all--);
}

void LD_HL_n(void){
    byte n = getDataFrom(cpu.PC++);
    writeDataTo(cpu.HL.all,n);
}

void LDH_n_A(void){
    byte n = getDataFrom(cpu.PC++);
    writeDataTo(0xFF00+n, cpu.AF.High);
}

void LDH_C_A(void){
    writeDataTo(0xFF00+cpu.BC.Low,cpu.AF.High);
}

void LD_nn_A(void){
    byte lsb = getDataFrom(cpu.PC++);
    byte msb = getDataFrom(cpu.PC++);
    word ADDR = (msb << 8) | lsb;
    writeDataTo(ADDR,cpu.AF.High);
}

void LDH_A_n(void){
    byte ADDR = 0xFF00 + getDataFrom(cpu.PC++);
    cpu.AF.High = getDataFrom(ADDR);
}

void LDH_A_C(void){
    cpu.AF.High = getDataFrom(0xFF00 + cpu.BC.Low);
}

void LD_A_nn(void){
    byte lsb = getDataFrom(cpu.PC++);
    byte msb = getDataFrom(cpu.PC++);
    word ADDR = (msb << 8)| lsb;
    cpu.AF.High = getDataFrom(ADDR);
}

