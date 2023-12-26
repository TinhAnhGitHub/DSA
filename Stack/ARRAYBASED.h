#include "Stack(ADT).h"

template <class E>
class AStack: public Stack<E> {
    private:
        int maxSize; // Maximum size of stack
        int top; // Index for top element
        E *listArray; // Array holding stack elements
    public:
        AStack(int size = 10): maxSize(size), top(0), listArray(new E[size]) {}
        ~AStack() { delete [] listArray; }

        void clear () { top = 0; } // reinitialize

        //push 'it' on stack
        void push ( const E& it){
            if ( top == maxSize){
                cout<<"Stack is full";
                return;
            }
            listArray[top++] = it;
        }
        // pop top element
        E pop(){
            if ( top == 0){
                throw "Stack is empty";
            }
            return listArray[--top];
        }
        const E& topValue() const{
            if ( top == 0){
                
                throw "Stack is empty";
            }
            return listArray[top-1];
        }
        int length() const { return top; } // return length
        
};