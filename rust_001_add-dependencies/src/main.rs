/* 
   This is the main entry point for the Rust application.
   It currently prints "Hello, world!" to the console.
    Go to crates.io to add dependencies to this project.
   */

/* En Rust las variables no pueden ser globales */
/* Se pueden usar constantes globales */
const MIN_POINTS: u32 = 10;

fn main() {
    let number = rand::random::<u8>(); /* Las variables son inmutables por defecto */
    let mut x = 5; /* Para hacer una variable mutable se usa 'mut' */
    println!("Random number: {}", number);
    println!("Hello, world! The value of x is: {}", x);
    x = 6;
    println!("Now the value of x is: {}", x);
    /* Shadowing: usar misma variable con distintos tipos de datos */
    let y = 10;
    println!("The value of y is: {}", y);
    let y = y + 5; /* Se puede redeclarar la variable */
    println!("The value of y after shadowing is: {}", y);
    let y = "Hello"; /* Ahora y es de tipo &str */
    println!("The value of y after shadowing with a string is: {}", y);
    const MAX_POINTS: u32 = 100_000; /* Constantes no pueden ser mutables ni shadowed */
    println!("The maximum points are: {}", MAX_POINTS);
    println!("The minimum points are: {}", MIN_POINTS);
}
