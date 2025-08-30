#ifndef H_8BIT_ARITHMETIC_H
#define H_8BIT_ARITHMETIC_H


/*----------------------------------------------------*/
/*---------------- INC reg opcodes -------------------*/
/*----------------------------------------------------*/

void INC_A(void);
void INC_B(void);
void INC_C(void);
void INC_D(void);
void INC_E(void);
void INC_H(void);
void INC_L(void);

/*----------------------------------------------------*/
/*---------------- DEC reg opcodes -------------------*/
/*----------------------------------------------------*/

void DEC_A(void);
void DEC_B(void);
void DEC_C(void);
void DEC_D(void);
void DEC_E(void);
void DEC_H(void);
void DEC_L(void);

/*----------------------------------------------------*/
/*---------------- ADD reg opcodes -------------------*/
/*----------------------------------------------------*/

void ADD_A(void);
void ADD_B(void);
void ADD_C(void);
void ADD_D(void);
void ADD_E(void);
void ADD_H(void);
void ADD_L(void);

/*----------------------------------------------------*/
/*---------------- SUB reg opcodes -------------------*/
/*----------------------------------------------------*/

void SUB_A(void);
void SUB_B(void);
void SUB_C(void);
void SUB_D(void);
void SUB_E(void);
void SUB_H(void);
void SUB_L(void);

/*----------------------------------------------------*/
/*---------------- ADC reg opcodes -------------------*/
/*----------------------------------------------------*/

void ADC_A(void);
void ADC_B(void);
void ADC_C(void);
void ADC_D(void);
void ADC_E(void);
void ADC_H(void);
void ADC_L(void);
/*----------------------------------------------------*/
/*---------------- SBC reg opcodes -------------------*/
/*----------------------------------------------------*/

void SBC_A(void);
void SBC_B(void);
void SBC_C(void);
void SBC_D(void);
void SBC_E(void);
void SBC_H(void);
void SBC_L(void);

/*----------------------------------------------------*/
/*---------------- Indirect opcodes ------------------*/
/*----------------------------------------------------*/

void INC_HL(void);
void DEC_HL(void);
void ADD_HL(void);
void SUB_HL(void);
void ADC_HL(void);
void SBC_HL(void);

/*----------------------------------------------------*/
/*---------------- Immediate opcodes -----------------*/
/*----------------------------------------------------*/

void ADD_n(void);
void SUB_n(void);
void ADC_n(void);
void SBC_n(void);

#endif