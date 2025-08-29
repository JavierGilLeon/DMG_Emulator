#ifndef H_OPCODES_H
#define H_OPCODES_H

#include "common.h"


// LD 8-bit: reg <- reg 
typedef struct ld8_reg_op{
	byte *dst;
	byte *src;
} LD8_REG_OP;



// Dispatch Table
typedef void (*ExecOPCode)(void *);

typedef struct opcode_entry{
	ExecOPCode execute;
	void *arg;
}OPCODE_ENTRY;


extern OPCODE_ENTRY table[0x100];


#endif
