use std::io::Write;

fn main() {
    print!("Hello, ");
    std::io::stdout().flush().unwrap();
    eprintln!("An error occurred!");
    let name = "Carlos";
    let age: u32 = 38;
    let message = format!("My name is {} and I am {} years old.", name, age);
    println!("{}", message);
    println!("Hello, world!");
}
