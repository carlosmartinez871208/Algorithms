use std::fs;
use std::io;
use std::env;
/*
Rust Input and Output (I/O)
Rust provides several ways to handle input and output operations through its standard library. 
Here are the main approaches:
*/
// Reading from a file:
fn read_file() -> io::Result<String> {
    fs::read_to_string("example.txt")
}

// Writing to a file:
fn write_file(content: &str) -> io::Result<()> {
    fs::write("output.txt", content)
}

fn main()
{
    // Print to stdout with newline
    println!("Hello, world!");
    // Print without newline
    print!("This stays on the same line");
    // Formatting output
    let name = "Alice";
    let age = 30;
    println!("Name: {}, Age: {}", name, age);
    // Debug print with {:?}
    let numbers = vec![1, 2, 3];
    println!("Debug view: {:?}", numbers);

    //Basic input
    println!("Enter your name:");
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");
    // Trim whitespace (including newline) from input
    let name = input.trim();
    println!("Hello, {}!", name);

    // Reading from a file
    match read_file() {
        Ok(content) => println!("File content:\n{}", content),
        Err(e) => eprintln!("Error reading file: {}", e),
    }

    // Writing to a file:
    let content = "This will be written to the file";
    if let Err(e) = write_file(content) {
        eprintln!("Error writing file: {}", e);
        return;
    }
    println!("File written successfully");

    // Collect all arguments into a vector
    let args: Vec<String> = env::args().collect();
    // First argument is the program name
    println!("Program name: {}", args[0]);
    // Subsequent arguments are user-provided
    if args.len() > 1 {
        println!("Arguments:");
        for arg in &args[1..] {
            println!("- {}", arg);
        }
        // Access specific argument by index (be careful with bounds)
        if args.len() > 2 {
            println!("\nSecond argument is: {}", args[2]);
        }
        // Alternatively use get()
        match args.get(3) {
            Some(value) => println!("\nThird argument is: {}", value),
            None => println!("\nNo third argument provided"),
        }
        // Or using if-let syntax:
        if let Some(value) = args.get(4) {
            println!("\nFourth argument is: {}", value);
        } else {
            println!("\nNo fourth argument provided");
        }
        // Checking for specific flags/options:
        if args.contains(&"--help".to_string()) || args.contains(&"-h".to_string()) { 
            println!("Help printing");
           return;
        } 
        // Parsing arguments as different types:
        if args.len() > 1 { 
            match args[1].parse::<i32>() { 
                Ok(n) => { /* do something with integer n */ }, 
                Err(_) => eprintln!("First argument must be an integer"), 
            } 
        } 
        // Using iterator methods:
        for arg in env::args().skip(1).filter(|a| !a.starts_with('-')) { 
           println!("{}",arg);
        }
    }
}