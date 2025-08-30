#include <stdio.h>
#include <stdlib.h>

#include "cpu.h"
#include "memory.h"

GAMEBOY_CPU cpu;

/** @brief Initialize all the registers of the CPU
 *
 * @return void
 */
void InitCpuRegs(void)
{
    printf("[CPU_INIT] Initializing CPU...\n");

    cpu.AF.all = 0x01B0;
    cpu.BC.all = 0x0013;
    cpu.DE.all = 0x00D8;
    cpu.HL.all = 0x014D;
    cpu.SP     = 0xFFFE;
    cpu.PC     = 0x0100;

    printf("[CPU_INIT] Register AF     initialized to: 0x%04x\n",cpu.AF.all);
    printf("[CPU_INIT] Register BC     initialized to: 0x%04x\n",cpu.BC.all);
    printf("[CPU_INIT] Register DE     initialized to: 0x%04x\n",cpu.DE.all);
    printf("[CPU_INIT] Register HL     initialized to: 0x%04x\n",cpu.HL.all);
    printf("[CPU_INIT] Stack Pointer   initialized to: 0x%04x\n",cpu.SP);
    printf("[CPU_INIT] Program Counter initialized to: 0x%04x\n",cpu.PC);
    printf("\n");
}

/** @brief Fetch Next Instruction from memory
 *
 * @return Next Instruction to execute
 */
byte FetchInstr(void)
{
    byte instr = getDataFrom(cpu.PC);
    printf("[CPU_FETCH] Instruction Fetched: 0x%02x\n",instr);

    cpu.PC++;
    printf("[CPU_OP] Program Counter incremented to: 0x%04x",cpu.PC);
    printf("\n");
    return instr;
}

/** @brief Decrement the Stack Pointer
 *
 * Terminate execution if Stack overflows
 *
 * @return none
 */
void DecSP(void)
{
    cpu.SP--;
    printf("[CPU_OP] SP Decremented, new value: 0x%04x\n",cpu.SP);
    printf("\n");

    if(cpu.SP < 0xFF80)
    {
        printf("[CPU_ERROR] Stack Overflow down");
        exit(1);
    }

}

/** @brief Increment the Stack Pointer
 *
 * Terminate execution if Stack overflows
 *
 * @return none
 */
void IncSP(void)
{
    cpu.SP++;
    printf("[CPU_OP] SP Incremented, new value: 0x%04x\n",cpu.SP);
    printf("\n");
    if(cpu.SP > 0xFFFE)
    {
        printf("[CPU_ERROR] Stack Overflow up");
        exit(1);
    }
}

