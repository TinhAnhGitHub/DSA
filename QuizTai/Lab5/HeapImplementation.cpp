#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"




template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item){
        this->ensureCapacity(capacity + 1);
        elements[count] = item;
        reheapUp(count);
        count++;
    }
    
    bool isEmpty(){
        return count == 0;
    }
    bool contains(T item){
        for(int i = 0; i < count; i++){
            if(elements[i] == item){
                return true;
            }
        }
        return false;
    }
    T peek(){
        if (isEmpty()){
            return -1;
        }
        return elements[0];
    }
    bool pop(){
        if(isEmpty()){
            return -1;
        }
        elements[0] = elements[count - 1];
        count --;
        reheapDown(0);
        return true;
    }
    int size(){
        return count;
    }
    
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
    int getItem(T item){
        // TODO: return the index of item in heap
        for(int i = 0; i < count; i++){
            if(elements[i] == item){
                return i;
            }
        }
        return -1;
    }


    void remove(T item) {
        // TODO: remove the element with value equal to item
        int i = 0;
        for(; i < count; i++){
            if(elements[i] == item){
                break;
            }
        }
        if(i >= count){
            return;
        }
        
     elements[i] = elements[count - 1];
            count --;
            for(int j = count - 1; j >=0 ; j--){
                reheapDown(j);
            }
            return;
    }
    void clear(){
        delete [] elements;
        elements = new T[capacity];
        count = 0;
    }

private:
    void ensureCapacity(int minCapacity){
        if( minCapacity > this->capacity){
            T* newElements = new T[minCapacity];
            for(int i = 0; i < capacity; i++){
                newElements[i] = elements[i];
            }
            delete [] elements ;
            elements = newElements;
            capacity = minCapacity;
        }
    }
    void reheapUp(int position){
        int parent = (position - 1) / 2; //* Floor
        while(position > 0 && elements[position] > elements[parent]){
            swap(elements[position], elements[parent]);
            position = parent;
            parent = (position - 1) / 2;
        }
    }
    void reheapDown(int position){
        int leftChild = 2 * position + 1;
        int rightChild = 2 * position + 2;
        int max = position;
        if ( leftChild < numberOfElements){
            max = (elements[leftChild] <= elements[position])? position : leftChild; 
        }
        if(rightChild < numberOfElements){
            max = (elements[rightChild] <= elements[max])? max : rightChild;
        }
        if(max != position){
            swap(elements[max], elements[position]);
            reheapDown(max);
        }
    }
};

int main(){
    Heap<int> maxHeap;
    for (int i=0;i<10;i++){
        maxHeap.push(i);
    }
    cout << maxHeap.isEmpty();

    cout<<endl<<endl;
    Heap<int> maxHeap;
    for(int i = 0; i <5;i++)
        maxHeap.push(i);
    maxHeap.printHeap();


}
