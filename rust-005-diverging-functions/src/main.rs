use std::process;
/*
In Rust, diverging functions are functions that never return to the caller. Instead, 
they diverge (i.e., they terminate the program, loop indefinitely, or otherwise prevent 
returning a value). These functions are marked with the ! return type, known as the never type.

Key Characteristics of Diverging Functions:
Return Type !: The ! type indicates that the function never returns normally.
No Normal Return: The function either panics, loops forever, or exits the process.
Compatible with Any Type: Since diverging functions never return, their "return value" 
can be coerced into any other type.
Common Use Cases:
*/
// Panic handling:
fn panic_example() -> ! {
    panic!("This function will never return!");
}

// Infinite loops:
fn infinite_loop() -> ! {
    loop {
        println!("This will run forever!");
    }
}

// Exit the process:
fn exit_program() -> ! {
    process::exit(1);
}

/*
Why Use !?
The ! type helps Rust's type system reason about unreachable code.
It allows diverging functions to be used in places where any type is expected (because they never actually produce a value).
Example in Control Flow:
*/
fn maybe_diverges(should_panic: bool) -> &'static str {
    if should_panic {
        /*
        Here, panic!() is a diverging macro (returns !), so it satisfies the function's 
        return type even though it doesn’t actually return.
        */
        panic!("Diverging!");
    } else {
        "Returned normally"
    }
}

fn main()
{
    let ret_string: String = maybe_diverges(false).to_string();
    println!("{}",ret_string);
}