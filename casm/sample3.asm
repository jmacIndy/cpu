// this is sample input for assembler
.CONSTANT
     ADD1 2
     ADD2 0x07
     LOOPSIZE 0x0A
.DATA
     RES1
     RES2
     COUNTER

.CODE
     LD R0,ADD1 // use variables for this addition
     LD R1,ADD2
     ADD
     STOR RES1
     PRT RES1
     CALL SUB1
     HALT
SUB1 LD R0,0x04 // use literals for this addition
     LD R1,9
     ADD
     STOR RES2
     PRT RES2
// setup loop; run through 10 times - backwards
     LD R0,LOOPSIZE
JB   STOR COUNTER
     PRT COUNTER
     DEC R0
     TST
     JNZ JB
     RET
