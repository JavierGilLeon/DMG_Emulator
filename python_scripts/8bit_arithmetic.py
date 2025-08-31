import os


regs = [
    "A",
    "B",
    "C",
    "D",
    "E",
    "H",
    "L"
]

regs_struct = [
    "cpu.AF.High", # Reg A
    "cpu.BC.High", # Reg B
    "cpu.BC.Low",  # Reg C
    "cpu.DE.High", # Reg D
    "cpu.DE.Low",  # Reg E
    "cpu.HL.High", # Reg H
    "cpu.HL.Low",  # Reg L
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
    header = os.path.join(dir,"..","cpu","include","8bit_arithmetic.h")
    src    = os.path.join(dir,"..","cpu","src","8bit_arithmetic.c")

    with open(header,"w") as f:
        f.write("#ifndef H_8BIT_ARITHMETIC_H\n")
        f.write("#define H_8BIT_ARITHMETIC_H\n")

        f.write("\n\n")

        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- INC reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")


        for i in regs:
            f.write(f"void INC_{i}(void);\n")
        f.write("\n")

        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- DEC reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in regs:
            f.write(f"void DEC_{i}(void);\n")
        f.write("\n")

        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- ADD reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in regs:
            f.write(f"void ADD_{i}(void);\n")
        f.write("\n")

        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- SUB reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in regs:
            f.write(f"void SUB_{i}(void);\n")
        f.write("\n")

        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- ADC reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in regs:
            f.write(f"void ADC_{i}(void);\n")

        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- SBC reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in regs:
            f.write(f"void SBC_{i}(void);\n")
        f.write("\n")

        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- Indirect opcodes ------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        # INC (HL)
        f.write("void INC_HL(void);\n")

        # DEC (HL)
        f.write("void DEC_HL(void);\n")

        # ADD (HL)
        f.write(f"void ADD_HL(void);\n")

        # SUB (HL)
        f.write(f"void SUB_HL(void);\n")

        # ADC (HL)
        f.write(f"void ADC_HL(void);\n")

        # SBC (HL)
        f.write(f"void SBC_HL(void);\n")
        f.write("\n")

        #---------------- Immediate opcodes ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- Immediate opcodes -----------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        # ADD n
        f.write(f"void ADD_n(void);\n")

        # SUB n
        f.write(f"void SUB_n(void);\n")

        #ADC n
        f.write(f"void ADC_n(void);\n")

        # SBC n
        f.write(f"void SBC_n(void);\n")
        f.write("\n")



        f.write("#endif")

#**************************************************************************************#

    with open(src,"w") as f:

        f.write("#include " + '"' + "cpu.h"    + '"' + "\n")
        f.write("#include " + '"' + "memory.h" + '"' + "\n")
        f.write("\n")

        #---------------- INC reg opcode ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- INC reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void INC_{regs[i]}(void){{" + "\n")
            f.write(f"    byte carry = {regs_struct[i]};\n")
            f.write(f"    {regs_struct[i]}++;\n")
            f.write("\n")

            f.write( "    // update Z flag\n")
            f.write(f"    {regs_struct[i]} ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

            f.write( "    // Reset N flag\n")
            f.write(f"    {flag_reg} &= ~{flags[N]};\n")

            f.write(f"    // Update H flag\n")
            f.write(f"    ((carry & 0x0F) + 1) > 0x0F ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")
            f.write("}\n\n")

        f.write("\n")


        #---------------- DEC reg opcode ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- DEC reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void DEC_{regs[i]}(void){{\n")
            f.write(f"    byte carry = {regs_struct[i]};\n")
            f.write(f"    {regs_struct[i]}--;\n")
            f.write("\n")

            f.write( "    // update Z flag\n")
            f.write(f"    {regs_struct[i]} ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

            f.write( "    // Set N flag\n")
            f.write(f"    {flag_reg} |= {flags[N]};\n")

            f.write(f"    // Update H flag\n")
            f.write(f"    (carry & 0x0F) ? ({flag_reg} &= ~{flags[H]}) : ({flag_reg} |= {flags[H]});\n")
            f.write("}\n\n")

        f.write("\n")

        #---------------- ADD reg opcode ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- ADD reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void ADD_{regs[i]}(void){{\n")
            f.write(f"    word res = {regs_struct[0]} + {regs_struct[i]};\n")
            f.write(f"    byte carry = ({regs_struct[0]} & 0x0F) + ({regs_struct[i]} & 0x0F);\n")
            f.write("\n")

            f.write( "    // update Z flag\n")
            f.write(f"    (res & 0xFF) ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

            f.write( "    // Reset N flag\n")
            f.write(f"    {flag_reg} &= ~{flags[N]};\n")

            f.write( "    // Update H flag\n")
            f.write(f"    (carry > 0x0F) ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")

            f.write( "    // Update C flag\n")
            f.write(f"    (res > 0xFF) ? ({flag_reg} |= {flags[C]}) : ({flag_reg} &= ~{flags[C]});\n")

            f.write("\n")
            f.write(f"    {regs_struct[0]} = (res & 0xFF);\n")
            f.write("}\n\n")

        f.write("\n")

        #---------------- SUB reg opcode ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- SUB reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void SUB_{regs[i]}(void){{\n")
            f.write(f"    word res = {regs_struct[0]} - {regs_struct[i]};\n")
            f.write(f"    byte carry = ({regs_struct[0]} & 0x0F) < ({regs_struct[i]} & 0x0F);\n")
            f.write("\n")

            f.write( "    // update Z flag\n")
            f.write(f"    (res & 0xFF) ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

            f.write( "    // Set N flag\n")
            f.write(f"    {flag_reg} |= {flags[N]};\n")

            f.write( "    // Update H flag\n")
            f.write(f"    carry ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")

            f.write( "    // Update C flag\n")
            f.write(f"    ({regs_struct[0]} < {regs_struct[i]}) ? ({flag_reg} |= {flags[C]}) : ({flag_reg} &= ~{flags[C]});\n")
            f.write("\n")
            f.write(f"    {regs_struct[0]} = (res & 0xFF);\n")
            f.write("}\n\n")

        f.write("\n")


        #---------------- ADC reg opcode ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- ADC reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void ADC_{regs[i]}(void){{\n")
            f.write(f"    byte c_bit = ({flag_reg} & {flags[C]}) ? 1 : 0;\n")
            f.write(f"    word res = {regs_struct[0]} + {regs_struct[i]} + c_bit;\n")
            f.write(f"    byte carry = ({regs_struct[0]} & 0x0F) + ({regs_struct[i]} & 0x0F) + c_bit;\n")
            f.write("\n")

            f.write( "    // update Z flag\n")
            f.write(f"    (res & 0xFF) ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

            f.write( "    // Reset N flag\n")
            f.write(f"    {flag_reg} &= ~{flags[N]};\n")

            f.write( "    // Update H flag\n")
            f.write(f"    (carry > 0x0F) ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")

            f.write( "    // Update C flag\n")
            f.write(f"    (res > 0xFF) ? ({flag_reg} |= {flags[C]}) : ({flag_reg} &= ~{flags[C]});\n")
            f.write("\n")
            f.write(f"    {regs_struct[0]} = (res & 0xFF);\n")
            f.write("}\n\n")

            f.write("\n")


        #---------------- SBC reg opcode ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- SBC reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void SBC_{regs[i]}(void){{\n")
            f.write(f"    byte c_bit = ({flag_reg} & {flags[C]}) ? 1 : 0;\n")
            f.write(f"    word res = {regs_struct[0]} - {regs_struct[i]} - c_bit;\n")
            f.write(f"    byte half_carry = ({regs_struct[0]} & 0x0F) < (({regs_struct[i]} & 0x0F) + c_bit);\n")
            f.write(f"    byte carry = {regs_struct[0]} < ((word){regs_struct[i]} + (word)c_bit);\n")
            f.write("\n")

            f.write( "    // update Z flag\n")
            f.write(f"    (res & 0xFF) ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

            f.write( "    // Set N flag\n")
            f.write(f"    {flag_reg} |= {flags[N]};\n")

            f.write( "    // Update H flag\n")
            f.write(f"    half_carry ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")

            f.write( "    // Update C flag\n")
            f.write(f"    carry ? ({flag_reg} |= {flags[C]}) : ({flag_reg} &= ~{flags[C]});\n")

            f.write("\n")
            f.write(f"    {regs_struct[0]} = (res & 0xFF);\n")
            f.write("}\n\n")

        f.write("\n")


        #---------------- Indirect opcodes ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- Indirect opcodes ------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        # INC (HL)
        f.write("void INC_HL(void){\n")
        f.write("    byte data = getDataFrom(cpu.HL.all);\n")
        f.write("    byte res = data + 1;\n")
        f.write("    byte carry = (data & 0x0F) + 1;\n")
        f.write("    writeDataTo(cpu.HL.all,res);\n")
        f.write("\n")

        f.write( "    // update Z flag\n")
        f.write(f"    (res & 0xFF) ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

        f.write( "    // Reset N flag\n")
        f.write(f"    {flag_reg} &= ~{flags[N]};\n")

        f.write(f"    // Update H flag\n")
        f.write(f"    (carry > 0x0F) ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")

        f.write("}\n\n")




        # DEC (HL)
        f.write("void DEC_HL(void){\n")
        f.write("    byte data = getDataFrom(cpu.HL.all);\n")
        f.write("    byte res = data - 1;\n")
        f.write("    byte carry = (data & 0x0F);\n")
        f.write("    writeDataTo(cpu.HL.all,res);\n")
        f.write("\n")

        f.write( "    // update Z flag\n")
        f.write(f"    (res & 0xFF) ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")


        f.write( "    // Set N flag\n")
        f.write(f"    {flag_reg} |= {flags[N]};\n")

        f.write(f"    // Update H flag\n")
        f.write(f"    carry ? ({flag_reg} &= ~{flags[H]}) : ({flag_reg} |= {flags[H]});\n")
        f.write("}\n\n")





        # ADD (HL)
        f.write(f"void ADD_HL(void){{\n")
        f.write( "    byte data = getDataFrom(cpu.HL.all);\n")
        f.write(f"    word res = data + {regs_struct[0]};\n")
        f.write(f"    byte carry = ({regs_struct[0]} & 0x0F) + (data & 0x0F);\n")
        f.write("\n")

        f.write( "    // update Z flag\n")
        f.write(f"    (res 0xFF) ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

        f.write( "    // Reset N flag\n")
        f.write(f"    {flag_reg} &= ~{flags[N]};\n")

        f.write( "    // Update H flag\n")
        f.write(f"    (carry > 0x0F) ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")

        f.write( "    // Update C flag\n")
        f.write(f"    (res > 0xFF) ? ({flag_reg} |= {flags[C]}) : ({flag_reg} &= ~{flags[C]});\n")

        f.write("\n")
        f.write(f"    {regs_struct[0]} = (res & 0xFF);\n")
        f.write("}\n\n")






        # SUB (HL)
        f.write(f"void SUB_HL(void){{\n")
        f.write( "    byte data = getDataFrom(cpu.HL.all);\n")
        f.write(f"    word res = {regs_struct[0]} - data;\n")
        f.write(f"    byte carry = ({regs_struct[0]} & 0x0F) < (data & 0x0F);\n")
        f.write("\n")

        f.write( "    // update Z flag\n")
        f.write(f"    (res & 0xFF) ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

        f.write( "    // Set N flag\n")
        f.write(f"    {flag_reg} |= {flags[N]};\n")

        f.write( "    // Update H flag\n")
        f.write(f"    carry ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")

        f.write( "    // Update C flag\n")
        f.write(f"    ({regs_struct[0]} < data) ? ({flag_reg} |= {flags[C]}) : ({flag_reg} &= ~{flags[C]});\n")
        f.write("\n")
        f.write(f"    {regs_struct[0]} = (res & 0xFF);\n")
        f.write("}\n\n")





        # ADC (HL)
        f.write(f"void ADC_HL(void){{\n")
        f.write( "    byte data = getDataFrom(cpu.HL.all);\n")
        f.write(f"    byte c_bit = ({flag_reg} & {flags[C]}) ? 1 : 0;\n")
        f.write(f"    word res = {regs_struct[0]} + data + c_bit;\n")
        f.write(f"    byte carry = ({regs_struct[0]} & 0x0F) + (data & 0x0F) + c_bit;\n")
        f.write("\n")

        f.write( "    // update Z flag\n")
        f.write(f"    (res & 0xFF) ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

        f.write( "    // Reset N flag\n")
        f.write(f"    {flag_reg} &= ~{flags[N]};\n")

        f.write( "    // Update H flag\n")
        f.write(f"    (carry > 0x0F) ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")

        f.write( "    // Update C flag\n")
        f.write(f"    (res > 0xFF) ? ({flag_reg} |= {flags[C]}) : ({flag_reg} &= ~{flags[C]});\n")
        f.write("\n")
        f.write(f"    {regs_struct[0]} = (res & 0xFF);\n")
        f.write("}\n\n")





        # SBC (HL)
        f.write(f"void SBC_HL(void){{\n")
        f.write( "    byte data = getDataFrom(cpu.HL.all);\n")
        f.write(f"    byte c_bit = ({flag_reg} & {flags[C]}) ? 1 : 0;\n")
        f.write(f"    word res = {regs_struct[0]} - data - c_bit;\n")
        f.write(f"    byte half_carry = ({regs_struct[0]} & 0x0F) < ((data & 0x0F) + c_bit);\n")
        f.write(f"    byte carry = {regs_struct[0]} < ((word)data + (word)c_bit);\n")
        f.write("\n")

        f.write( "    // update Z flag\n")
        f.write(f"    (res & 0xFF) ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

        f.write( "    // Set N flag\n")
        f.write(f"    {flag_reg} |= {flags[N]};\n")

        f.write( "    // Update H flag\n")
        f.write(f"    half_carry ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")

        f.write( "    // Update C flag\n")
        f.write(f"    carry ? ({flag_reg} |= {flags[C]}) : ({flag_reg} &= ~{flags[C]});\n")

        f.write("\n")
        f.write(f"    {regs_struct[0]} = (res & 0xFF);\n")
        f.write("}\n\n")



        #---------------- Immediate opcodes ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- Immediate opcodes -----------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        # ADD n
        f.write(f"void ADD_n(void){{\n")
        f.write( "    byte n = getDataFrom(cpu.PC++);\n")
        f.write(f"    word res = {regs_struct[0]} + n;\n")
        f.write(f"    byte carry = ({regs_struct[0]} & 0x0F) + (n & 0x0F);\n")
        f.write("\n")

        f.write( "    // update Z flag\n")
        f.write(f"    (res & 0xFF) ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

        f.write( "    // Reset N flag\n")
        f.write(f"    {flag_reg} &= ~{flags[N]};\n")

        f.write( "    // Update H flag\n")
        f.write(f"    (carry > 0x0F) ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")

        f.write( "    // Update C flag\n")
        f.write(f"    (res > 0xFF) ? ({flag_reg} |= {flags[C]}) : ({flag_reg} &= ~{flags[C]});\n")

        f.write("\n")
        f.write(f"    {regs_struct[0]} = (res & 0xFF);\n")
        f.write("}\n\n")



        # SUB n
        f.write(f"void SUB_n(void){{\n")
        f.write( "    byte n = getDataFrom(cpu.PC++);\n")
        f.write(f"    word res = {regs_struct[0]} - n;\n")
        f.write(f"    byte carry = ({regs_struct[0]} & 0x0F) < (n & 0x0F);\n")
        f.write("\n")

        f.write( "    // update Z flag\n")
        f.write(f"    (res & 0xFF) ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

        f.write( "    // Set N flag\n")
        f.write(f"    {flag_reg} |= {flags[N]};\n")

        f.write( "    // Update H flag\n")
        f.write(f"    carry ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")

        f.write( "    // Update C flag\n")
        f.write(f"    ({regs_struct[0]} < n) ? ({flag_reg} |= {flags[C]}) : ({flag_reg} &= ~{flags[C]});\n")
        f.write("\n")
        f.write(f"    {regs_struct[0]} = (res & 0xFF);\n")
        f.write("}\n\n")




        #ADC n
        f.write(f"void ADC_n(void){{\n")
        f.write( "    byte n = getDataFrom(cpu.PC++);\n")
        f.write(f"    byte c_bit = ({flag_reg} & {flags[C]}) ? 1 : 0;\n")
        f.write(f"    word res = {regs_struct[0]} + n + c_bit;\n")
        f.write(f"    byte carry = ({regs_struct[0]} & 0x0F) + (n & 0x0F) + c_bit;\n")
        f.write("\n")

        f.write( "    // update Z flag\n")
        f.write(f"    (res & 0xFF) ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

        f.write( "    // Reset N flag\n")
        f.write(f"    {flag_reg} &= ~{flags[N]};\n")

        f.write( "    // Update H flag\n")
        f.write(f"    (carry > 0x0F) ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")

        f.write( "    // Update C flag\n")
        f.write(f"    (res > 0xFF) ? ({flag_reg} |= {flags[C]}) : ({flag_reg} &= ~{flags[C]});\n")
        f.write("\n")
        f.write(f"    {regs_struct[0]} = (res & 0xFF);\n")
        f.write("}\n\n")



        # SBC n
        f.write(f"void SBC_n(void){{\n")
        f.write( "    byte n = getDataFrom(cpu.PC++);\n")
        f.write(f"    byte c_bit = ({flag_reg} & {flags[C]}) ? 1 : 0;\n")
        f.write(f"    word res = {regs_struct[0]} - n - c_bit;\n")
        f.write(f"    byte half_carry = ({regs_struct[0]} & 0x0F) < ((n & 0x0F) + c_bit);\n")
        f.write(f"    byte carry = {regs_struct[0]} < ((word)n + (word)c_bit);\n")
        f.write("\n")

        f.write( "    // update Z flag\n")
        f.write(f"    (res & 0xFF) ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

        f.write( "    // Set N flag\n")
        f.write(f"    {flag_reg} |= {flags[N]};\n")

        f.write( "    // Update H flag\n")
        f.write(f"    half_carry ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")

        f.write( "    // Update C flag\n")
        f.write(f"    carry ? ({flag_reg} |= {flags[C]}) : ({flag_reg} &= ~{flags[C]});\n")

        f.write("\n")
        f.write(f"    {regs_struct[0]} = (res & 0xFF);\n")
        f.write("}\n\n")


