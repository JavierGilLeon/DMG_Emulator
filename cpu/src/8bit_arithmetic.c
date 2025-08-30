#include "cpu.h"
#include "memory.h"

/*----------------------------------------------------*/
/*---------------- INC reg opcodes -------------------*/
/*----------------------------------------------------*/

void INC_A(void){
    byte carry = cpu.AF.High;
    cpu.AF.High++;

    // update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    ((carry & 0x0F) + 1) > 0x0F ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
}

void INC_B(void){
    byte carry = cpu.BC.High;
    cpu.BC.High++;

    // update Z flag
    cpu.BC.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    ((carry & 0x0F) + 1) > 0x0F ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
}

void INC_C(void){
    byte carry = cpu.BC.Low;
    cpu.BC.Low++;

    // update Z flag
    cpu.BC.Low ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    ((carry & 0x0F) + 1) > 0x0F ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
}

void INC_D(void){
    byte carry = cpu.DE.High;
    cpu.DE.High++;

    // update Z flag
    cpu.DE.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    ((carry & 0x0F) + 1) > 0x0F ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
}

void INC_E(void){
    byte carry = cpu.DE.Low;
    cpu.DE.Low++;

    // update Z flag
    cpu.DE.Low ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    ((carry & 0x0F) + 1) > 0x0F ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
}

void INC_H(void){
    byte carry = cpu.HL.High;
    cpu.HL.High++;

    // update Z flag
    cpu.HL.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    ((carry & 0x0F) + 1) > 0x0F ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
}

void INC_L(void){
    byte carry = cpu.HL.Low;
    cpu.HL.Low++;

    // update Z flag
    cpu.HL.Low ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    ((carry & 0x0F) + 1) > 0x0F ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
}


/*----------------------------------------------------*/
/*---------------- DEC reg opcodes -------------------*/
/*----------------------------------------------------*/

void DEC_A(void){
    byte carry = cpu.AF.High;
    cpu.AF.High--;

    // update Z flag
    cpu.AF.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    (carry & 0x0F) ? (cpu.AF.Low &= ~H_FLAG) : (cpu.AF.Low |= H_FLAG);
}

void DEC_B(void){
    byte carry = cpu.BC.High;
    cpu.BC.High--;

    // update Z flag
    cpu.BC.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    (carry & 0x0F) ? (cpu.AF.Low &= ~H_FLAG) : (cpu.AF.Low |= H_FLAG);
}

void DEC_C(void){
    byte carry = cpu.BC.Low;
    cpu.BC.Low--;

    // update Z flag
    cpu.BC.Low ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    (carry & 0x0F) ? (cpu.AF.Low &= ~H_FLAG) : (cpu.AF.Low |= H_FLAG);
}

void DEC_D(void){
    byte carry = cpu.DE.High;
    cpu.DE.High--;

    // update Z flag
    cpu.DE.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    (carry & 0x0F) ? (cpu.AF.Low &= ~H_FLAG) : (cpu.AF.Low |= H_FLAG);
}

void DEC_E(void){
    byte carry = cpu.DE.Low;
    cpu.DE.Low--;

    // update Z flag
    cpu.DE.Low ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    (carry & 0x0F) ? (cpu.AF.Low &= ~H_FLAG) : (cpu.AF.Low |= H_FLAG);
}

void DEC_H(void){
    byte carry = cpu.HL.High;
    cpu.HL.High--;

    // update Z flag
    cpu.HL.High ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    (carry & 0x0F) ? (cpu.AF.Low &= ~H_FLAG) : (cpu.AF.Low |= H_FLAG);
}

void DEC_L(void){
    byte carry = cpu.HL.Low;
    cpu.HL.Low--;

    // update Z flag
    cpu.HL.Low ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    (carry & 0x0F) ? (cpu.AF.Low &= ~H_FLAG) : (cpu.AF.Low |= H_FLAG);
}


/*----------------------------------------------------*/
/*---------------- ADD reg opcodes -------------------*/
/*----------------------------------------------------*/

void ADD_A(void){
    word res = cpu.AF.High + cpu.AF.High;
    byte carry = (cpu.AF.High & 0x0F) + (cpu.AF.High & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void ADD_B(void){
    word res = cpu.AF.High + cpu.BC.High;
    byte carry = (cpu.AF.High & 0x0F) + (cpu.BC.High & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void ADD_C(void){
    word res = cpu.AF.High + cpu.BC.Low;
    byte carry = (cpu.AF.High & 0x0F) + (cpu.BC.Low & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void ADD_D(void){
    word res = cpu.AF.High + cpu.DE.High;
    byte carry = (cpu.AF.High & 0x0F) + (cpu.DE.High & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void ADD_E(void){
    word res = cpu.AF.High + cpu.DE.Low;
    byte carry = (cpu.AF.High & 0x0F) + (cpu.DE.Low & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void ADD_H(void){
    word res = cpu.AF.High + cpu.HL.High;
    byte carry = (cpu.AF.High & 0x0F) + (cpu.HL.High & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void ADD_L(void){
    word res = cpu.AF.High + cpu.HL.Low;
    byte carry = (cpu.AF.High & 0x0F) + (cpu.HL.Low & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}


/*----------------------------------------------------*/
/*---------------- SUB reg opcodes -------------------*/
/*----------------------------------------------------*/

void SUB_A(void){
    word res = cpu.AF.High - cpu.AF.High;
    byte carry = (cpu.AF.High & 0x0F) < (cpu.AF.High & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < cpu.AF.High) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void SUB_B(void){
    word res = cpu.AF.High - cpu.BC.High;
    byte carry = (cpu.AF.High & 0x0F) < (cpu.BC.High & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < cpu.BC.High) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void SUB_C(void){
    word res = cpu.AF.High - cpu.BC.Low;
    byte carry = (cpu.AF.High & 0x0F) < (cpu.BC.Low & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < cpu.BC.Low) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void SUB_D(void){
    word res = cpu.AF.High - cpu.DE.High;
    byte carry = (cpu.AF.High & 0x0F) < (cpu.DE.High & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < cpu.DE.High) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void SUB_E(void){
    word res = cpu.AF.High - cpu.DE.Low;
    byte carry = (cpu.AF.High & 0x0F) < (cpu.DE.Low & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < cpu.DE.Low) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void SUB_H(void){
    word res = cpu.AF.High - cpu.HL.High;
    byte carry = (cpu.AF.High & 0x0F) < (cpu.HL.High & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < cpu.HL.High) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void SUB_L(void){
    word res = cpu.AF.High - cpu.HL.Low;
    byte carry = (cpu.AF.High & 0x0F) < (cpu.HL.Low & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < cpu.HL.Low) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}


/*----------------------------------------------------*/
/*---------------- ADC reg opcodes -------------------*/
/*----------------------------------------------------*/

void ADC_A(void){
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High + cpu.AF.High + c_bit;
    byte carry = (cpu.AF.High & 0x0F) + (cpu.AF.High & 0x0F) + c_bit;

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}


void ADC_B(void){
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High + cpu.BC.High + c_bit;
    byte carry = (cpu.AF.High & 0x0F) + (cpu.BC.High & 0x0F) + c_bit;

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}


void ADC_C(void){
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High + cpu.BC.Low + c_bit;
    byte carry = (cpu.AF.High & 0x0F) + (cpu.BC.Low & 0x0F) + c_bit;

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}


void ADC_D(void){
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High + cpu.DE.High + c_bit;
    byte carry = (cpu.AF.High & 0x0F) + (cpu.DE.High & 0x0F) + c_bit;

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}


void ADC_E(void){
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High + cpu.DE.Low + c_bit;
    byte carry = (cpu.AF.High & 0x0F) + (cpu.DE.Low & 0x0F) + c_bit;

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}


void ADC_H(void){
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High + cpu.HL.High + c_bit;
    byte carry = (cpu.AF.High & 0x0F) + (cpu.HL.High & 0x0F) + c_bit;

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}


void ADC_L(void){
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High + cpu.HL.Low + c_bit;
    byte carry = (cpu.AF.High & 0x0F) + (cpu.HL.Low & 0x0F) + c_bit;

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}


/*----------------------------------------------------*/
/*---------------- SBC reg opcodes -------------------*/
/*----------------------------------------------------*/

void SBC_A(void){
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High - cpu.AF.High - c_bit;
    byte half_carry = (cpu.AF.High & 0x0F) < ((cpu.AF.High & 0x0F) + c_bit);
    byte carry = cpu.AF.High < (cpu.AF.High + c_bit);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    half_carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    carry ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void SBC_B(void){
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High - cpu.BC.High - c_bit;
    byte half_carry = (cpu.AF.High & 0x0F) < ((cpu.BC.High & 0x0F) + c_bit);
    byte carry = cpu.AF.High < (cpu.BC.High + c_bit);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    half_carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    carry ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void SBC_C(void){
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High - cpu.BC.Low - c_bit;
    byte half_carry = (cpu.AF.High & 0x0F) < ((cpu.BC.Low & 0x0F) + c_bit);
    byte carry = cpu.AF.High < (cpu.BC.Low + c_bit);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    half_carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    carry ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void SBC_D(void){
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High - cpu.DE.High - c_bit;
    byte half_carry = (cpu.AF.High & 0x0F) < ((cpu.DE.High & 0x0F) + c_bit);
    byte carry = cpu.AF.High < (cpu.DE.High + c_bit);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    half_carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    carry ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void SBC_E(void){
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High - cpu.DE.Low - c_bit;
    byte half_carry = (cpu.AF.High & 0x0F) < ((cpu.DE.Low & 0x0F) + c_bit);
    byte carry = cpu.AF.High < (cpu.DE.Low + c_bit);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    half_carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    carry ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void SBC_H(void){
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High - cpu.HL.High - c_bit;
    byte half_carry = (cpu.AF.High & 0x0F) < ((cpu.HL.High & 0x0F) + c_bit);
    byte carry = cpu.AF.High < (cpu.HL.High + c_bit);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    half_carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    carry ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void SBC_L(void){
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High - cpu.HL.Low - c_bit;
    byte half_carry = (cpu.AF.High & 0x0F) < ((cpu.HL.Low & 0x0F) + c_bit);
    byte carry = cpu.AF.High < (cpu.HL.Low + c_bit);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    half_carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    carry ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}


/*----------------------------------------------------*/
/*---------------- Indirect opcodes ------------------*/
/*----------------------------------------------------*/

void INC_HL(void){
    byte data = getDataFrom(cpu.HL.all);
    byte res = data + 1;
    byte carry = (data & 0x0F) + 1;
    writeDataTo(cpu.HL.all,res);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
}

void DEC_HL(void){
    byte data = getDataFrom(cpu.HL.all);
    byte res = data - 1;
    byte carry = (data & 0x0F);
    writeDataTo(cpu.HL.all,res);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low &= ~H_FLAG) : (cpu.AF.Low |= H_FLAG);
}

void ADD_HL(void){
    byte data = getDataFrom(cpu.HL.all);
    word res = data + cpu.AF.High;
    byte carry = (cpu.AF.High & 0x0F) + (data & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void SUB_HL(void){
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

    cpu.AF.High = (res & 0xFF);
}

void ADC_HL(void){
    byte data = getDataFrom(cpu.HL.all);
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High + data + c_bit;
    byte carry = (cpu.AF.High & 0x0F) + (data & 0x0F) + c_bit;

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void SBC_HL(void){
    byte data = getDataFrom(cpu.HL.all);
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High - data - c_bit;
    byte half_carry = (cpu.AF.High & 0x0F) < ((data & 0x0F) + c_bit);
    byte carry = cpu.AF.High < (data + c_bit);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    half_carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    carry ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

/*----------------------------------------------------*/
/*---------------- Immediate opcodes -----------------*/
/*----------------------------------------------------*/

void ADD_n(void){
    byte n = getDataFrom(cpu.PC++);
    word res = cpu.AF.High + n;
    byte carry = (cpu.AF.High & 0x0F) + (n & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void SUB_n(void){
    byte n = getDataFrom(cpu.PC++);
    word res = cpu.AF.High - n;
    byte carry = (cpu.AF.High & 0x0F) < (n & 0x0F);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (cpu.AF.High < n) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void ADC_n(void){
    byte n = getDataFrom(cpu.PC++);
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High + n + c_bit;
    byte carry = (cpu.AF.High & 0x0F) + (n & 0x0F) + c_bit;

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Reset N flag
    cpu.AF.Low &= ~N_FLAG;
    // Update H flag
    (carry > 0x0F) ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    (res > 0xFF) ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

void SBC_n(void){
    byte n = getDataFrom(cpu.PC++);
    byte c_bit = !(cpu.AF.Low & C_FLAG);
    word res = cpu.AF.High - n - c_bit;
    byte half_carry = (cpu.AF.High & 0x0F) < ((n & 0x0F) + c_bit);
    byte carry = cpu.AF.High < (n + c_bit);

    // update Z flag
    res ? (cpu.AF.Low &= ~Z_FLAG) : (cpu.AF.Low |= Z_FLAG);
    // Set N flag
    cpu.AF.Low |= N_FLAG;
    // Update H flag
    half_carry ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);
    // Update C flag
    carry ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);

    cpu.AF.High = (res & 0xFF);
}

