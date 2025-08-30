
#ifndef H_CPU_H
#define H_CPU_H

#include "common.h"

typedef union cpu_regs{
	struct{
		byte High;
		byte Low;
	};
	word all;
}CPU_REGS;

typedef struct flags{
	unsigned unused: 4;
	unsigned C     : 1;
	unsigned H     : 1;
	unsigned N     : 1;
	unsigned Z     : 1;
}FLAGS;


typedef union reg_F{
	FLAGS bit;
	byte  all;
}REG_F;

typedef union cpu_acc_flags{
	word all;

	struct{
		byte High; 				//Accumulator
	  REG_F Low;
	};

}CPU_ACC_FLAGS;

typedef struct gameboy_cpu{
	CPU_ACC_FLAGS  AF;   // Accumulator & Flags    
	CPU_REGS			 BC;   // Registers B & C
	CPU_REGS			 DE;   // Registers D & E
	CPU_REGS			 HL;   // Registers H & L
	word					 SP;   // Stack Pointer
	word					 PC;   // Program Counter
} GAMEBOY_CPU;



extern GAMEBOY_CPU cpu;



byte FetchInstr(void);
void InitCpuRegs(void);

void DecSP(void);
void IncSP(void);

#endif
