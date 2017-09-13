use std::io::prelude::*;
use std::io;

const MEMORY_SIZE : usize = 0xFF;

fn display_menu() -> char {

    let mut input = String::new();

    println!("Menu");
    println!("---------------------------");
    println!("1. Reset the CPU");
    println!("2. Clear the memory");
    println!("3. Dump the CPU");
    println!("4. Dump the memory");
    println!("5. Dump the heap");
    println!("6. Dump the stack");
    println!("7. Run the CPU");
    println!("8. Load program into memory");
    println!("X. Exit the CPU");
    print!("   Your choice===> ");

    match io::stdout().flush() { // print! does not flush output buffer
        Ok(_) => (),
        Err(error) => println!("flush didn't work: {}", error),
    }

    match io::stdin().read_line(&mut input) {
        Ok(_) => (),
        Err(error) => println!("ERROR: Invalid input: {}", error),
     }

    input.chars().nth(0).unwrap()
}

fn reset_cpu() {
    println!("in reset_cpu");
}

fn clear_memory(memory: &mut [u8]) {

    for i in 0 ..MEMORY_SIZE {
        memory[i] = 0x00;
    }
}

fn dump_cpu() {
    println!("in dump_cpu");
}

fn dump_memory(memory: &mut [u8]) {

    println!("\nMemory Contents:");
    print!("----------------");

    let mut address_counter : u8 = 0x00;

    let mut j = 0x00;

    for i in 0..MEMORY_SIZE {

        if (j % 0x0F) == 0x00 {

            print!("\nAddress({:X}) ", address_counter);
            address_counter += 0x0F;
        }

        print!("{:X} ", memory[i]);
        j += 1;
    }

    println!("\n");
}

fn dump_heap() {
    println!("in dump_heap");
}

fn dump_stack() {
    println!("in dump_stack");
}

fn run_cpu() {
    println!("in run_cpu");
}

fn load_program() {
    println!("in load_program");
}

fn main() {

    let mut memory:[u8;MEMORY_SIZE] = [0;MEMORY_SIZE];

    println!("=========================");
    println!("=== Welcome to my CPU ===");
    println!("=========================\n");

    clear_memory(&mut memory);

    loop {

        match display_menu() {
           '1' => reset_cpu(),
           '2' => clear_memory(&mut memory),
           '3' => dump_cpu(),
           '4' => dump_memory(&mut memory),
           '5' => dump_heap(),
           '6' => dump_stack(),
           '7' => run_cpu(),
           '8' => load_program(),
           'X' | 'x' => break,
           _ => println!("ERROR: Bad selection! Try again!"),
        }
    }
}
