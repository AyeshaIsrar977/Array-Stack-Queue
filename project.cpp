#include<iostream>
using namespace std;

class Array {
private:
    int* arr;
    int capacity;
    int size;
public:
    Array(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        arr = new int[capacity];
    }

    ~Array() {
        delete[] arr;
    }

    void insert(int index, int value) {
        if (index < 0 || index > size || size == capacity) {
            cout << "Invalid index or array is full" << endl;
            return;
        }
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
    }

    void deleteElement(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index." << endl;
            return;
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void search(int value) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                cout << "Element " << value << " found at index " << i << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Element " << value << " not found in the array." << endl;
        }
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty." << endl;
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Queue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int size;
public:
    Queue(int capacity) {
        this->capacity = capacity;
        this->front = 0;
        this->rear = -1;
        this->size = 0;
        arr = new int[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return (size == 0);
    }

    bool isFull() {
        return (size == capacity);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int temp = front;
        for (int i = 0; i < size; i++) {
            cout << arr[temp] << " ";
            temp = (temp + 1) % capacity;
        }
        cout << endl;
    }
};

// ---------------------- STACK CLASS ----------------------//
class Stack {
private:
    int top;
    int size;
    int* arr;
public:
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed to stack." << endl;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }
};

int main() {
    int choice;

    cout << "=============== DATA STRUCTURES PROJECT ===============\n";
    cout << "1. Run ARRAY Program\n";
    cout << "2. Run STACK Program\n";
    cout << "3. Run QUEUE Program\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "\n--- Running Array Program ---\n";
        Array array(10);

        array.insert(0, 10);
        array.insert(1, 20);
        array.insert(2, 30);
        array.insert(3, 40);
        array.insert(4, 50);

        array.display();
        array.search(30);
        array.deleteElement(2);
        array.display();
        array.search(60);
    }

    else if (choice == 2) {
        cout << "\n--- Running Stack Program ---\n";
        Stack s(5);
        s.push(10);
        s.push(20);
        s.push(30);

        cout << "Top element is: " << s.peek() << endl;
        cout << s.pop() << " Popped from stack." << endl;
        cout << "Now top element is: " << s.peek() << endl;
    }

    else if (choice == 3) {
        cout << "\n--- Running Queue Program ---\n";
        Queue queue(5);

        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        queue.enqueue(40);
        queue.enqueue(50);

        queue.display();
        cout << "Dequeued element: " << queue.dequeue() << endl;
        queue.display();
    }

    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
