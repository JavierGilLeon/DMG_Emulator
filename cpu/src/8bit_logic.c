#include "8bit_logic.h"
#include "memory.h"
#include "cpu.h"
/*----------------------------------------------------*/
/*---------------- AND reg opcodes -------------------*/
/*----------------------------------------------------*/

void AND_A(void){
    cpu.AF.High &= cpu.AF.High;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Set H flag
    cpu.AF.Low |= H_FLAG;
    // Reset C flag
    cpu.AF.Low &= ~C_FLAG;
}

void AND_B(void){
    cpu.AF.High &= cpu.BC.High;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Set H flag
    cpu.AF.Low |= H_FLAG;
    // Reset C flag
    cpu.AF.Low &= ~C_FLAG;
}

void AND_C(void){
    cpu.AF.High &= cpu.BC.Low;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Set H flag
    cpu.AF.Low |= H_FLAG;
    // Reset C flag
    cpu.AF.Low &= ~C_FLAG;
}

void AND_D(void){
    cpu.AF.High &= cpu.DE.High;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Set H flag
    cpu.AF.Low |= H_FLAG;
    // Reset C flag
    cpu.AF.Low &= ~C_FLAG;
}

void AND_E(void){
    cpu.AF.High &= cpu.DE.Low;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Set H flag
    cpu.AF.Low |= H_FLAG;
    // Reset C flag
    cpu.AF.Low &= ~C_FLAG;
}

void AND_H(void){
    cpu.AF.High &= cpu.HL.High;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Set H flag
    cpu.AF.Low |= H_FLAG;
    // Reset C flag
    cpu.AF.Low &= ~C_FLAG;
}

void AND_L(void){
    cpu.AF.High &= cpu.HL.Low;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Set H flag
    cpu.AF.Low |= H_FLAG;
    // Reset C flag
    cpu.AF.Low &= ~C_FLAG;
}

void AND_HL(void){
    cpu.AF.High &= getDataFrom(cpu.HL.all);

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Set H flag
    cpu.AF.Low |= H_FLAG;
    // Reset C flag
    cpu.AF.Low &= ~C_FLAG;
}

void AND_n(void){
    byte n = getDataFrom(cpu.PC++);
    cpu.AF.High &= n;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Set H flag
    cpu.AF.Low |= H_FLAG;
    // Reset C flag
    cpu.AF.Low &= ~C_FLAG;
}


/*----------------------------------------------------*/
/*---------------- OR reg opcodes --------------------*/
/*----------------------------------------------------*/

void OR_A(void){
    cpu.AF.High |= cpu.AF.High;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Reset H & C flags
    cpu.AF.Low &= ~(H_FLAG | C_FLAG);
}

void OR_B(void){
    cpu.AF.High |= cpu.BC.High;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Reset H & C flags
    cpu.AF.Low &= ~(H_FLAG | C_FLAG);
}

void OR_C(void){
    cpu.AF.High |= cpu.BC.Low;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Reset H & C flags
    cpu.AF.Low &= ~(H_FLAG | C_FLAG);
}

void OR_D(void){
    cpu.AF.High |= cpu.DE.High;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Reset H & C flags
    cpu.AF.Low &= ~(H_FLAG | C_FLAG);
}

void OR_E(void){
    cpu.AF.High |= cpu.DE.Low;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Reset H & C flags
    cpu.AF.Low &= ~(H_FLAG | C_FLAG);
}

void OR_H(void){
    cpu.AF.High |= cpu.HL.High;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Reset H & C flags
    cpu.AF.Low &= ~(H_FLAG | C_FLAG);
}

void OR_L(void){
    cpu.AF.High |= cpu.HL.Low;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Reset H & C flags
    cpu.AF.Low &= ~(H_FLAG | C_FLAG);
}

void OR_HL(void){
    cpu.AF.High |= getDataFrom(cpu.HL.all);

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Reset H & C flags
    cpu.AF.Low &= ~(H_FLAG | C_FLAG);
}

void OR_n(void){
    byte n = getDataFrom(cpu.PC++);
    cpu.AF.High |= n;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Reset H & C flags
    cpu.AF.Low &= ~(H_FLAG | C_FLAG);
}


/*----------------------------------------------------*/
/*---------------- XOR reg opcodes -------------------*/
/*----------------------------------------------------*/

void XOR_A(void){
    cpu.AF.High ^= cpu.AF.High;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N, C & H flags
    cpu.AF.Low &= ~(N_FLAG | C_FLAG | H_FLAG);
}

void XOR_B(void){
    cpu.AF.High ^= cpu.BC.High;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N, C & H flags
    cpu.AF.Low &= ~(N_FLAG | C_FLAG | H_FLAG);
}

void XOR_C(void){
    cpu.AF.High ^= cpu.BC.Low;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N, C & H flags
    cpu.AF.Low &= ~(N_FLAG | C_FLAG | H_FLAG);
}

void XOR_D(void){
    cpu.AF.High ^= cpu.DE.High;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N, C & H flags
    cpu.AF.Low &= ~(N_FLAG | C_FLAG | H_FLAG);
}

void XOR_E(void){
    cpu.AF.High ^= cpu.DE.Low;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N, C & H flags
    cpu.AF.Low &= ~(N_FLAG | C_FLAG | H_FLAG);
}

void XOR_H(void){
    cpu.AF.High ^= cpu.HL.High;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N, C & H flags
    cpu.AF.Low &= ~(N_FLAG | C_FLAG | H_FLAG);
}

void XOR_L(void){
    cpu.AF.High ^= cpu.HL.Low;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N, C & H flags
    cpu.AF.Low &= ~(N_FLAG | C_FLAG | H_FLAG);
}

void XOR_HL(void){
    cpu.AF.High ^= getDataFrom(cpu.HL.all);

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N, C & H flags
    cpu.AF.Low &= ~(N_FLAG | C_FLAG | H_FLAG);
}

void XOR_n(void){
    byte n = getDataFrom(cpu.PC++);
    cpu.AF.High ^= n;

    // Update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N, C & H flags
    cpu.AF.Low &= ~(N_FLAG | C_FLAG | H_FLAG);
}


/*----------------------------------------------------*/
/*---------------- CP reg opcodes --------------------*/
/*----------------------------------------------------*/

void CP_A(void){
    byte data = cpu.AF.High;
    word res = cpu.AF.High - data;
    byte carry = (cpu.AF.High & 0x0F) < (data & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < data) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

}

void CP_B(void){
    byte data = cpu.BC.High;
    word res = cpu.AF.High - data;
    byte carry = (cpu.AF.High & 0x0F) < (data & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < data) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

}

void CP_C(void){
    byte data = cpu.BC.Low;
    word res = cpu.AF.High - data;
    byte carry = (cpu.AF.High & 0x0F) < (data & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < data) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

}

void CP_D(void){
    byte data = cpu.DE.High;
    word res = cpu.AF.High - data;
    byte carry = (cpu.AF.High & 0x0F) < (data & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < data) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

}

void CP_E(void){
    byte data = cpu.DE.Low;
    word res = cpu.AF.High - data;
    byte carry = (cpu.AF.High & 0x0F) < (data & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < data) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

}

void CP_H(void){
    byte data = cpu.HL.High;
    word res = cpu.AF.High - data;
    byte carry = (cpu.AF.High & 0x0F) < (data & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < data) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

}

void CP_L(void){
    byte data = cpu.HL.Low;
    word res = cpu.AF.High - data;
    byte carry = (cpu.AF.High & 0x0F) < (data & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < data) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

}

void CP_HL(void){
    byte data = getDataFrom(cpu.HL.all);
    word res = cpu.AF.High - data;
    byte carry = (cpu.AF.High & 0x0F) < (data & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < data) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

}

void CP_n(void){
    byte data = getDataFrom(cpu.PC++);
    word res = cpu.AF.High - data;
    byte carry = (cpu.AF.High & 0x0F) < (data & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < data) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

}


/*----------------------------------------------------*/
/*---------------- the rest opcodes ------------------*/
/*----------------------------------------------------*/

void CPL(void){
    cpu.AF.High = ~cpu.AF.High;

    // Set N & H flags
    cpu.AF.Low |= (N_FLAG | H_FLAG) ;
}

void SCF(void){
    // Set C flag
    cpu.AF.Low |= C_FLAG;
    // Reset N & H flags
    cpu.AF.Low &= ~(N_FLAG | H_FLAG);
}

void CCF(void){
    // Flip C flag
    cpu.AF.Low ^= C_FLAG;
    // Reset N & H flags
    cpu.AF.Low &= ~(N_FLAG | H_FLAG);
}

void DAA(void){
    byte adj = 0;

    if((cpu.AF.Low & N_FLAG))  // If N flag is set 
    {
        (cpu.AF.Low & H_FLAG) ? (adj += 0x06) : adj;
        (cpu.AF.Low & C_FLAG) ? (adj += 0x60) : adj;
        cpu.AF.High -= adj;
    }

    else  // If N flag is not set
    {
        ((cpu.AF.Low & H_FLAG) || ((cpu.AF.High & 0x0F) > 0x09)) ? (adj+= 0x06) : adj;
        if((cpu.AF.Low & C_FLAG) || (cpu.AF.High > 0x99))
        {
            adj += 0x60;
            cpu.AF.Low |= C_FLAG;
        }

        cpu.AF.High += adj;
    }
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    cpu.AF.Low &= ~H_FLAG;
}

