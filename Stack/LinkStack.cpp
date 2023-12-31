#include "Stack(ADT).h"

template <typename E>

class LinkedStack : public Stack<E> {
private:
    Link<E>* top; // Pointer to first element
    int size; // Number of elements
public:
    LStack(int sz ) // Constructor
    { top = NULL; size = 0; }
    void clear() { // Reinitialize
        while (top != NULL) { // Delete link nodes
            Link<E>* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }
     ~LStack() { clear(); } // Destructor
    void push(const E& it) { // Put "it" on stack
        top = new Link<E>(it, top);
        size++;
    }
    E pop() { // Remove "it" from stack
        if ( top == NULL){
            cout<<"Stack is empty";
            return;
        }
        E it = top->element;
        Link<E>* ltemp = top->next;
        delete top;
        top = ltemp;
        size--;
        return it;
    }
    const E& topValue() const { // Return top value
        Assert(top != 0, "Stack is empty");
        return top->element;
    }
    int length() const { return size; } // Return length
};