
import os


regs = [
    "BC",
    "DE",
    "HL",
    "SP"
]

regs_struct = [
    "cpu.BC.all",  # Reg BC
    "cpu.DE.all",  # Reg DE
    "cpu.HL.all",  # Reg HL
    "cpu.SP"       # Stack Pointer
]

flag_reg = "cpu.AF.Low"

flags = [
    "Z_FLAG",
    "N_FLAG",
    "H_FLAG",
    "C_FLAG"
]

Z = 0
N = 1
H = 2
C = 3

indirect_reg = "HL"

if __name__ == "__main__":
    # Obtain file path
    dir = os.path.dirname(__file__)

    # Construct absolute paths for output files
    header = os.path.join(dir,"..","cpu","include","16bit_arithmetic.h")
    src    = os.path.join(dir,"..","cpu","src","16bit_arithmetic.c")

    with open(header,"w") as f:
        f.write("#ifndef H_16_BIT_ARITHMETIC_H\n")
        f.write("#define H_16_BIT_ARITHMETIC_H\n")

        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- INC reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")
        for i in range(0,len(regs)):
            f.write(f"void INC_{regs[i]}(void);\n")

        f.write("\n\n")
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- DEC reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")
        for i in range(0,len(regs)):
            f.write(f"void DEC_{regs[i]}(void);\n")
        f.write("\n\n")

        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- ADD HL reg opcodes ----------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")
        for i in range(0,len(regs)):
            f.write(f"void ADD_HL_{regs[i]}(void);\n")
        f.write("\n\n")

        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- ADD SP+e reg opcodes ----------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")
        f.write(f"void ADD_SP_e(void);\n")
        f.write("\n\n")

        f.write("#endif")

    with open(src,"w") as f:
        f.write("#include " + '"' + "16bit_arithmetic.h" + '"' + "\n")
        f.write("#include " + '"' + "cpu.h" + '"' + "\n")
        f.write("#include " + '"' + "memory.h" + '"' + "\n")
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- INC reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")
        for i in range(0,len(regs)):
            f.write(f"void INC_{regs[i]}(void){{\n")
            f.write(f"    {regs_struct[i]}++;\n")
            f.write("}\n\n")

        f.write("\n")

        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- DEC reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")
        for i in range(0,len(regs)):
            f.write(f"void DEC_{regs[i]}(void){{\n")
            f.write(f"    {regs_struct[i]}--;\n")
            f.write("}\n\n")

        f.write("\n")

        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- ADD HL reg opcodes ----------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")
        for i in range(0,len(regs)):
            f.write(f"void ADD_{regs[i]}(void){{\n")
            f.write(f"    word res = {regs_struct[2]} + {regs_struct[i]};\n")
            f.write(f"    word low_carry = ({regs_struct[2]} & 0x0FFF) + ({regs_struct[i]} & 0x0FFF);\n")
            f.write("\n")

            f.write( "    // Reset N flag\n")
            f.write(f"    {flag_reg} &= ~{flags[N]};\n")

            f.write( "    // Update H flag\n")
            f.write(f"    (low_carry > 0x0FFF) ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")

            f.write( "    // Update C flag\n")
            f.write(f"    ({regs_struct[2]} + {regs_struct[i]} > 0xFFFF) ? ({flag_reg} |= {flags[C]}) : ({flag_reg} &= ~{flags[C]});\n")
            f.write("\n")

            f.write(f"    {regs_struct[2]} = res;\n")
            f.write("}\n\n")

        f.write("\n")

        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- ADD SP+e reg opcodes ----------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")
        f.write(f"void ADD_SP_e(void){{\n")
        f.write(f"    signed_byte e = getDataFrom(cpu.PC++);\n")
        f.write(f"    word res = {regs_struct[3]} + e;\n")
        f.write(f"    word low_carry = ({regs_struct[3]} & 0x0F) + (e & 0x0F);\n")
        f.write(f"    word carry = ({regs_struct[3]} & 0xFF) + (e & 0xFF);\n")
        f.write("\n")

        f.write( "    // Reset N & Z flags\n")
        f.write(f"    {flag_reg} &= ~({flags[N]} | {flags[Z]});\n")

        f.write( "    // Update H flag\n")
        f.write(f"    (low_carry > 0x0F) ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")

        f.write( "    // Update C flag\n")
        f.write(f"    (carry > 0xFF) ? ({flag_reg} |= {flags[C]}) : ({flag_reg} &= ~{flags[C]});\n")
        f.write("}\n\n")

