/* Template for Rust program */
struct Queue<T> {
    items: Vec<T>,
}

impl<T> Queue<T> {
    fn new() -> Self {
        Queue { items: Vec::new() }
    }

    fn enqueue(&mut self, item: T) {
        self.items.push(item);
    }

    fn dequeue(&mut self) -> Option<T> {
        if self.is_empty() {
            println!("Queue underflow");
            None
        } else {
            Some(self.items.remove(0))
        }
    }

    fn peek(&self) -> Option<&T> {
        if self.is_empty() {
            println!("Queue is empty");
            None
        } else {
            self.items.first()
        }
    }

    fn is_empty(&self) -> bool {
        self.items.is_empty()
    }
}

fn main() {
    let mut queue = Queue::new();
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    println!("Frente: {:?}", queue.peek());      // Some(10)
    println!("Dequeue: {:?}", queue.dequeue());  // Some(10)
    println!("Nuevo frente: {:?}", queue.peek()); // Some(20)
}