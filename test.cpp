#include "Cpu.h"
#include "Memory.h"
#include "Heap.h"

int main(void)
{

   Cpu cpu;
   Memory memory;
   Heap heap;

   cpu.setSigning();
   cpu.setOverflow();

   cpu.dump();
   memory.dump();
   heap.dump();

   cpu.resetSigning();
   cpu.resetOverflow();

   memory.write(0x00, 0x01); // LDR0 0x02
   memory.write(0x01, 0x02); 
   memory.write(0x02, 0x02); // LDR1 0x07
   memory.write(0x03, 0x07);
   memory.write(0x04, 0x03); // ADD
   memory.write(0x05, 0x04); // STOR 0x00
   memory.write(0x06, 0x00);
   memory.write(0x07, 0x05); // PRT 0x00
   memory.write(0x08, 0x00);
   memory.write(0x09, 0x0E); // CALL 0x0D
   memory.write(0x0A, 0x0D);
   memory.write(0x0B, 0x06); // BEEP
   memory.write(0x0C, 0x00); // HALT
   memory.write(0x0D, 0x01); // LDR0 0x04
   memory.write(0x0E, 0x04);
   memory.write(0x0F, 0x02); // LDR1 0x09
   memory.write(0x10, 0x09);
   memory.write(0x11, 0x03); // ADD
   memory.write(0x12, 0x04); // STOR 0x01
   memory.write(0x13, 0x01);
   memory.write(0x14, 0x05); // PRT 0x01
   memory.write(0x15, 0x01);
   memory.write(0x16, 0x0F); // RET

   cpu.run(memory, heap);

   cpu.dump();
   memory.dump();
   heap.dump();

   return 0;
}
