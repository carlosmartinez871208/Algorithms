/*
** Rust numerical types:
Types        Size (bits)    Range
i8           8              -128 to 127
u8           8              0 to 255
i16          16             -32,768 to 32,767
u16          16             0 to 65,535
i32          32             -2,147,483,648 to 2,147,483,647
u32          32             0 to 4,294,967,295
i64          64             -9,223,372,036,854,
u64          64             0 to 18,446,744,073,709,551,615,615
i128         128            -170,141,183,460,469,231,731,687,303,715,884,105,728 to 170,141,183,460,469,231,731,687,303,715,884,105,727
u128         128            0 to 340,282,366,920,938,463,463,374,607,431,768,211,455
isize       architecture-dependent  -2^(n-1) to 2^(n-1)-1
usize       architecture-dependent  0 to 2^n-1
** Note: 'n' is 32 on 32-bit systems and 64 on 64-bit systems.
f32          32             Approx. ±1.5 x 10^-45 to ±3.4 x 10^38 (6-7 decimal digits precision)
f64          64             Approx. ±5.0 x 10^-324 to ±1.7 x 10^308 (15-16 decimal digits precision)
*/

/*
** Char type:
- Represents a single Unicode scalar value (USV).
- Size: 4 bytes (32 bits).
- Example: let letter: char = 'A';
- Scalar values include letters, digits, symbols, and emojis. 
- Range: U+0000 to U+D7FF and U+E000 to U+10FFFF.
*/

/*
** boolean type:
- Represents a value that can be either true or false.
- Size: 1 byte (8 bits).
- Example: let is_active: bool = true;
- Commonly used for conditional statements and control flow.
*/

/*
** Traits:
- A trait is a collection of methods defined for an unknown type: Self.
- By implementing a trait, we can use its methods for different types.
- Example: The std::fmt::Display trait allows types to be formatted as strings.
*/

/*
** Arrays
- Fixed-size collections of elements of the same type.
- Declared using square brackets, e.g., let arr: [i32; 5] = [1, 2, 3, 4, 5];
- Accessed using indices, e.g., arr[0] for the first element.
- Size must be known at compile time.
*/

/*
** Vectors
- Dynamic-size collections of elements of the same type.
- Declared using the Vec<T> type, e.g., let vec: Vec<i32> = Vec::new();
- Elements can be added or removed at runtime.
- Accessed using indices, e.g., vec[0] for the first element.
*/

fn main() {
    let x: i8 = -100; //let is used to declare variables, variables by default are immutable (cannot be changed once set).
    let y: u32 = 3000000000; // Always iniotialize variables with a value.
    let z: f64 = 3.141592653589793;
    let sum: u32 = y + 100; // Example of addition with unsigned integer
    println!("Sum: {}", sum);
    println!("Byte: {}, Unsigned Int: {}, Float: {}", x, y, z);
    //sum = 500; //This will cause a compile-time error because 'sum' is immutable.
    let subtraction: i8 = (x - (z as i8)) as i8; // Example of subtraction with type casting
    let mut mutable_var: i16 = 200; // 'mut' keyword makes the variable mutable
    mutable_var += 50; // Now we can change the value
    println!("Mutable Variable: {}", mutable_var);
    println!("Subtraction: {}", subtraction);
    // Demonstrating floating-point precision
    let precise_float: f64 = 0.1 + 0.2;
    println!("Precise Float (0.1 + 0.2): {}", precise_float);
    // Traits demonstration
    let max_i8 = std::i8::MAX; // A trait is a collection of methods defined for an unknown type: Self.
    let min_u32 = std::u32::MIN; // By implementing a trait, we can use its methods for different types.
    println!("Max i8: {}, Min u32: {}", max_i8, min_u32);
    // Suffixes demonstration
    let large_number = 1_000_000u64; // Using suffix to define a u64 type
    println!("Large Number with Suffix: {}", large_number);
    // Underscores in numeric literals for readability
    let readable_number = 1_234_567.89_f32;
    println!("Readable Number: {}", readable_number);
    // Storing ASCII values
    let ascii_a: u8 = b'A'; // 'b' prefix indicates a byte
    println!("ASCII value of 'A': {}", ascii_a);
    // Char type demonstration
    let letter: char = 'A';
    println!("Character: {}", letter);
    let emoji: char = '😊';
    println!("Emoji: {}", emoji);
    // Unicode scalar value range demonstration
    let unicode_char: char = '\u{1F600}'; // Unicode scalar value, syntax: \u{XXXX}
    println!("Unicode Character: {}", unicode_char);
    let tm = '\u{2122}'; // Trademark symbol
    println!("Trademark Symbol: {}", tm);
    // Boolean type demonstration
    let is_active: bool = true;
    let is_inactive: bool = false;
    println!("Is Active: {}, Is Inactive: {}", is_active, is_inactive);
    // Arrays demonstration
    let arr: [i32; 5] = [1, 2, 3, 4, 5];
    println!("First element of array: {}", arr[0]);
    let arr_char: [char; 3] = ['a', 'b', 'c'];
    println!("Second element of char array: {}", arr_char[1]);
    // "{:?}" is used to print arrays and vectors for debugging purposes
    println!("Array: {:?}", arr);
    println!("Char Array: {:?}", arr_char);
    // "{:#?}" is used for pretty-printing arrays and vectors
    println!("Pretty Char Array: {:#?}", arr_char);
    // Repeat expression to create an array
    let repeated_arr: [i32; 4] = [0; 4];
    println!("Repeated Array: {:?}", repeated_arr);
    // Vectors demonstration
    let mut vec: Vec<i32> = Vec::new();
    vec.push(10);
    vec.push(20);
    vec.push(30);
    println!("First element of vector: {}", vec[0]);
}
