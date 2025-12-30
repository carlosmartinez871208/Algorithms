/* En Rust la revision de los tipos de datos se hace en tiempo de compilacion (static typing) */


fn main() {
    /* Integer: signed or unsigned:
    ** Sintax:
    ** let variable_name: data_type = value;
    */
    let a: i32 = -10; // entero con signo de 32 bits
    let b: u32 = 20;  // entero sin signo de 32 bits
    println!("a: {}, b: {}", a, b);

    /* Integer literals:
    ** 
    */
    let decimal: i32 = 98_222;       // Decimal
    let hex: i32 = 0xff;             // Hexadecimal
    let octal: i32 = 0o77;           // Octal
    let binary: i32 = 0b1111_0000;   // Binario
    let byte: u8 = b'A';             // Byte (u8 only)
    println!("decimal: {}, hex: {}, octal: {}, binary: {}, byte: {}", decimal, hex, octal, binary, byte);

    /* Floating point:
    ** Sintax:
    ** let variable_name: data_type = value;
    */
    let x: f32 = 2.0; // 32-bit floating point
    let y: f64 = 3.0; // 64-bit floating point (default)
    println!("x: {}, y: {}", x, y);

    /* Boolean: */
    let t: bool = true;
    let f: bool = false;
    println!("t: {}, f: {}", t, f);

    /* Character: */
    let c: char = 'z';
    let z: char = 'ℤ';
    let heart_eyed_cat: char = '😻';
    println!("c: {}, z: {}, heart_eyed_cat: {}", c, z, heart_eyed_cat);

    /* Compound types: */
    // Tuple: es usado para agrupar multiples valores en un solo tipo compuesto, tienen un tamaño fijo.
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    /* Para usar los elementos de el tuple directamente: */
    let (x, y, z) = tup;
    println!("tup: ({}, {}, {}), x: {}, y: {}, z: {}", tup.0, tup.1, tup.2, x, y, z);

    // Array: los arrays tienen un tamaño fijo y todos los elementos deben ser del mismo tipo.
    let arr: [i32; 5] = [1, 2, 3, 4, 5];
    println!("arr: [{}, {}, {}, {}, {}]", arr[0], arr[1], arr[2], arr[3], arr[4]);

    // Array with default values:
    let arr_default: [i32; 5] = [3; 5]; // all elements will be 3
    println!("arr_default: [{}, {}, {}, {}, {}]", arr_default[0], arr_default[1], arr_default[2], arr_default[3], arr_default[4]);

    // Slice: un slice es una vista dinamica de una secuencia contigua de elementos en un array.
    let slice: &[i32] = &arr[1..4]; // slice from index 1 to 3
    println!("slice: [{}, {}, {}]", slice[0], slice[1], slice[2]);

    // String: cadena de texto dinamica
    let s: String = String::from("Hello, Rust!");
    println!("s: {}", s);

    // &str: cadena de texto inmutable
    let str_slice: &str = "Hello, &str!";
    println!("str_slice: {}", str_slice);

    // Option type: para valores que pueden o no estar presentes
    let some_number: Option<i32> = Some(10);
    let no_number: Option<i32> = None;
    match some_number {
        Some(n) => println!("some_number: {}", n),
        None => println!("no number"),
    }
}