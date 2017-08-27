# Instructions
Mnemonic | Operand | OpCode | Description
HALT||0x00|Halt the CPU
LDR0|<value>|0x01|Set register 0 = value
LDR1|<value>|0x02|Set register 1 = value
ADD||0x03|Set register 0 = register 0 + register 1
STOR|<address>|0x04|Store register 0 on heap at <address>
PRT|<address>|0x05|Print contents of heap at <address>
BEEP||0x06|Print BEEP to the screen (USELESS)
MULT||0x07|Set register 0 = register 0 * register 1
DIV|| 0x08|Set register 0 = register 0 / register 1
SUB||0x09|Set register 0 = register 0 - register 1
JEQ|<address>|0x0A|Jump to <address> if R0 and R1 are equal
JNE|<address>|0x0B|Jump to <address> if R0 and R1 are NOT equal
JLT|<address>|0x0C|Jump to <address> if R0 < R1
JGT|<address>|0x0D|Jump to <address> if R0 > R1
CALL|<address>|0x0E|Jump to subroutine at <address>
RET||0x0F|Return from subroutine to statement after CALL
INT|<value>|0x10|Handle interrupts
CMP||0x11|Compare values
JNZ|<address>|0x12|Jump to <address> if R0 is NOT zero
JMP|<address>|0x13|Unconditional jump to <address>
JZ|<address>|0x14|Jump to <address> if R0 is zero
INC0||0x15|Increment register 0 by 1
INC1||0x16|Increment register 1 by 1
DEC0||0x17|Decrement register 0 by 1
DEC1||0x18|Decrement register 1 by 1


# Comments
any line that starts with //
or // til end of line

*** any line can be blank ***

# Directives
.CODE - starts code section
.VARS - starts a section of variables
      - followed by: <label> <value>
      - continues until .CODE directive found

Any <value> in code:
	=<number>
	=X<hex number>
        <label>

# Sample Code
.DATA
   addop1 =0X02
   addop2 =0X07
   addresult1 =0
   addop3 =X04
   addop4 =X09
   addresult =0

.CODE
   LDR0 addop1
   LDR1 addop2 
   ADD
   STOR addresult1
   PRT addresult1
   CALL ADDIT
   BEEP
   HALT
ADDIT LDR0 addop3
   LDR1 addop4
   ADD
   STOR addresult2
   PRT addresult2
   RET
