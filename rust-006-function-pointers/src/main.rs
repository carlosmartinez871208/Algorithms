/*
In Rust, function pointers allow you to store and pass functions as values. They are useful 
for scenarios where you want to dynamically select or pass a function at runtime.
1. Basic Function Pointer
A function pointer type is written as fn(arg_types) -> return_type.
*/
fn add(a: i32, b: i32) -> i32 {
    a + b
}

fn subtract(a: i32, b: i32) -> i32 {
    a - b
}

/*
2. Passing Function Pointers as Arguments
You can pass functions as arguments to other functions.
Example:
*/
fn apply(op: fn(i32, i32) -> i32, x: i32, y: i32) -> i32 {
    op(x, y)
}

fn multiply(a: i32, b: i32) -> i32 {
    a * b
}

/*
3. Returning Function Pointers
You can return function pointers from functions.
Example:
*/
fn add_64(a: i64, b: i64) -> Option<i64> { Some(a + b) }
fn subtract_64(a: i64, b: i64) -> Option<i64> { Some(a - b) }

fn get_math_op(op: &str) -> fn(i64, i64) -> Option<i64> {
    match op {
        "add" => add_64,
        "subtract" => subtract_64,
        _ => |_, _| None,
    }
}

fn main()
{
    let operation: fn(i32, i32) -> i32 = add;
    println!("5 + 3 = {}", operation(5, 3));

    let operation = subtract; // Type inference works here
    println!("5 - 3 = {}", operation(5, 3));

    let result = apply(multiply, 4, 5);
    println!("4 * 5 = {}", result); // Outputs "4 * 5 = 20"

    let op = get_math_op("add");
    println!("{:?}", op(2, 3)); // Some(5)

}