
#ifndef H_CPU_H
#define H_CPU_H

#include "common.h"
#include "memory.h"

typedef union cpu_regs{
	struct{
		byte High;
		byte Low;
	};
	word all;
}CPU_REGS;

typedef struct gameboy_cpu{
	CPU_REGS AF;   // Accumulator & Flags
	CPU_REGS BC;   // Registers B & C
	CPU_REGS DE;   // Registers D & E
	CPU_REGS HL;   // Registers H & L
	word     SP;   // Stack Pointer
	word     PC;   // Program Counter
} GAMEBOY_CPU;

extern GAMEBOY_CPU cpu;

#endif
