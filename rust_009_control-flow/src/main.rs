/* Control Flow */

fn main() {
    let number = 6;
    // if-else statement
    if number < 5 {
        println!("Condition was true");
    } else {
        println!("Condition was false");
    }

    // if multiple conditions
    let number = 6;
    if number % 4 == 0 {
        println!("Number is divisible by 4");
    } else if number % 3 == 0 {
        println!("Number is divisible by 3");
    } else if number % 2 == 0 {
        println!("Number is divisible by 2");
    } else {
        println!("Number is not divisible by 4, 3, or 2");
    }

    // if in a let statement
    let condition = true;
    let number = if condition { 5 } else { 6 };
    println!("The value of number is: {}", number);

    //loop
    let mut count = 0;
    loop {
        count += 1;
        if count == 3 {
            break;
        }
    }
    println!("Loop ended at count: {}", count);

    // while loop
    let mut number = 3;
    while number != 0 {
        println!("{}!", number);
        number -= 1;
    }

    // for loop
    let a = [10, 20, 30, 40, 50];
    for element in a.iter() {
        println!("The value is: {}", element);
    }

    //let else
    let some_option: Option<i32> = Some(5);
    let Some (value) = some_option else {
        println!("No value found");
        return;
    };
    println!("The value is: {}", value);

    // match statement
    let number = 13;
    match number {
        1 => println!("One!"),
        2 | 3 | 5 | 7 | 11 => println!("This is a prime number"),
        13..=19 => println!("A teen"),
        _ => println!("A number"),
    }

    //labelled blocks
    'outer: loop {
        println!("Entered the outer loop");
        'inner: loop {
            println!("Entered the inner loop");
            break 'outer;
        }
        println!("This point will never be reached");
    }
    println!("Exited the outer loop");
}