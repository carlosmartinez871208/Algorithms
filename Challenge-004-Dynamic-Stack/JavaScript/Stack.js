class Stack {
    constructor() {
        this.items = [];
    }

    // Agregar elemento (push)
    push(element) {
        this.items.push(element);
    }

    // Eliminar elemento (pop)
    pop() {
        if (this.isEmpty()) {
            console.log("Stack underflow");
            return undefined;
        }
        return this.items.pop();
    }

    // Consultar elemento en la cima (peek)
    peek() {
        if (this.isEmpty()) {
            console.log("Stack is empty");
            return undefined;
        }
        return this.items[this.items.length - 1];
    }

    // Verificar si está vacía
    isEmpty() {
        return this.items.length === 0;
    }
}

// Ejemplo de uso
const stack = new Stack();
stack.push(10);
stack.push(20);
stack.push(30);

console.log("Cima:", stack.peek()); // 30
console.log("Pop:", stack.pop());   // 30
console.log("Nueva cima:", stack.peek()); // 20