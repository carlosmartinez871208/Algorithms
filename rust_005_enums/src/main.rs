/* Enums */
/* Es un tipo de dato que permite definir un conjunto de valores posibles */
/* Sintaxis: 
** enum NombreDelEnum {
**     Valor1,
**     Valor2,
**     Valor3,
** }
*/

// option
enum Option<T> {
    Some(T),
    None,
}

enum Direction {
    North,
    South,
    East,
    West,
}

fn main() {
    let mut my_direction = Direction::North;
    match my_direction {
        Direction::North => println!("You are heading North!"),
        Direction::South => println!("You are heading South!"),
        Direction::East  => println!("You are heading East!"),
        Direction::West  => println!("You are heading West!"),
    }
    my_direction = Direction::East;
    match my_direction {
        Direction::North => println!("You are heading North!"),
        Direction::South => println!("You are heading South!"),
        Direction::East  => println!("You are heading East!"),
        Direction::West  => println!("You are heading West!"),
    }
    my_direction = Direction::South;
    match my_direction {
        Direction::North => println!("You are heading North!"),
        Direction::South => println!("You are heading South!"),
        Direction::East  => println!("You are heading East!"),
        Direction::West  => println!("You are heading West!"),
    }
    my_direction = Direction::West;
    match my_direction {
        Direction::North => println!("You are heading North!"),
        Direction::South => println!("You are heading South!"), 
        Direction::East  => println!("You are heading East!"),
        Direction::West  => println!("You are heading West!"),
    }
    let some_number = Option::Some(5);
    let no_number: Option<i32> = Option::None;
    match some_number {
        Option::Some(value) => println!("The number is: {}", value),
        Option::None => println!("No number found"),
    }
    match no_number {
        Option::Some(value) => println!("The number is: {}", value),
        Option::None => println!("No number found"),
    }
}