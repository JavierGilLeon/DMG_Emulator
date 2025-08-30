import os

regs = [
    "BC",
    "DE",
    "HL",
]

regs_struct = [
    "cpu.BC.all",
    "cpu.DE.all",
    "cpu.HL.all"
]

regs_byte = [
    "cpu.BC.High", # Reg B
    "cpu.BC.Low",  # Reg C
    "cpu.DE.High", # Reg D
    "cpu.DE.Low",  # Reg E
    "cpu.HL.High", # Reg H
    "cpu.HL.Low",  # Reg L
]

if __name__ == "__main__":
    # Obtain file path
    dir = os.path.dirname(__file__)

    # Construct absolute paths for output files
    header = os.path.join(dir,"..","cpu","include","16bitLoads.h")
    src    = os.path.join(dir,"..","cpu","src","16bitLoads.c")


    with open(header,"w") as f:
        f.write("#ifndef H_16BITLOADS_H\n")
        f.write("#define H_16BITLOADS_H\n")


        #---------------- Write "reg <- num opcodes" ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- reg <- num opcodes ----------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void LD_{regs[i]}_nn(void);\n")

        f.write("\n\n")


        #---------------- Write "POP reg opcodes" ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- POP reg opcodes ------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void POP_{regs[i]}(void);\n")
        f.write(f"void POP_AF(void);\n")

        f.write("\n\n")


        #---------------- Write "PUSH reg opcodes" ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- PUSH reg opcodes ------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        j = 0
        for i in range(0,len(regs_byte),2):
            f.write(f"void PUSH_{regs[j]}(void);\n")
        f.write(f"void PUSH_AF(void);\n")
        f.write("\n\n")


        #---------------- Write the other opcodes ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- other opcodes ---------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        f.write("void LD_nn_SP(void);\n")
        f.write("void LD_HL_SPe(void);\n")
        f.write("void LD_SP_HL(void);\n")

        f.write("#endif")

    #**************************************************************************#
    with open(src,"w") as f:
        f.write(f"#include " + '"' + "cpu.h"    + '"' + "\n")
        f.write("#include " + '"' + "memory.h" + '"' + "\n")
        f.write("\n")

        #---------------- Write "reg <- num opcodes" ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- reg <- num opcodes ----------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void LD_{regs[i]}_nn(void){{\n")
            f.write("    byte lsb = getDataFrom(cpu.PC++);\n")
            f.write("    byte msb = getDataFrom(cpu.PC++);\n")
            f.write(f"    {regs_struct[i]} = (msb << 8) | lsb;\n")
            f.write("}\n\n")


        #---------------- Write "POP reg opcodes" ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- POP reg opcodes ------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")


        for i in range(0,len(regs)):
            f.write(f"void POP_{regs[i]}(void){{\n")
            f.write("    byte lsb = getDataFrom(cpu.SP++);\n")
            f.write("    byte msb = getDataFrom(cpu.SP++);\n")
            f.write(f"   {regs_struct[i]} = (msb << 8) | lsb;\n")
            f.write("}\n\n")

        # To be sure that only the flags are set in F reg
        f.write("void POP_AF(void){\n")
        f.write("    byte lsb = getDataFrom(cpu.SP++);\n")
        f.write("    byte msb = getDataFrom(cpu.SP++);\n")
        f.write("    cpu.AF.all = (msb << 8) | (lsb & 0xF0);\n")
        f.write("}\n\n")


        #---------------- Write "PUSH reg opcodes" ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- PUSH reg opcodes ------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        j = 0
        regs.append("AF")
        regs_byte.append("cpu.AF.High")
        regs_byte.append("cpu.AF.Low")

        for i in range(0,len(regs_byte),2):
            f.write(f"void PUSH_{regs[j]}(void){{\n")
            f.write(f"    writeDataTo(--cpu.SP,{regs_byte[i]});\n")
            f.write(f"    writeDataTo(--cpu.SP,{regs_byte[i+1]});\n")
            j = j+1
            f.write("}\n\n")

        regs.pop()
        regs_byte.pop()
        regs_byte.pop()

        #---------------- Write the other opcodes ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- other opcodes ---------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        f.write("void LD_nn_SP(void){\n")
        f.write("    byte lsb = getDataFrom(cpu.PC++);\n")
        f.write("    byte msb = getDataFrom(cpu.PC++);\n")
        f.write("    word ADDR = (msb << 8) | lsb;\n")
        f.write("\n")
        f.write("    writeDataTo(ADDR,cpu.SP & 0xFF);\n")
        f.write("    writeDataTo(ADDR+1,(cpu.SP >> 8) & 0xFF);\n")
        f.write("}\n\n")

        f.write("void LD_HL_SPe(void){\n")
        f.write("    signed_byte e = getDataFrom(cpu.PC++);\n")
        f.write("    word result = cpu.SP + e;\n")
        f.write("    cpu.HL.all = result;\n")
        f.write("\n")

        f.write("    // Reset flags Z & N\n")
        f.write("    cpu.AF.Low &= ~(Z_FLAG | N_FLAG);\n")

        f.write("    // calculate H flag\n")
        f.write("    ((cpu.SP & 0x0F) + (e & 0x0F)) > 0x0F ? (cpu.AF.Low |= H_FLAG) : (cpu.AF.Low &= ~H_FLAG);\n");

        f.write("    // calculate C flag\n")
        f.write("    ((cpu.SP & 0xFF) + (e & 0xFF)) > 0xFF ? (cpu.AF.Low |= C_FLAG) : (cpu.AF.Low &= ~C_FLAG);\n")
        f.write("}\n\n")

        f.write("void LD_SP_HL(void){\n")
        f.write("    cpu.SP = cpu.HL.all;\n")
        f.write("}\n\n")

