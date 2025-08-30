
#ifndef H_CPU_H
#define H_CPU_H

#include "common.h"

#define Z_FLAG 0x80 // 1000 0000b
#define N_FLAG 0x40 // 0100 0000b
#define H_FLAG 0x20 // 0010 0000b
#define C_FLAG 0x10 // 0001 0000b
										
typedef union cpu_regs{
	struct{
		byte High;
		byte Low;
	};
	word all;
}CPU_REGS;

typedef struct gameboy_cpu{
	CPU_REGS       AF;   // Accumulator & Flags    
	CPU_REGS	     BC;   // Registers B & C
	CPU_REGS	     DE;   // Registers D & E
	CPU_REGS	     HL;   // Registers H & L
	word		       SP;   // Stack Pointer
	word		       PC;   // Program Counter
} GAMEBOY_CPU;



extern GAMEBOY_CPU cpu;



byte FetchInstr(void);
void InitCpuRegs(void);

void DecSP(void);
void IncSP(void);

#endif
