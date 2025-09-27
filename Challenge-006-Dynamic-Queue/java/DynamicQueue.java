/*
 * DynamicQueue
 *  - Implementación de una cola dinámica usando un buffer circular.
 *  - Crece automáticamente (estrategia: duplicar capacidad) cuando size == capacidad.
 *  - Operaciones:
 *      enqueue: O(1) amortizado (O(n) solo cuando se realoca)
 *      dequeue: O(1)
 *      peek:    O(1)
 *      size:    O(1)
 *  - Estrategia de crecimiento: duplicar capacidad minimiza número de realocaciones.
 *  - No se implementa shrink para mantener simplicidad y evitar thrashing.
 */
public class DynamicQueue {
    private int[] data;
    private int front;      // índice del primer elemento válido
    private int rear;       // índice de la próxima posición libre para insertar
    private int size;       // número de elementos en la cola

    private static final int DEFAULT_CAPACITY = 8;

    public DynamicQueue() {
        this(DEFAULT_CAPACITY);
    }

    public DynamicQueue(int initialCapacity) {
        if (initialCapacity <= 0) {
            throw new IllegalArgumentException("Capacity must be > 0");
        }
        data = new int[initialCapacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    public int capacity() {
        return data.length;
    }

    public void clear() {
        // Reinicia índices y permite GC de enteros antiguos si fuera wrapper
        front = 0;
        rear = 0;
        size = 0;
    }

    public void enqueue(int value) {
        ensureCapacityForAdd();
        data[rear] = value;
        rear = (rear + 1) % data.length;
        size++;
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue underflow");
            return -1; // siguiendo el estilo de la cola estática
        }
        int value = data[front];
        front = (front + 1) % data.length;
        size--;
        // (Opcional) shrink si sobra mucha capacidad. Podemos omitir para simplicidad.
        return value;
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return -1;
        }
        return data[front];
    }

    private void ensureCapacityForAdd() {
        if (size == data.length) {
            // Duplicar capacidad
            int newCapacity = data.length * 2;
            int[] newData = new int[newCapacity];
            // Copiar en orden lógico actual
            for (int i = 0; i < size; i++) {
                newData[i] = data[(front + i) % data.length];
            }
            data = newData;
            front = 0;
            rear = size;
        }
    }

    @Override
    public String toString() {
        if (isEmpty()) return "[]";
        StringBuilder sb = new StringBuilder();
        sb.append('[');
        for (int i = 0; i < size; i++) {
            if (i > 0) sb.append(',');
            sb.append(data[(front + i) % data.length]);
        }
        sb.append(']');
        return sb.toString();
    }
}
