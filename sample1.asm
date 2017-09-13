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
     SET0 ADD1 // use variables for this addition
     SET1 ADD2
     ADD
     STOR RES1
     PRT RES1
     CALL SUB1
     HALT
SUB1 SET0 0x04 // use literals for this addition
     SET1 9
     ADD
     STOR RES2
     PRT RES2
// setup loop; run through 10 times - backwards
     SET0 LOOPSIZE
JB   STOR COUNTER
     PRT COUNTER
     DEC0
     TST
     JNZ JB
     RET
