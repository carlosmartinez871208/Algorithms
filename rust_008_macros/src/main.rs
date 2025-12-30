// Macros
// A macro is a way of writing code that writes other code, which is known as metaprogramming.
// Macros are useful for reducing code repetition and can be used to create domain-specific languages within Rust.
// They are defined using the macro_rules! keyword or the newer procedural macros.
// Syntax:


macro_rules! say_hello {
    () => {
        println!("Hello from the macro!");
    };
}

macro_rules! macro_sum {
    ($a:expr, $b:expr) => {
        {
            let sum = $a + $b;
            println!("The sum of {} and {} is {}", $a, $b, sum);
        }
    };
}

fn main() {
    say_hello!();
    macro_sum!(5, 10);
}
// Example Usage:
// say_hello!(); // This will print "Hello from the macro!"
// macro_sum!(5, 10); // This will print "The sum of 5 and 10 is 15"// macro_rules! macro_name {
//     (pattern) => {
//         // code to be generated
//     };