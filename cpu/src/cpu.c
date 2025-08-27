#include "cpu.h"
#include "memory.h"
#include "stdio.h"

GAMEBOY_CPU cpu;

/** @brief Initialize the registers of the CPU
 *
 * @return void
 */
void InitCpuRegs(void)
{
    cpu.AF.all = 0x01B0;
    cpu.BC.all = 0x0013;
    cpu.DE.all = 0x00D8;
    cpu.HL.all = 0x014D;
    cpu.SP     = 0xFFFE;
    cpu.PC     = 0x0100;
}

/** @brief Fetch Next Instruction from memory
 *
 * @return Next Instruction to execute
 */
byte FetchInstr(void)
{
    byte instr = memory[cpu.PC];
    printf("[FETCH] Instruction Fetched: 0x%02x\n",instr);
    cpu.PC++;
    return instr;
}


