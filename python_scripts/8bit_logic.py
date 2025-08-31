import os

regs_byte = [
    "cpu.AF.High", # Reg A
    "cpu.BC.High", # Reg B
    "cpu.BC.Low",  # Reg C
    "cpu.DE.High", # Reg D
    "cpu.DE.Low",  # Reg E
    "cpu.HL.High", # Reg H
    "cpu.HL.Low",  # Reg L
    "getDataFrom(cpu.HL.all)",
    "getDataFrom(cpu.PC++)"

]

regs_struct = [
    "cpu.AF.High", # Reg A
    "cpu.BC.High", # Reg B
    "cpu.BC.Low",  # Reg C
    "cpu.DE.High", # Reg D
    "cpu.DE.Low",  # Reg E
    "cpu.HL.High", # Reg H
    "cpu.HL.Low",  # Reg L
    "getDataFrom(cpu.HL.all)",
    "getDataFrom(cpu.PC++)"
]

regs = ['A','B','C','D','E','H','L',"HL",'n']



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


if __name__ == "__main__":
    # Obtain file path
    dir = os.path.dirname(__file__)

    # Construct absolute paths for output files
    header = os.path.join(dir,"..","cpu","include","8bit_logic.h")
    src    = os.path.join(dir,"..","cpu","src","8bit_logic.c")

    with open(header,"w") as f:
        f.write("#ifndef H_8BIT_LOGIC_H\n")
        f.write("#define H_8BIT_LOGIC_H\n")

        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- AND reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void AND_{regs[i]}(void);\n")

        #---------------- Write "OR reg opcodes" ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- OR reg opcodes --------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void OR_{regs[i]}(void);\n")

        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- XOR reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void XOR_{regs[i]}(void);\n")


        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- CP reg opcodes --------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void CP_{regs[i]}(void);\n")
 
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- the rest opcodes ------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        # CPL
        f.write("void CPL(void);\n")

        f.write("void SCF(void);\n")
        f.write("void CCF(void);\n")
        f.write("void DAA(void);\n")

        f.write("\n\n\n")
        f.write("#endif")

#*************************************************************************************************
    with open(src,"w") as f:
        f.write("#include " + '"' + "8bit_logic.h" + '"' + "\n")
        f.write("#include " + '"' + "memory.h" + '"' + "\n")
        f.write("#include " + '"' + "cpu.h" + '"' + "\n")


        #---------------- Write "AND reg opcodes" ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- AND reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void AND_{regs[i]}(void){{\n")
            if regs[i] != 'n':
                f.write(f"    {regs_byte[0]} &= {regs_byte[i]};\n")
                f.write("\n")

            else:
                f.write(f"    byte n = getDataFrom(cpu.PC++);\n")
                f.write(f"    {regs_byte[0]} &= n;\n")
                f.write("\n")

            f.write( "    // Update Z flag\n")
            f.write(f"    {regs_byte[0]} ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

            f.write( "    // Reset N flag\n")
            f.write(f"    {flag_reg} &= ~{flags[N]};\n")

            f.write( "    // Set H flag\n")
            f.write(f"    {flag_reg} |= {flags[H]};\n")

            f.write( "    // Reset C flag\n")
            f.write(f"    {flag_reg} &= ~{flags[C]};\n")

            f.write("}\n\n")
        f.write("\n")
        

        #---------------- Write "OR reg opcodes" ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- OR reg opcodes --------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void OR_{regs[i]}(void){{\n")

            if regs[i] != 'n':
                f.write(f"    {regs_byte[0]} |= {regs_byte[i]};\n")
                f.write("\n")

            else:
                f.write(f"    byte n = getDataFrom(cpu.PC++);\n")
                f.write(f"    {regs_byte[0]} |= n;\n")
                f.write("\n")

            f.write( "    // Update Z flag\n")
            f.write(f"    {regs_byte[0]} ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

            f.write( "    // Reset N flag\n")
            f.write(f"    {flag_reg} &= ~{flags[N]};\n")

            f.write( "    // Reset H & C flags\n")
            f.write(f"    {flag_reg} &= ~({flags[H]} | {flags[C]});\n")

            f.write("}\n\n")

        f.write("\n")



        #---------------- Write "XOR reg opcodes" ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- XOR reg opcodes -------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void XOR_{regs[i]}(void){{\n")
            if regs[i] != 'n':
                f.write(f"    {regs_byte[0]} ^= {regs_byte[i]};\n")
                f.write("\n")

            else:
                f.write(f"    byte n = getDataFrom(cpu.PC++);\n")
                f.write(f"    {regs_byte[0]} ^= n;\n")
                f.write("\n")

            f.write( "    // Update Z flag\n")
            f.write(f"    {regs_byte[0]} ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

            f.write( "    // Reset N, C & H flags\n")
            f.write(f"    {flag_reg} &= ~({flags[N]} | {flags[C]} | {flags[H]});\n")
            f.write("}\n\n")
        f.write("\n")
        
        #---------------- Write "Compare reg opcodes" ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- CP reg opcodes --------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        for i in range(0,len(regs)):
            f.write(f"void CP_{regs[i]}(void){{\n")

            f.write(f"    byte data = {regs_struct[i]};\n")
            f.write(f"    word res = {regs_struct[0]} - data;\n")
            f.write(f"    byte carry = ({regs_struct[0]} & 0x0F) < (data & 0x0F);\n")

            f.write("\n")

            f.write( "    // update Z flag\n")
            f.write(f"    res ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")

            f.write( "    // Set N flag\n")
            f.write(f"    {flag_reg} |= {flags[N]};\n")

            f.write( "    // Update H flag\n")
            f.write(f"    carry ? ({flag_reg} |= {flags[H]}) : ({flag_reg} &= ~{flags[H]});\n")

            f.write( "    // Update C flag\n")
            f.write(f"    ({regs_struct[0]} < data) ? ({flag_reg} |= {flags[C]}) : ({flag_reg} &= ~{flags[C]});\n")

            f.write("\n")
            f.write("}\n\n")

        f.write("\n")


        #---------------- Write the rest opcodes ----------------
        f.write("/*----------------------------------------------------*/\n")
        f.write("/*---------------- the rest opcodes ------------------*/\n")
        f.write("/*----------------------------------------------------*/\n\n")

        # CPL
        f.write("void CPL(void){\n")
        f.write(f"    {regs_byte[0]} = ~{regs_byte[0]};\n")
        f.write("\n")

        f.write( "    // Set N & H flags\n")
        f.write(f"    {flag_reg} |= ({flags[N]} | {flags[H]}) ;\n")
        f.write("}\n\n")



        # SCF
        f.write("void SCF(void){\n")
        f.write( "    // Set C flag\n")
        f.write(f"    {flag_reg} |= {flags[C]};\n")

        f.write( "    // Reset N & H flags\n")
        f.write(f"    {flag_reg} &= ~({flags[N]} | {flags[H]});\n")
        f.write("}\n\n")




        # CCF
        f.write("void CCF(void){\n")
        f.write( "    // Flip C flag\n")
        f.write(f"    {flag_reg} ^= {flags[C]};\n")

        f.write( "    // Reset N & H flags\n")
        f.write(f"    {flag_reg} &= ~({flags[N]} | {flags[H]});\n")
        f.write("}\n\n")




        # DAA
        f.write("void DAA(void){\n")
        f.write( "    byte adj = 0;\n")
        f.write("\n")

        f.write(f"    if(({flag_reg} & {flags[N]}))  // If N flag is set \n")
        f.write( "    {\n")
        f.write(f"        ({flag_reg} & {flags[H]}) ? (adj += 0x06) : adj;\n")
        f.write(f"        ({flag_reg} & {flags[C]}) ? (adj += 0x60) : adj;\n")
        f.write(f"        {regs_byte[0]} -= adj;\n")
        f.write( "    }\n")
        f.write("\n")


        f.write( "    else  // If N flag is not set\n")
        f.write( "    {\n")
        f.write(f"        (({flag_reg} & {flags[H]}) || (({regs_byte[0]} & 0x0F) > 0x09)) ? (adj+= 0x06) : adj;\n")

        f.write(f"        if(({flag_reg} & {flags[C]}) || ({regs_byte[0]} > 0x99))\n")
        f.write( "        {\n")
        f.write( "            adj += 0x60;\n")
        f.write(f"            {flag_reg} |= {flags[C]};\n")

        f.write( "        }\n")
        f.write("\n")
        f.write(f"        {regs_byte[0]} += adj;\n")
        f.write( "    }\n")
        f.write(f"    {regs_byte[0]} ? ({flag_reg} &= ~{flags[Z]}) : ({flag_reg} |= {flags[Z]});\n")
        f.write(f"    {flag_reg} &= ~{flags[H]};\n")
        f.write("}\n\n")














