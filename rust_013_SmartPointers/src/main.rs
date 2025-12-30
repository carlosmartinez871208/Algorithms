// Smart Pointer Example in Rust
// A smart pointer is a data structure that not only holds a value but also
// provides additional metadata and capabilities, such as automatic memory management.
// This code demonstrates the use of a smart pointer in Rust.
// Specifically, it uses the Box<T> smart pointer to allocate data on the heap.
// The Box<T> type is a simple smart pointer that provides ownership for heap-allocated data.
// When a Box<T> goes out of scope, the memory it points to is automatically deallocated.
// This example creates a Box containing an integer and prints its value.

fn main() {
    // Box smart pointer example
    let b = Box::new(5);
    println!("Box contains: {}", b);
    // When 'b' goes out of scope here, the memory allocated on the heap is automatically freed.
    // No explicit deallocation is needed.
    // This demonstrates Rust's ownership model and automatic memory management.
    // End of example
    // Note: Box<T> is just one of several smart pointers in Rust, others include Rc<T> and Arc<T> for reference counting.
    // Linked lists and other data structures can also be implemented using smart pointers.
    enum List {
        Node(i32, Box<List>),
        None,
    }
    let node0 = List::Node(0, Box::new(List::None));
    let node1 = List::Node(1, Box::new(node0));
    let node2 = List::Node(2, Box::new(node1));
    // The list now represents 2 -> 1 -> 0 -> None
    println!("Created a linked list using Box smart pointers.");
    // Display the list
    fn display_list(list: &List) {
        match list {
            List::Node(value, next) => {
                print!("{} -> ", value);
                display_list(next);
            }
            List::None => {
                println!("None");
            }
        }
    }
    display_list(&node2);

    // Deref trait example
    use std::ops::Deref;
    struct MyBox<T>(T);
    impl<T> Deref for MyBox<T> {
        type Target = T;
        fn deref(&self) -> &T {
            &self.0
        }
    }
    let x = 5;
    let y = MyBox(x);
    assert_eq!(5, *y);
    println!("Deref trait example works: {}", *y);

    // Drop trait example
    struct CustomSmartPointer {
        data: String,
    }
    impl Drop for CustomSmartPointer {
        fn drop(&mut self) {
            println!("Dropping CustomSmartPointer with data: {}", self.data);
        }
    }
    let c = CustomSmartPointer {
        data: String::from("my data"),
    };
    println!("CustomSmartPointer created.");

    // Reference Counting with Rc<T>
    use std::rc::Rc;
    let rc_a = Rc::new(5);
    let rc_b = Rc::clone(&rc_a);
    println!("Reference count after cloning: {}", Rc::strong_count(&rc_a));
    {
        let rc_c = Rc::clone(&rc_a);
        println!("Reference count inside block: {}", Rc::strong_count(&rc_a));
    }
}