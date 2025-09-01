/*
n Rust, variables are immutable by default, meaning their values cannot be changed after assignment. 
However, you can explicitly declare mutable variables when needed. Here’s a breakdown of Rust variables:
*/
fn main()
{
    /*
    1. Immutable Variables (Default)
    Once assigned, the value cannot be changed.
    Declared using let.
    */
    let x = 5;
    // x = 6; // Error: Cannot assign to immutable variable
    println!("{}",x);
    /*
    2. Mutable Variables
    Declared with let mut to allow changes.
    */
    let mut y = 10;
    y = 20; // Allowed
    println!("{}",y);
    /*
    3. Constants
    Always immutable and must have an explicit type annotation.
    Declared with const (evaluated at compile time) or static (has a fixed memory address).
    */
    const PI: f64 = 3.14159;
    static MAX_POINTS: u32 = 100_000;
    println!("{},{}",PI,MAX_POINTS);
    /*
    4. Shadowing
    Reusing the same variable name with let, creating a new binding.
    */
    let z = 5;
    let z = z + 1; // Shadowing: New variable `z` (value: 6)
    println!("{}",z);
    /*
    Key Differences:
    Feature	        Immutable (let)     Mutable (let mut)   Shadowing (let again)
    Reassignment    No                  Yes	                Creates a new binding
    Type Change     No                  No	                Yes (if desired)
    */
    let a = 1;       // Immutable
    let mut b = 2;    // Mutable
    const C: i32 = 3; // Constant
    println!("{}",a);
    println!("{}",b);
    println!("{}",C);

    // b can be changed:
    b += 1;
    println!("{}",b);

    // Shadowing:
    let a = "hello"; // New binding (type changed from `i32` to `&str`)
    println!("{}",a);
    /*
    Why Immutability by Default?
    Safety: Prevents accidental modifications.
    Concurrency: Immutable data is thread-safe.
    To make a variable mutable, explicitly use mut. Use shadowing when you need to 
    reuse a name while changing its type or value logically.
    */
}