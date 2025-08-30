#ifndef H_8BITLOADS_H
#define H_8BITLOADS_H
/*----------------------------------------------------*/
/*---------------- reg <- reg opcodes ----------------*/
/*----------------------------------------------------*/

void LD_A_B(void);
void LD_A_C(void);
void LD_A_D(void);
void LD_A_E(void);
void LD_A_H(void);
void LD_A_L(void);
void LD_B_A(void);
void LD_B_C(void);
void LD_B_D(void);
void LD_B_E(void);
void LD_B_H(void);
void LD_B_L(void);
void LD_C_A(void);
void LD_C_B(void);
void LD_C_D(void);
void LD_C_E(void);
void LD_C_H(void);
void LD_C_L(void);
void LD_D_A(void);
void LD_D_B(void);
void LD_D_C(void);
void LD_D_E(void);
void LD_D_H(void);
void LD_D_L(void);
void LD_E_A(void);
void LD_E_B(void);
void LD_E_C(void);
void LD_E_D(void);
void LD_E_H(void);
void LD_E_L(void);
void LD_H_A(void);
void LD_H_B(void);
void LD_H_C(void);
void LD_H_D(void);
void LD_H_E(void);
void LD_H_L(void);
void LD_L_A(void);
void LD_L_B(void);
void LD_L_C(void);
void LD_L_D(void);
void LD_L_E(void);
void LD_L_H(void);


/*----------------------------------------------------*/
/*---------------- reg <- (HL) opcodes ---------------*/
/*----------------------------------------------------*/

void LD_A_HL(void);
void LD_B_HL(void);
void LD_C_HL(void);
void LD_D_HL(void);
void LD_E_HL(void);
void LD_H_HL(void);
void LD_L_HL(void);


/*----------------------------------------------------*/
/*---------------- (HL) <- reg opcodes ---------------*/
/*----------------------------------------------------*/

void LD_HL_A(void);
void LD_HL_B(void);
void LD_HL_C(void);
void LD_HL_D(void);
void LD_HL_E(void);
void LD_HL_H(void);
void LD_HL_L(void);


/*----------------------------------------------------*/
/*---------------- reg <- num opcodes ----------------*/
/*----------------------------------------------------*/

void LD_A_n(void);
void LD_B_n(void);
void LD_C_n(void);
void LD_D_n(void);
void LD_E_n(void);
void LD_H_n(void);
void LD_L_n(void);
/*----------------------------------------------------*/
/*---------------- The rest of the LD8 opcodes -------*/
/*----------------------------------------------------*/

void LD_BC_A(void);
void LD_A_BC(void);
void LD_DE_A(void);
void LD_A_DE(void);
void LD_HLP_A(void);
void LD_A_HLP(void);
void LD_HLM_A(void);
void LD_A_HLM(void);
void LD_HL_n(void);
void LDH_n_A(void);
void LDH_C_A(void);
void LDH_nn_A(void);
void LDH_A_n(void);
void LDH_A_C(void);
void LDH_A_nn(void);
#endif