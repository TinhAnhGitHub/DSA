// Abstract queue class
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

void Assert( bool a, string s){
    if (!a){
        cout<<s<<endl;
    }
    assert(a);
}


template <typename E> class Queue {
    private:
        void operator =(const Queue&) {} // Protect assignment
        Queue(const Queue&) {} // Protect copy constructor
    public:
        Queue() {} // Default
        virtual ~Queue() {} // Base destructor
        // Reinitialize the queue. The user is responsible for
        // reclaiming the storage used by the queue elements.
        virtual void clear() = 0;
        // Place an element at the rear of the queue.
        // it: The element being enqueued.
        virtual void enqueue(const E&) = 0;
        // Remove and return element at the front of the queue.
        // Return: The element at the front of the queue.
        virtual E dequeue() = 0;
        // Return: A copy of the front element.
        virtual const E& frontValue() const = 0;
        // Return: The number of elements in the queue.
        virtual int length() const = 0;
    };
    // Singly linked list node
template <typename E> class Link {
public:
E element; // Value for this node
Link *next; // Pointer to next node in list
// Constructors
Link(const E& elemval, Link* nextval =NULL)
{ element = elemval; next = nextval; }
Link(Link* nextval =NULL) { next = nextval; }
};
// Linked queue implementation
template <typename E> class LQueue: public Queue<E> {
    private:
        Link<E>* front; // Pointer to front queue node
        Link<E>* rear; // Pointer to rear queue node
        int size; // Number of elements in queue
    public:
    LQueue(int sz =100) // Constructor
        { front = rear = new Link<E>(); size = 0; }


    ~LQueue() { clear(); delete front; }
     // Destructor
    void clear() { // Clear queue
        if(front->next != NULL) { // Delete each link node
            rear = front->next;
            delete rear;
        }
            rear = front;
            size = 0;
    }
    void enqueue(const E& it) { // Put element on rear
        rear->next = new Link<E>(it, NULL);
        rear = rear->next;
        size++;
    }
    E dequeue() { // Remove element from front
        Assert(size != 0, "Queue is empty");
        E it = front->next->element; // Store dequeued value
        Link<E>* ltemp = front->next; // Hold dequeued link
        front->next = ltemp->next; // Advance front
        if (rear == ltemp) rear = front; // Dequeue last element
        delete ltemp; // Delete link
        size --;
        return it; // Return element value
    }
    const E& frontValue() const { // Get front element
        
        return front->next->element;
    }
    const E& rearValue() const{
        Assert(size != 0, "Queue is empty");
        return rear->element;
    }
    virtual int length() const { return size; }
};

int prefix(const string* L, int n) {
    
    string * tmp = new string[n];
    for( int i = 0; i < n; i++){
        tmp[i] = L[i];
    }
    int size = n;
    while( !isdigit(tmp[0][0])){
        int position = 0;
        LQueue<string> Link;

        for( int i = 0; i < n ; i++){
            
            if ( !isdigit(tmp[i][0])){
                if ( Link.length() >0 ){
                    Link.clear();
                }
                Link.enqueue(tmp[i]);
                position = i;
            }else{
                Link.enqueue(tmp[i]);
                if ( Link.length() == 3){
                    string Operator = Link.dequeue();
                    int Operand1 = stoi(Link.dequeue());
                    int Operand2 = stoi(Link.dequeue());
                    int res = 0;
                    if ( Operator == "+"){
                        res = Operand1 + Operand2;
                    }else{
                        res = Operand1 - Operand2;
                    }
                    tmp[position] = to_string(res);
                    int k ;
                    for(  k = position + 1; k < n - 2; k ++){
                        tmp[k] = tmp[k + 2];
                    } 
                    n -=2;
                    i = position+ 1;
                    // for ( int l = 0 ; l < n; l++){
                    //     cout<< tmp[l] << " ";
                    
                }
            }
        }
    }
    return stoi(tmp[0]);
    
}

int main (){
    string t[] = {"+","3","-","5","4"};
  
    cout << prefix(t,5);
}