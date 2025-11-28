#include<iostream>
using namespace std;
class Array {
  private:
   int* arr;
   int capacity;
   int size;
  public:
   Array(int capacity) {
   this->capacity=capacity;
   this->size=0;
   arr=new int[capacity];
   }

   ~Array (){
     delete[] arr;
   }

   void insert(int index, int value) {
     if(index<0|| index>size || size==capacity) {
        cout<<"Invalid index or array is full"<<endl;
        return;
     }
     for(int i=size; i>index; i--) {
        arr[i]=arr[i-1];
     }
     arr[index]=value;
     size++;
   }
   void deleteElement(int index) {
     if(index<0 || index>=size) {
        cout<<"Invalid index."<<endl;
        return;
     }
    for(int i=index; i<size-1; i++) {
        arr[i]=arr[i+1];
    }
    size--;

   }

   void search(int value) {
    bool found=false;
    for(int i=0;i<size; i++) {
        if (arr[i]==value) {
            cout<<"Element "<<value<<" found at index "<<i<<endl;
            found=true;
            break;
        }
    }
    if (!found) {
        cout<<"Element "<<value<<" not found in the array."<<endl;

    }
   }
   
   void display() {
    if (size==0) {
        cout <<"Array is empty."<<endl;
        return;
    }
    cout<<"Array elements:";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   }
};
int main () {
    Array array(10);

    array.insert(0,10);
    array.insert(1,20);
    array.insert(2,30);
    array.insert(3,40);
    array.insert(4,50);


    cout<<"After inserting array elements: ";
    array.display();

    array.search(30);

    array.deleteElement(2);

    cout<<"After deleting element at index 2: ";
    array.display();

    array.search(60);
    return 0;
}
