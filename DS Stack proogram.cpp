#include<iostream>
using namespace std;

class Stack {
    private:
     int top;
     int size;
     int*arr;

    public:
     Stack(int s) {
        size=s;
        arr=new int[size];
        top=-1;
     } 
     ~Stack() {
        delete[] arr;
     }
     void push(int value) {
        if (isFull()) {
            cout<<"Stack Overflow! Cannot push "<<value<<endl;
        }
        else {
            arr[++top]=value;
            cout<<value<<" pushed to stack."<<endl;
            
        }
     }
     int pop () {
        if (isEmpty()) {
            cout<<"Stack Underflow!Cannot pop."<<endl;
            return-1;
        }
        else {

            return arr[top--];
        }
     }
     int peek () {
        if (isEmpty()) {
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
        else {
            return arr[top];
        }
     }
     bool isEmpty () {
        return top==-1;
     }
     bool isFull () {
        return top==size-1;
     }
};

int main () {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);

    cout<<"Top element is: "<<s.peek()<<endl;
    cout<<s.pop()<<" Popped from stack."<<endl;
    cout<<"Now top element is: "<<s.peek()<<endl;

    return 0;
}