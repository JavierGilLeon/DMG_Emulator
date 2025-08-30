#include "opcodes.h"
#include "cpu.h"



/*LD8_REG_OP ld8_reg_op[] = {
    {&cpu.AF.High,&cpu.AF.High}, // LD A,A
    {&cpu.AF.High,&cpu.BC.High}, // LD A,B
    {&cpu.AF.High,&cpu.BC.Low }, // LD A,C
    {&cpu.AF.High,&cpu.DE.High}, // LD A,D
    {&cpu.AF.High,&cpu.DE.Low }, // LD A,E
    {&cpu.AF.High,&cpu.HL.High}, // LD A,H
    {&cpu.AF.High,&cpu.HL.Low }, // LD A,L


    {&cpu.BC.High,&cpu.AF.High}, // LD B,A
    {&cpu.BC.High,&cpu.BC.High}, // LD B,B
    {&cpu.BC.High,&cpu.BC.Low }, // LD B,C
   {&cpu.BC.High,&cpu.DE.High}, // LD B,D
   {&cpu.BC.High,&cpu.DE.Low }, // LD B,E
   {&cpu.BC.High,&cpu.HL.High}, // LD B,H
   {&cpu.BC.High,&cpu.HL.Low }, // LD B,L


   {&cpu.BC.Low,&cpu.AF.High},  // LD C,A
   {&cpu.BC.Low,&cpu.BC.High},  // LD C,B
   {&cpu.BC.Low,&cpu.BC.Low },  // LD C,C
   {&cpu.BC.Low,&cpu.DE.High},  // LD C,D
   {&cpu.BC.Low,&cpu.DE.Low },  // LD C,E
   {&cpu.BC.Low,&cpu.HL.High},  // LD C,H
   {&cpu.BC.Low,&cpu.HL.Low },  // LD C,L
                                               
                                               
   {&cpu.HL.High,&cpu.AF.High}, // LD A,A
   {&cpu.HL.High,&cpu.BC.High}, // LD A,B
   {&cpu.HL.High,&cpu.BC.Low }, // LD A,C
   {&cpu.HL.High,&cpu.DE.High}, // LD A,D
   {&cpu.HL.High,&cpu.DE.Low }, // LD A,E
   {&cpu.HL.High,&cpu.HL.High}, // LD A,H
   {&cpu.HL.High,&cpu.HL.Low }, // LD A,L


   {&cpu.HL.Low,&cpu.AF.High}, // LD A,A
   {&cpu.HL.Low,&cpu.BC.High}, // LD A,B
   {&cpu.HL.Low,&cpu.BC.Low }, // LD A,C
   {&cpu.HL.Low,&cpu.DE.High}, // LD A,D
   {&cpu.HL.Low,&cpu.DE.Low }, // LD A,E
   {&cpu.HL.Low,&cpu.HL.High}, // LD A,H
   {&cpu.HL.Low,&cpu.HL.Low }, // LD A,L
                                               

   {&cpu.AF.High,&cpu.AF.High}, // LD A,A
   {&cpu.AF.High,&cpu.BC.High}, // LD A,B
   {&cpu.AF.High,&cpu.BC.Low }, // LD A,C
   {&cpu.AF.High,&cpu.DE.High}, // LD A,D
   {&cpu.AF.High,&cpu.DE.Low }, // LD A,E
   {&cpu.AF.High,&cpu.HL.High}, // LD A,H
   {&cpu.AF.High,&cpu.HL.Low }, // LD A,L
                                               

   {&cpu.AF.High,&cpu.AF.High}, // LD A,A
   {&cpu.AF.High,&cpu.BC.High}, // LD A,B
   {&cpu.AF.High,&cpu.BC.Low }, // LD A,C
   {&cpu.AF.High,&cpu.DE.High}, // LD A,D
   {&cpu.AF.High,&cpu.DE.Low }, // LD A,E
   {&cpu.AF.High,&cpu.HL.High}, // LD A,H
   {&cpu.AF.High,&cpu.HL.Low }, // LD A,L
};*/

// Where all OPCodes will be stored
OPCODE_ENTRY table[0x100];


void LD8_Reg(void *arg){
    LD8_REG_OP *op = (LD8_REG_OP*)arg;
    *(op->dst) = *(op->src);
}

void Init_LD8_Op(void)
{
   // First load all "reg <- reg" instructions to the dispatch table
   byte *regs[] = {
      &cpu.BC.High, // Reg B
      &cpu.BC.Low,  // Reg C
      &cpu.DE.High, // Reg D
      &cpu.DE.Low,  // Reg E
      &cpu.HL.High, // Reg H
      &cpu.HL.Low,  // Reg L
      &cpu.AF.High  // Reg A
   };

   LD8_REG_OP op[7*7]; // 7 registers
   
   byte index = 0;
   for(byte i = 0; i < 7; i++)
   {
      for(byte j = 0; j < 7; j++)
      {
         op[index].dst = regs[i];
         op[index].src = regs[j];
         index++;
      }
   }


   table[0x40] = (OPCODE_ENTRY){&LD8_Reg,&op[0]};


}

