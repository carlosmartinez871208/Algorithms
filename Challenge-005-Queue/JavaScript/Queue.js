/* Template for Java Scrip*/
class Queue {
    constructor() {
        this.items = [];
    }

    // Encolar (agregar al final)
    enqueue(element) {
        this.items.push(element);
    }

    // Desencolar (eliminar del frente)
    dequeue() {
        if (this.isEmpty()) {
            console.log("Queue underflow");
            return undefined;
        }
        return this.items.shift();
    }

    // Consultar el frente
    peek() {
        if (this.isEmpty()) {
            console.log("Queue is empty");
            return undefined;
        }
        return this.items[0];
    }

    // Verificar si está vacía
    isEmpty() {
        return this.items.length === 0;
    }
}

// Ejemplo de uso
const queue = new Queue();
queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);

console.log("Frente:", queue.peek());      // 10
console.log("Dequeue:", queue.dequeue());  // 10
console.log("Nuevo frente:", queue.peek()); // 20