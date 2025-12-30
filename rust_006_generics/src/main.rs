fn main() {
    // Generic types in Rust allow you to write flexible and reusable code.
    // Here is an example of a generic function that returns the largest element in a slice.
    // Sintax: fn function_name<T: Trait>(parameters) -> ReturnType { ... }
    fn largest<T: PartialOrd>(list: &[T]) -> &T {
        let mut largest = &list[0];
        for item in list {
            if item > largest {
                largest = item;
            }
        }
        largest
    }
    let number_list = vec![34, 50, 25, 100, 65];
    let result = largest(&number_list);
    println!("The largest number is {}", result);

    let char_list = vec!['y', 'm', 'a', 'q'];
    let result = largest(&char_list);
    println!("The largest char is {}", result);
}