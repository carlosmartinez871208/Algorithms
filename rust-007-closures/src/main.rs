use std::thread;
/*
Rust Closures
Closures in Rust are anonymous functions that can capture their environment. They're similar to 
lambdas in other languages and are a powerful feature for writing concise, functional-style code.
*/

/*
Closure Traits
Rust closures implement one or more of these traits automatically:
Fn: Immutably borrows values from the environment
FnMut: Mutably borrows values from the environment
FnOnce: Takes ownership of values (can only be called once)
The compiler infers which traits to implement based on how the closure uses variables from its environment.
Passing Closures as Arguments
You can pass closures to functions using generics and trait bounds:
*/
fn apply<F>(f: F, x: i32) -> i32 
where F: Fn(i32) -> i32 {
    f(x)
}

/*
Storing Closures
To store closures in structs or return them from functions, you often need to use trait objects or boxes:
*/
struct Cacher<T>
where T: Fn(i32) -> i32 {
    calculation: T,
    value: Option<i32>,
}

impl<T> Cacher<T>
where T: Fn(i32) -> i32 {
    fn new(calculation: T) -> Cacher<T> {
        Cacher {
            calculation,
            value: None,
        }
    }
    
    fn value(&mut self, arg: i32) -> i32 {
        match self.value {
            Some(v) => v,
            None => {
                let v = (self.calculation)(arg);
                self.value = Some(v);
                v
            }
        }
    }
}

fn process_data<F>(data: &[i32], callback: F)
where F: Fn(i32) {
    for &item in data {
        callback(item);
    }
}

fn main()
{
    // Basic Syntax:
    let add_one = |x| x + 1;
    println!("{}", add_one(5)); // prints 6
    /*
    Characteristics of Rust Closures
    Type Inference: Closure parameter and return types are usually inferred
    Flexible Syntax: Can be written in different ways:
    */
    //let add = |a, b| a + b;           // simple
    let add = |a: i32, b: i32| a + b; // with explicit types
    //let add = |a, b| -> i32 { a + b }; // with block and return type
    /*
    Environment Capture: Can capture variables from their surrounding scope
    Capturing the Environment
    Closures can capture variables in three ways (corresponding to the three ways a function can take a parameter):
    */
    let x = 4;
    // By reference (Fn)
    //let equal_to_x = |z| z == x;
    // By mutable reference (FnMut)
    //let mut y = 0;
    //let mut add_to_y = |z| y += z;
    // By value (FnOnce)
    //let consume_x = move |z| z == x;

    let double = |x| x * 2;
    println!("{}", apply(double, 5)); // prints 10

    /* Common use cases */
    // Iterator adapters:
    let numbers = vec![1, 2, 3];
    let doubled: Vec<_> = numbers.iter().map(|x| x * 2).collect();

    // Thread spawning:
    let message = "Hello".to_string();
    thread::spawn(move || {
        println!("{}", message);
    }).join().unwrap();

    // Callback functions
    process_data(&[1, 2, 3], |x| println!("Processing {}", x));
}