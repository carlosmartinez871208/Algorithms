fn main() {
    println!("Hello, world!");
    display_message();
    display_message_with_params("Ninmah", 5);
    let sum = add(5, 7);
    println!("The sum of 5 and 7 is: {}", sum);
    // Block expression
    let num = {
        20
    };
    println!("The value of num is: {}", num);
    reference_example(&num);
    let mut mutable_num = 15;
    mutable_reference_example(&mut mutable_num);
    println!("The final value of mutable_num is: {}", mutable_num);
}

/* Function syntax
fn function_name(){
    // function body
}*/
fn display_message() {
    println!("This is a sample message from the display_message function.");
}

/* Function syntax
fn function_name(parameter1: type, parameter2: type){
    // function body
}
*/
fn display_message_with_params(name: &str, age: u32) {
    println!("Name: {}, Age: {}", name, age);
}

/* Function syntax
fn function_name(parameter1: type, parameter2: type) -> return_type {
    // function body
}
*/
fn add(a: i32, b: i32) -> i32 {
    a + b
}

/* Reference value parameter */
fn reference_example(value: &i32) {
    println!("The referenced value is: {}", value);
}

/* Reference mutable parameter */
fn mutable_reference_example(value: &mut i32) {
    *value += 10;
    println!("The modified referenced value is: {}", value);
}