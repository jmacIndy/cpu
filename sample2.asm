// this is sample input for assembler
.CODE
     SET0 0x01
     SET1 0x03
     INT 0x02 // interrupt - print 03 to screen
     SET0 0x02
     SET1 0x43
     INT 0x02 // interrupt - print 'C' to screen
     HALT
