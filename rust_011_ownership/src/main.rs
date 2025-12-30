// Ownership and Borrowing in Rust
// This program demonstrates the basic concepts of ownership and borrowing in Rust.
// It shows how variables own data, how ownership can be transferred, and how borrowing works.

fn main() {
    // Ownership example
    let s1 = String::from("hello"); // s1 owns the String data
    let s2 = s1; // Ownership of the data is moved from s1 to s2
    // println!("{}", s1); // This would cause a compile-time error because s1 is no longer valid

    println!("s2: {}", s2); // s2 is valid and owns the data

    // Borrowing example
    let s3 = String::from("world");
    let len = calculate_length(&s3); // We borrow s3 by passing a reference
    println!("The length of '{}' is {}.", s3, len); // s3 is still valid here

    // Mutable borrowing example
    let mut s4 = String::from("hello");
    change(&mut s4); // We borrow s4 mutably
    println!("s4 after change: {}", s4); // s4 is modified
}

fn calculate_length(s: &String) -> usize {
    s.len()
}

fn change(s: &mut String) {
    s.push_str(", world");
}