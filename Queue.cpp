#include<iostream>
using namespace std;
 
class Queue {
    private:
     int*arr;
     int capacity;
     int front;
     int rear;
     int size;
    public:
     Queue(int capacity) {
        this->capacity=capacity;
        this->front=0;
        this->rear=-1;
        this->size=0;
        arr=new int[capacity];
     } 
     ~Queue() {
        delete[] arr;
     }
     bool isEmpty() {
        return (size==0);
     }
     bool isFull() {
        return (size==capacity);
     }

     void enqueue(int value) {
        if (isFull()) {
            cout<<"Queue is full. Cannot enqueue."<<endl;
            return;
        }
        rear=(rear+1)%capacity;
        arr[rear]=value;
        size++; 
     }
  
     int dequeue() {
        if (isEmpty()) {
            cout<<"Queue is empty. Cannot dequeue."<<endl;
            return-1;
        }
        int value=arr[front];
        front=(front+1)%capacity;
        size--;
        return value;
     }

     int getFront() {
        if (isEmpty()) {
            cout<<"Queue is empty."<<endl;
            return-1;
        }
        return arr[front];
     }

     int getSize() {
        return size;
     }

     void display() {
        if (isEmpty()) {
            cout<<"Queue is empty."<<endl;
            return;
        }
        int temp=front;
        for (int i=0;i<size;i++) {
            cout<<arr[temp]<<" ";
            temp=(temp+1)%capacity;
        }
        cout<<endl;
     }
};
int main() {
    Queue queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    
    cout<<"Queue elements: ";
    queue.display();

    cout<<"Dequeued element: "<<queue.dequeue()<<endl;

    cout<<"Queue elements after dequeue: ";
    queue.display();

    return 0;
}
