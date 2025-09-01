/*
In Rust, functions are defined using the fn keyword. Here's a basic overview of how to work with functions in Rust:
*/
// 1. Basic Function:
fn greet(){
    println!("Hello, world!");
}

// 2. Function with Parameters:
fn greet_name(name: &str)
{
    println!("Hello, {}!",name);
}

/*
3. Function with Return Value
Use -> to specify the return type.
The last expression in a function is implicitly returned (no return needed unless early exit).
*/
fn add(a: i32, b: i32) -> i32 {
    a + b // No semicolon means this is the return value
}

// Alternatively, using `return` explicitly:
fn subtract(a: i32, b: i32) -> i32 {
    return a - b; // Semicolon + `return` works too
}

/*
4. Diverging Functions (Never Return)
Functions that never return (e.g., panic or infinite loop) use ! (the "never" type).
*/
fn panic_and_exit() -> ! {
    panic!("This function will never return!");
}

/*
5. Function Pointers
Functions can be passed as arguments using function pointers.
*/
fn apply(func: fn(i32) -> i32, value: i32) -> i32 {
    func(value)
}

fn square(x: i32) -> i32 {
    x * x
}

fn main()
{
    greet();
    greet_name("Ninmah");
    let sum = add(3,5);
    println!("Sum: {}",sum);            // Sum: 8
    let diff = subtract(10,4);
    println!("Difference: {}",diff);    // Difference: 6
    let result = apply(square, 5);
    println!("Result: {}", result); // Result: 25
    /*
    6. Closures (Anonymous Functions)
    Rust also supports closures (lambdas).
    */
    let add_one = |x| x + 1; // Inferred types
    println!("{}", add_one(5)); // Prints "6"
    let add = |a, b| a + b;
    println!("{}", add(3, 7)); // Prints "10"
}