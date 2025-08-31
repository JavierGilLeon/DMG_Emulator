#include "rotates.h"
#include "cpu.h"


// Rotate Left Circular (Accumulator)
void RLCA(void){
    byte bit = (cpu.AF.High >> 7) & 1;
    cpu.AF.High = ((cpu.AF.High << 1) | bit);

    // Reset Z, N & H flags
    cpu.AF.Low &= ~(Z_FLAG | N_FLAG | H_FLAG);

    // Update C flag
    bit ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);
}

// Rotate Left (Accumulator)
void RLA(void){
    byte bit = (cpu.AF.High >> 7) & 1;
    byte carry = (cpu.AF.Low & C_FLAG) ? 1 : 0;

    cpu.AF.High = ((cpu.AF.High << 1) | carry);

    // Reset Z, N & H flags
    cpu.AF.Low &= ~(Z_FLAG | N_FLAG | H_FLAG);

    // Update C flag
    bit ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);
}

// Rotate Right Circular (Accumulator)
void RRCA(void){
    byte bit = cpu.AF.High & 1;
    cpu.AF.High = (((cpu.AF.High >> 1) & 0x7F) | (bit << 7));  // 0x7F = 0111 1111b

    // Reset Z, N & H flags
    cpu.AF.Low &= ~(Z_FLAG | N_FLAG | H_FLAG);

    // Update C flag
    bit ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);
}

// Rotate Right (Accumulator)
void RRA(void){
    byte bit = cpu.AF.High & 1;
    byte carry = (cpu.AF.Low & C_FLAG) ? 1 : 0;

    cpu.AF.High = (((cpu.AF.High >> 1) & 0x7F) | (carry << 7)); // 0x7F = 0111 1111b

    // Reset Z, N & H flags
    cpu.AF.Low &= ~(Z_FLAG | N_FLAG | H_FLAG);

    // Update C flag
    bit ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);
}

