#ifndef H_8BITLOADS_H
#define H_8BITLOADS_H

#include "common.h"




void LD_BC_A     (void);   
void LD_B_n 	 (byte n);
void LD_A_BC     (void);
void LD_C_n    (byte n);

void LD_DE_A     (void); 
void LD_D_n    (byte n); 
void LD_A_DE     (void);
void LD_E_n    (byte n);
void LD_HLP_A    (void);

void LD_H_n		 (byte n); // 0x26
void LD_A_HLP	 (void);   // 0x2A
void LD_L_n	   (byte n); // 0x2E

void LD_HLM_A				 (void); // 0x32
void LD_HL_n				 (void); // 0x36
void LD_A_HLM 			 (void); // 0x3A
void LD_A_n 				 (void); // 0x3E

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

void LD_D_B 				 (void); // 0x50
void LD_D_C 				 (void); // 0x51
void LD_D_D 				 (void); // 0x52
void LD_D_E 				 (void); // 0x53
void LD_D_H 				 (void); // 0x54
void LD_D_L 				 (void); // 0x55
void LD_D_HL 				 (void); // 0x56
void LD_D_A 				 (void); // 0x57
														 
void LD_E_B 				 (void); // 0x58
void LD_E_C 				 (void); // 0x59
void LD_E_D 				 (void); // 0x5A
void LD_E_E 				 (void); // 0x5B
void LD_E_H 				 (void); // 0x5C
void LD_E_L 				 (void); // 0x5D
void LD_E_HL 				 (void); // 0x5E
void LD_E_A 				 (void); // 0x5F

void LD_H_B 				 (void); // 0x60
void LD_H_C 				 (void); // 0x61
void LD_H_D 				 (void); // 0x62
void LD_H_E 				 (void); // 0x63
void LD_H_H 				 (void); // 0x64
void LD_H_L 				 (void); // 0x65
void LD_H_HL 				 (void); // 0x66
void LD_H_A 				 (void); // 0x67
														 
void LD_L_B 				 (void); // 0x68
void LD_L_C 				 (void); // 0x69
void LD_L_D 				 (void); // 0x6A
void LD_L_E 				 (void); // 0x6B
void LD_L_H 				 (void); // 0x6C
void LD_L_L 				 (void); // 0x6D
void LD_L_HL 				 (void); // 0x6E
void LD_L_A 				 (void); // 0x6F

void LD_HL_B 				 (void); // 0x70
void LD_HL_C 				 (void); // 0x71
void LD_HL_D 				 (void); // 0x72
void LD_HL_E 				 (void); // 0x73
void LD_HL_H 				 (void); // 0x74
void LD_HL_L 				 (void); // 0x75

void LD_HL_A 				 (void); // 0x77
void LD_A_B 				 (void); // 0x78
void LD_A_C 				 (void); // 0x79
void LD_A_D 				 (void); // 0x7A
void LD_A_E 				 (void); // 0x7B
void LD_A_H 				 (void); // 0x7C
void LD_A_L 				 (void); // 0x7D
void LD_A_HL 				 (void); // 0x7E
void LD_A_A 				 (void); // 0x7F

void LDH_n_A 				 (void); // 0xE0
void LDH_C_A 				 (void); // 0xE2
void LD_nn_A 				 (void); // 0xEA

void LDH_A_n 				 (void); // 0xF0
void LDH_A_C 				 (void); // 0xF2
void LD_A_nn 				 (void); // 0xFA

#endif
