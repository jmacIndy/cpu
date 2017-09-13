//#define MAX_FILENAME_SIZE 50
//#define MAX_INPUT_SIZE 500

#![allow(dead_code)]

use std::io::prelude::*;
use std::io;

const MEMORY_SIZE : usize = 0xFF;

fn display_menu() -> char {

   let mut input = String::new();

   println!("Menu (my CPU)");
   println!("-------------");
   println!("1. Reset CPU");
   println!("2. Clear Memory");
   println!("3. Dump the CPU");
   println!("4. Dump the Memory");
   println!("5. Dump the Heap");
   println!("6. Dump the Stack");
   println!("7. Run the CPU");
   println!("8. Load program from file");
   println!("X. Exit the CPU");
   print!("   Your choice===>");

   io::stdout().flush(); // print! does not flush output buffer

   match io::stdin().read_line(&mut input) {
      Ok(n) => (),
      Err(error) => println!("error: {}", error),
   }
   let choice = input.chars().nth(0).unwrap();

   println!("");

   return choice;
}

fn load_program(memory: &mut [u8]) {

   write_memory(&memory[0], 0x01);
   //memory[0] = 0x01;
//
//   char inName[MAX_FILENAME_SIZE];
//
//   printf("\nEnter input file name ===> ");
//   fgets(inName, sizeof(inName), stdin);
//   inName[strlen(inName) - 1] = '\0'; /* remove training \n */
//
//   FILE *inFile = fopen(inName, "r");
//   if (inFile == 0) {
//      printf("ERROR: Could not open file %s\n", inName);
//      return;
//   }
//
//   char *inputLine;
//   size_t lineSize = MAX_INPUT_SIZE;
//
//   inputLine = (char *) malloc(lineSize + 1);
//
//   if (getline(&inputLine, &lineSize, inFile) == -1) {
//      printf("ERROR: File is empty. Nothing to load.\n");
//      return;
//   }
//
//   int filePointer = 3; /* skip over CPU text */
//   byte memoryPointer = 0x00;
//   for (int i = filePointer; i < strlen(inputLine); i += 2) {
//      char inData[5];
//      strcpy(inData, "0x");
//      strncat(inData, inputLine + i, 2);
//      writeMemory(memoryPointer, (int) strtol(inData, NULL, 0));
//      memoryPointer++;
//   }
//
//   free(inputLine);
//
//   fclose(inFile);

}

fn initialize_cpu() {
}

fn dump_cpu() {
}

fn dump_heap() {
}

fn dump_stack() {
}

fn is_halted() -> bool {
   return false;
}

fn run() {
}

fn clear_heap() {
}

fn clear_stack() {
}

fn clear_memory(memory: &mut [u8]) {

   for i in 0..MEMORY_SIZE {
      memory[i] = 0x00;
   }
}

fn write_memory(memory: &[u8], value: u8) {

   if address < MEMORY_SIZE
   {
      memory[address] = value;
   }
   else
   {
      println!("ERROR: Cannot write above maximum memory!");
   }

}

fn read_memory(memory: &[u8], address: usize) -> u8 {

   if address < MEMORY_SIZE
   {
      return memory[address];
   }
   else
   {
      println!("ERROR: Cannot read above maximum memory!");
   }

   return 0;

}

fn dump_memory(memory: &[u8]) {

   let i: u8;
   let mut j = 0x00;

   let mut address_counter : u8 = 0x00;

   println!("");
   println!("Memory Contents:");
   print!("----------------");

   j = 0x00;
   for i in 0..MEMORY_SIZE {
      if (j % 0x0F) == 0x00 {
         println!("");
         print!("Address({}) ", address_counter);
         address_counter += 0x0F;
      }
      print!("{} ", memory[i]);
      j = j + 1;
   }

   println!("");
   println!("");
}

fn main() {

   let mut menu_choice;

   let mut exit_flag = false;

   let mut memory:[u8;MEMORY_SIZE] = [0;MEMORY_SIZE];

   clear_memory(&mut memory);
   clear_heap();
   initialize_cpu();
   clear_stack();

   println!("=======================");
   println!("== Welcome to my CPU ==");
   println!("=======================");
   println!("");

   while !exit_flag {

      menu_choice = display_menu();

      match menu_choice {
         '1' => initialize_cpu(),
         '2' => clear_memory(&mut memory),
         '3' => dump_cpu(),
         '4' => dump_memory(&memory),
         '5' => dump_heap(),
         '6' => dump_stack(),
         '7' => { if is_halted() {
                     println!("ERROR: CPU is HALTED! Cannot run!");
                  } else {
                     run()
                  }
                },
         '8' => load_program(&mut memory),
         'X' | 'x' => exit_flag = true,
         _ => println!("ERROR: Bad selection! Try again."),
      }
   }
}
