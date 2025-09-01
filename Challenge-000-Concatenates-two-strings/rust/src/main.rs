/*
fn declares a function.
main() is the entry point.
println! is a macro (note the !) for printing.
*/
fn main()
{
    let a = vec![1, 2];
    let b = vec![3, 4];
    let concatenated = [a, b].concat();
    println!("{:?}", concatenated);

    // Or
    /*let mut v1 = vec![1, 2];
    let arr = [3, 4];
    v1.extend_from_slice(&arr); // Append elements from the array
    println!("{:?}", v1); // Output: [1, 2, 3, 4]*/

    //Or
    /*let arr1 = [1, 2];
    let arr2 = [3, 4];
    let combined_vec: Vec<i32> = arr1.iter().chain(arr2.iter()).copied().collect();
    println!("{:?}", combined_vec); // Output: [1, 2, 3, 4]*/
}