
import os


regs = ['A','B','C','D','E','H','L']

regs_struct = [
    "cpu.AF.High", # Reg A
    "cpu.BC.High", # Reg B
    "cpu.BC.Low",  # Reg C
    "cpu.DE.High", # Reg D
    "cpu.DE.Low",  # Reg E
    "cpu.HL.High", # Reg H
    "cpu.HL.Low"   # Reg L
]


if __name__ =="__main__":
    # Obtain file path
    dir = os.path.dirname(__file__)

    # Construct absolute paths for output files
    header = os.path.join(dir,"..","cpu","include","8bitLoads.h")
    src    = os.path.join(dir,"..","cpu","src","8bitLoads.c")

    with open(header,"w") as f:
        f.write("#ifndef H_8BITLOADS_H\n")
        f.write("#define H_8BITLOADS_H\n")

        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- reg <- reg opcodes ----------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in regs:
            for j in regs:
                if i != j:
                    f.write("void LD_" + i + "_" + j + "(void);\n")

        f.write("\n\n")
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- reg <- (HL) opcodes ---------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in regs:
            f.write("void LD_" + i + "_HL(void);\n")

        f.write("\n\n")


        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- (HL) <- reg opcodes ---------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in regs:
            f.write("void LD_HL_" + i + "(void);\n")

        f.write("\n\n")


        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- reg <- num opcodes ----------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in regs:
            f.write("void LD_" + i + "_n(void);\n")


        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- The rest of the LD8 opcodes -------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        f.write("void LD_BC_A(void);\n")

        f.write("void LD_A_BC(void);\n")

        f.write("void LD_DE_A(void);\n")

        f.write("void LD_A_DE(void);\n")

        f.write("void LD_HLP_A(void);\n")

        f.write("void LD_A_HLP(void);\n")

        f.write("void LD_HLM_A(void);\n")

        f.write("void LD_A_HLM(void);\n")

        f.write("void LD_HL_n(void);\n")

        f.write("void LDH_n_A(void);\n")

        f.write("void LDH_C_A(void);\n")

        f.write("void LDH_nn_A(void);\n")

        f.write("void LDH_A_n(void);\n")

        f.write("void LDH_A_C(void);\n")

        f.write("void LDH_A_nn(void);\n")

        f.write("#endif")
#**********************************************************************************#
    with open(src,"w") as f:
        f.write("#include " + '"' + "cpu.h"    + '"' + "\n")
        f.write("#include " + '"' + "memory.h" + '"' + "\n")
        f.write("\n")

        #---------------- Write "reg <- reg" opcodes ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- reg <- reg opcodes ----------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            for j in range(0,len(regs)):
                if regs[i] != regs[j]:
                    f.write(f"void LD_{regs[i]}_{regs[j]}(void){{\n")

                    f.write(f"    {regs_struct[i]} = {regs_struct[j]};\n")
                    f.write("}\n\n")

            f.write("\n")


        #---------------- Write "reg <- (HL)" opcodes ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- reg <- (HL) opcodes ---------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void LD_{regs[i]}_HL(void){{\n")
            f.write(f"    {regs_struct[i]} = getDataFrom(cpu.HL.all);\n")
            f.write("}\n\n")


        #---------------- Write "(HL) <- reg" opcodes ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- (HL) <- reg opcodes ---------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void LD_HL_{regs[i]}(void){{\n")
            f.write(f"    writeDataTo(cpu.HL.all,{regs_struct[i]});\n")
            f.write("}\n\n")


        #---------------- Write "reg <- num" opcodes ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- reg <- num opcodes ----------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void LD_{regs[i]}_n(void){{\n")
            f.write(f"    {regs_struct[i]} = getDataFrom(cpu.PC++);\n")
            f.write("}\n\n")

        #---------------- Write special LD opcodes ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- The rest of the LD8 opcodes -------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        f.write("void LD_BC_A(void){\n")
        f.write("    writeDataTo(cpu.BC.all, cpu.AF.High);\n")
        f.write("}\n\n")

        f.write("void LD_A_BC(void){\n")
        f.write("    cpu.AF.High = getDataFrom(cpu.BC.all);\n")
        f.write("}\n\n")

        f.write("void LD_DE_A(void){\n")
        f.write("    writeDataTo(cpu.DE.all, cpu.AF.High);\n")
        f.write("}\n\n")

        f.write("void LD_A_DE(void){\n")
        f.write("    cpu.AF.High = getDataFrom(cpu.DE.all);\n")
        f.write("}\n\n")

        f.write("void LD_HLP_A(void){\n")
        f.write("    writeDataTo(cpu.HL.all++, cpu.AF.High);\n")
        f.write("}\n\n")

        f.write("void LD_A_HLP(void){\n")
        f.write("    cpu.AF.High = getDataFrom(cpu.HL.all++);\n")
        f.write("}\n\n")

        f.write("void LD_HLM_A(void){\n")
        f.write("    writeDataTo(cpu.HL.all--, cpu.AF.High);\n")
        f.write("}\n\n")

        f.write("void LD_A_HLM(void){\n")
        f.write("    cpu.AF.High = getDataFrom(cpu.HL.all--);\n")
        f.write("}\n\n")

        f.write("void LD_HL_n(void){\n")
        f.write("    byte n = getDataFrom(cpu.PC++);\n")
        f.write("    writeDataTo(cpu.HL.all,n);\n")
        f.write("}\n\n")

        f.write("void LDH_n_A(void){\n")
        f.write("    byte n = getDataFrom(cpu.PC++);\n")
        f.write("    writeDataTo(0xFF00+n, cpu.AF.High);\n")
        f.write("}\n\n")

        f.write("void LDH_C_A(void){\n")
        f.write("    writeDataTo(0xFF00+cpu.BC.Low,cpu.AF.High);\n")
        f.write("}\n\n")

        f.write("void LD_nn_A(void){\n")
        f.write("    byte lsb = getDataFrom(cpu.PC++);\n")
        f.write("    byte msb = getDataFrom(cpu.PC++);\n")
        f.write("    word ADDR = (msb << 8) | lsb;\n")
        f.write("    writeDataTo(ADDR,cpu.AF.High);\n")
        f.write("}\n\n")

        f.write("void LDH_A_n(void){\n")
        f.write("    byte ADDR = 0xFF00 + getDataFrom(cpu.PC++);\n")
        f.write("    cpu.AF.High = getDataFrom(ADDR);\n")
        f.write("}\n\n")

        f.write("void LDH_A_C(void){\n")
        f.write("    cpu.AF.High = getDataFrom(0xFF00 + cpu.BC.Low);\n")
        f.write("}\n\n")

        f.write("void LD_A_nn(void){\n")
        f.write("    byte lsb = getDataFrom(cpu.PC++);\n")
        f.write("    byte msb = getDataFrom(cpu.PC++);\n")
        f.write("    word ADDR = (msb << 8)| lsb;\n")
        f.write("    cpu.AF.High = getDataFrom(ADDR);\n")
        f.write("}\n\n")
