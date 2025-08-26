#ifndef H_MEMORY_H
#define H_MEMORY_H

#include "common.h"

extern byte memory[0x10000]; // 64 KB
											// [0000h - 3FFFh] ROM0:  Non switchable ROM bank
											// [4000h - 7FFFh] ROMX:  Switchable ROM bank 
											// [8000h - 9FFFh] VRAM:  Video RAM
											// [A000h - BFFFh] SRAM:  External RAM in cartdrige
											// [C000h - CFFFh] WRAM0: Work RAM
											// [D000h - DFFFh] WRAMX: Work RAM
											// [E000h - FDFFh] ECHO:  Mirror of WRAM
											// [FE00h - FE9Fh] OAM:   Sprite Information Table
											// [FEA0h - FEFFh] UNUSED
											// [FF00h - FF7Fh] I/O Regs
											// [FF80h - FFFEh] HRAM:  Internal CPU RAM
											// [FFFh] 			 IE Reg:  Interrupt enable reg


byte getDataFrom(word ADDR);
void writeDataTo(word ADDR, byte REG);

#endif

