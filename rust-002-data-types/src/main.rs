/*
In Rust, data types are categorized into scalar and compound types. Rust is statically typed, 
meaning the compiler must know the types of all variables at compile time, but it can often 
infer them.
*/
fn main()
{
    /*
    1. Scalar Types (Single Value)
    Represent a single value. There are 4 primary scalar types:
    A. Integers
    Signed integers: i8, i16, i32 (default), i64, i128, isize (pointer-sized).
    Unsigned integers: u8, u16, u32, u64, u128, usize (pointer-sized).
    */
    let x: i32 = 42; // Explicit type
    let y = -10;     // Inferred as i32
    /*
    B. Floating-Point Numbers
    f32 (single precision), f64 (default, double precision).
    Example:
    */
    let pi: f64 = 3.14159;
    /*
    C. Booleans (bool)
    Either true or false.
    Example:
    */
    let is_active: bool = true;
    /*
    D. Characters (char)
    Represents a Unicode scalar value (4 bytes).
    Example:
    */
    let emoji = '😊';
    /*
    2. Compound Types (Multiple Values)
    Group multiple values into one type.
    A. Tuples
    Fixed-length, heterogeneous collections.
    Example:
    */
    let tuple: (i32, f64, char) = (42, 3.14, 'R');
    let (x, y, z) = tuple; // Destructuring
    println!("{}", tuple.0); // Access by index → "42"
    /*
    B. Arrays
    fixed-length, homogeneous collections.
    */
    let arr = [1, 2, 3];                            // Type inferred as [i32; 3]
    let first = arr[0];                             // Access by index → "1"
    let fixed_size: [u8;5] = [0;5];                 // [0,0,0,0,0]
    /*
    3. Other Important Types
    A. String Types
    String Slice (&str): Immutable reference to a string.
    Owned String (String): Growable heap-allocated string.
    */
    let s1: &str = "Hello";       // String slice
    let s2: String = s1.to_string(); // Owned String
    /*
    B. Custom Types
    Defined using structs or enums.
    */
    struct Person {
        name: String,
        age: u8,
    }

    enum Result<T,E> {   // Generic enum (like Option/Result)
        Ok(T),
        Err(E),
    }
    /*
    4. Type Inference & Annotation
    Rust can often infer types but allows explicit annotation.
    */
    let x = "Rust";      // Inferred as &str  
    let y: u8 = b'A';    // Byte literal → u8  
}