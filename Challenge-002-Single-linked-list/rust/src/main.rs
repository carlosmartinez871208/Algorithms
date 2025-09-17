#[derive(Debug)]
struct Node {
    data: i32,
    next: Option<Box<Node>>,
}

struct SingleLinkedList {
    head: Option<Box<Node>>,
}

impl SingleLinkedList {
    fn new() -> Self {
        SingleLinkedList { head: None }
    }

    fn insert_at_beginning(&mut self, data: i32) {
        let new_node = Box::new(Node {
            data,
            next: self.head.take(),
        });
        self.head = Some(new_node);
    }

    fn insert_at_end(&mut self, data: i32) {
        let mut new_node = Box::new(Node { data, next: None });
        match self.head.as_mut() {
            Some(mut current) => {
                while let Some(ref mut next) = current.next {
                    current = next;
                }
                current.next = Some(new_node);
            }
            None => {
                self.head = Some(new_node);
            }
        }
    }

    fn delete_node_at_index (&mut self, index: usize){
        if index == 0 || index==1 {
            if let Some(node) = self.head.take() {
                self.head = node.next;
            }
            return;
        }
        let mut current = self.head.as_mut();
        let mut i = 0;
        while let Some(node) = current {
            if i + 1 == index {
                if let Some(next_node) = node.next.take() {
                    node.next = next_node.next;
                }
                return;
            }
            current = node.next.as_mut();
            i += 1;
        }
    }

    fn traverse(&self) {
        let mut current = self.head.as_ref();
        let mut result = Vec::new();
        while let Some(node) = current {
            result.push(node.data);
            current = node.next.as_ref();
        }
        println!("{:?}", result);
    }
}

fn main() {
    let mut list = SingleLinkedList::new();
    list.insert_at_beginning(3);
    list.insert_at_end(2);
    list.insert_at_end(4);
    list.insert_at_beginning(5);
    list.delete_node_at_index(3);
    list.traverse(); // Output: [5, 3, 2, 4]
}