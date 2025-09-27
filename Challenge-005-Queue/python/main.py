#!python3
class Queue:
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if self.is_empty():
            print("Queue underflow")
            return None
        return self.items.pop(0)

    def peek(self):
        if self.is_empty():
            print("Queue is empty")
            return None
        return self.items[0]

    def is_empty(self):
        return len(self.items) == 0

# Ejemplo de uso
if __name__ == "__main__":
    queue = Queue()
    queue.enqueue(10)
    queue.enqueue(20)
    queue.enqueue(30)

    print("Frente:", queue.peek())      # 10
    print("Dequeue:", queue.dequeue())  # 10
    print("Nuevo frente:", queue.peek()) # 20
