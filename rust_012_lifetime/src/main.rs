// Lifetime annotations in Rust are used to specify how long references are valid. They help the compiler ensure memory safety without needing a garbage collector.

fn main() {
    let r;                // Declare a reference variable `r`
    {
        let x = 5;       // `x` is created in this inner scope
        r = &x;         // `r` borrows `x`
        println!("r: {}", r); // Use `r` while `x` is still valid
    }                   // `x` goes out of scope here, and `r` becomes invalid

    // println!("r: {}", r); // This line would cause a compile-time error because `r` is dangling
}
