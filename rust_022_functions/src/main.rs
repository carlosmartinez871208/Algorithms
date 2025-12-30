/*
** Functions:
** - main: The entry point of the Rust program.
A function in rust is defined using the `fn` keyword followed by the function name and parentheses.
Return type is optional and specified after an arrow `->` if needed.
Syntax: fn function_name(parameters) -> return_type {
    // function body
}
*/

// Function definition
fn KilometersToMiles(km: f64) -> f64 {
    km * 0.621371
}

// Callback function type definition and usage
type ConversionFn = fn(f64) -> f64;

/* 
** Modules:
** A module is a way to organize code into namespaces. Modules are defined using the `mod` keyword.
Syntax: mod module_name {
    // module body
*/
mod conversions {
    // Function inside module
    pub fn FarenheitToCelsius(f: f64) -> f64 {
        (f - 32.0) * 5.0 / 9.0
    }
}

// Two parameter function example (not used in main, but for demonstration)
fn AddNumbers(a: i32, b: i32) -> i32 {
    a + b
}

// Calling by reference example (not used in main, but for demonstration)
fn IncrementByReference(num: &mut i32) {
    *num += 1;
}

// No returning function example (not used in main, but for demonstration)
fn PrintMessage(message: &str) {
    println!("{}", message);
}

// Main function
fn main(){

    let kilometers = 5.0;
    let miles = KilometersToMiles(kilometers);
    println!("{} kilometers is equal to {} miles.", kilometers, miles);
    // Pointer to function
    let convert: fn(f64) -> f64 = KilometersToMiles; // Syntax for function pointer: fn(parameter_types) -> return_type
    println!("Using function pointer: {} kilometers is equal to {} miles.", kilometers, convert(kilometers));
    //Callback function usage
    let callback: ConversionFn = KilometersToMiles;
    println!("Using callback function: {} kilometers is equal to {} miles.", kilometers, callback(kilometers));
    // Using module function
    let fahrenheit = 100.0;
    let celsius = conversions::FarenheitToCelsius(fahrenheit);
    println!("{} degrees Fahrenheit is equal to {} degrees Celsius.", fahrenheit, celsius);
    // Two parameter function usage
    let sum = AddNumbers(10, 20);
    println!("The sum of 10 and 20 is {}.", sum);
    // Calling by reference usage
    let mut number = 5;
    IncrementByReference(&mut number);
    println!("After incrementing by reference, the number is {}.", number);
    // No returning function usage
    PrintMessage("Hello, this is a message from a no-returning function.");
}
