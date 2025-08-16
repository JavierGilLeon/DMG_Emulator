#ifndef H_INSTRUCTIONSET_H
#define H_INSTRUCTIONSET_H

#include "common.h"


void InitInstr(void);

//----------------------------------
//----------8-BIT LOADS-------------
//----------------------------------

void LD_BC_A				 (void); // 0x02
void LD_B_D8				 (void); // 0x06
void LD_A_BC				 (void); // 0x0A
void LD_C_D8				 (void); // 0x0E

void LD_DE_A				 (void); // 0x12
void LD_D_D8				 (void); // 0x16
void LD_A_DE				 (void); // 0x1A
void LD_E_D8				 (void); // 0x1E

void LD_HLP_A				 (void); // 0x22
void LD_H_D8				 (void); // 0x26
void LD_A_HLP				 (void); // 0x2A
void LD_L_D8				 (void); // 0x2E

void LD_HLM_A				 (void); // 0x32
void LD_HL_D8				 (void); // 0x36
void LD_A_HLM 			 (void); // 0x3A
void LD_A_D8 				 (void); // 0x3E

void LD_B_B 				 (void); // 0x40
void LD_B_C 				 (void); // 0x41
void LD_B_D 				 (void); // 0x42
void LD_B_E 				 (void); // 0x43
void LD_B_H 				 (void); // 0x44
void LD_B_L 				 (void); // 0x45
void LD_B_HL 				 (void); // 0x46
void LD_B_A 				 (void); // 0x47
void LD_C_B 				 (void); // 0x48
void LD_C_C 				 (void); // 0x49
void LD_C_D 				 (void); // 0x4A
void LD_C_E 				 (void); // 0x4B
void LD_C_H 				 (void); // 0x4C
void LD_C_L 				 (void); // 0x4D
void LD_C_HL 				 (void); // 0x4E
void LD_C_A 				 (void); // 0x4F


// 16-bit loads
// 8-bit arithmetic/logical
// 16-bit arithmetic
// Rotates,shifts and bit operations
// Control Flow
// Miscellaneous





#endif

