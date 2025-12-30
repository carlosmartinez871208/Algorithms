// Traits and types from the standard library are imported by default in Rust.
// a trait defines shared behavior that types can implement.

use core::fmt;

struct MyStruct {
    value: i32,
}

impl MyStruct {
    fn new(value: i32) -> Self {
        MyStruct { value }
    }
}

trait MyTrait {
    fn do_something(&self);
}

impl MyTrait for MyStruct {
    fn do_something(&self) {
        println!("Doing something with value: {}", self.value);
    }
}

struct User{
    name: String,
    age: u8,
}

// Attribute Derive
// Trait derive
// The #[derive] attribute automatically implements certain traits for a struct or enum.
#[derive(Debug, Clone)]
struct Product {
    id: u32,
    name: String,
    price: f64,
}

// Trait Display
// The Display trait allows for user-friendly string representations of types.
impl fmt::Display for User {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "User: {}, Age: {}", self.name, self.age)
    }
}

// Trait default
impl Default for User {
    fn default() -> Self {
        User {
            name: String::from("Default User"),
            age: 0,
        }
    }
}

// Trait enum
enum Status {
    Active,
    Inactive,
    Pending,
}

impl fmt::Display for Status {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Status::Active => write!(f, "Active"),
            Status::Inactive => write!(f, "Inactive"),
            Status::Pending => write!(f, "Pending"),
        }
    }
}

fn main() {
    let my_struct = MyStruct::new(10);
    my_struct.do_something();
    let user = User {
        name: String::from("Ninmah"),
        age: 5,
    };
    println!("User: {}, Age: {}", user.name, user.age);

    let product = Product {
        id: 1,
        name: String::from("Laptop"),
        price: 999.99,
    };
    println!("Product: {:?}", product);
    println!("{}", user);
    let default_user = User::default();
    println!("Default User: {}, Age: {}", default_user.name, default_user.age);
    let status = Status::Active;
    println!("Status: {}", status);
    //iterators
    let numbers = vec![1, 2, 3, 4, 5];
    let sum: i32 = numbers.iter().sum();
    println!("Sum of numbers: {}", sum);
    // Closure is a function-like construct that can capture variables from its surrounding scope.
    let add = |a: i32, b: i32| -> i32 { a + b };
    let result = add(5, 10);
    println!("Result of closure add: {}", result);
}
