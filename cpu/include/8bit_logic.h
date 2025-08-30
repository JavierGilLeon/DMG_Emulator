#ifndef H_8BIT_LOGIC_H
#define H_8BIT_LOGIC_H
/*----------------------------------------------------*/
/*---------------- AND reg opcodes -------------------*/
/*----------------------------------------------------*/

void AND_A(void);
void AND_B(void);
void AND_C(void);
void AND_D(void);
void AND_E(void);
void AND_H(void);
void AND_L(void);
void AND_HL(void);
void AND_n(void);
/*----------------------------------------------------*/
/*---------------- OR reg opcodes --------------------*/
/*----------------------------------------------------*/

void OR_A(void);
void OR_B(void);
void OR_C(void);
void OR_D(void);
void OR_E(void);
void OR_H(void);
void OR_L(void);
void OR_HL(void);
void OR_n(void);
/*----------------------------------------------------*/
/*---------------- XOR reg opcodes -------------------*/
/*----------------------------------------------------*/

void XOR_A(void);
void XOR_B(void);
void XOR_C(void);
void XOR_D(void);
void XOR_E(void);
void XOR_H(void);
void XOR_L(void);
void XOR_HL(void);
void XOR_n(void);
/*----------------------------------------------------*/
/*---------------- CP reg opcodes --------------------*/
/*----------------------------------------------------*/

void CP_A(void);
void CP_B(void);
void CP_C(void);
void CP_D(void);
void CP_E(void);
void CP_H(void);
void CP_L(void);
void CP_HL(void);
void CP_n(void);
/*----------------------------------------------------*/
/*---------------- the rest opcodes ------------------*/
/*----------------------------------------------------*/

void CPL(void);
void SCF(void);
void CCF(void);
void DAA(void);



#endif