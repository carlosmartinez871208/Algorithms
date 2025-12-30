// Use command "cargo test".

fn main() {
    // Unit test:
    // Assert that the main function runs without panicking.    assert!(std::panic::catch_unwind(|| {
    // Your main logic here, if any.
    // assert!(true); // Placeholder assertion
    // }).is_ok());
    // assert!(expresion);
    // assert_eq(a,b);
    // assert_ne(a,b);
    let a = 5;
    let b = 10;
    let resultado = sumar(a, b);
    println!("La suma de {} y {} es: {}", a, b, resultado);
}

fn sumar(a: i32, b: i32) -> i32 {
    a + b
}

#[test]
fn test_sumar() {
    assert_eq!(sumar(2, 3), 5);
    assert_eq!(sumar(-1, 1), 0);
    assert_ne!(sumar(10, 5), 20);
}
#[test]
fn test_sumar_negative() {
    assert_eq!(sumar(-5, -5), -10);
    assert_eq!(sumar(-3, 3), 0);
    assert_ne!(sumar(-2, -3), -4);
}