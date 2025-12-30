
fn main() {
    let name = "Ninmah";
    let age: u8 = 5;
    println!("Hello, {}! You are {} years old.", name, age);
    let msg = format!("Welcome to Rust programming, {}!", name);
    let formated_msg = format!("{user_name} You are {user_age} years old.", user_name=name, user_age=age);
    let formated_msg_new = format!(
        "{user_name} You are {user_age} years old.",
        user_name=name,
        user_age=age    
    );
    println!("{}", msg);
    println!("{}", formated_msg);
    println!("{formated_msg_new}");
    for i in 1..=5 {
        println!("Iteration number: {}", i);
    }
    let pi = std::f64::consts::PI;
    println!("The value of pi is approximately {:.8}", pi);
    println!("The value of pi is approximately {:>10.4}", pi);
    let number = 42;
    println!("The number is {:0>5}", number);
    println!("The number is {:x}", number);
    println!("The number is {:X}", number);
    println!("The number is {:#x}", number);
    println!("The number is {:#X}", number);
    println!("The number is {:b}", number);
    println!("The number is {:#b}", number);
    println!(r"user\path\to\file.txt" ); //Using raw string literal
    println!(r#"She said, "Hello, World!""# ); //Using raw string literal with quotes
}
