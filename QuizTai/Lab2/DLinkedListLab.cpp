#include <iostream>
using namespace std;

template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head; 
    Node* tail;
    int count ;
public:
    DLinkedList(){
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    ~DLinkedList(){
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    void    add(const T &e);
    void    add(int index, const T &e);
    string    toString();
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int, const T&);
    int     indexOf(const T&);
    bool    contains(const T&);
    T       removeAt(int index);
    bool    removeItem(const T &item);
    void    clear();
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };

};


/* * * Function implementatio * * */
template <class T>
void DLinkedList<T>::add(const T& E){
    // insert an element into the end of the list

    // create a node for element E
    Node* tmp = new Node(E);
    // insert case 1: if the List is empty
    if (head == NULL){
        head = tail = tmp;
    }else{
        tail->next = tmp; // insert at the end of the List
        tmp->previous = tail; // assign previous of newNode back into the tail and then tail = tail -> next
        tail = tail->next;
    }
    this->count++; // increase size of the List
}

template <class T>
void DLinkedList<T>::add( int index, const T& E){
    if ( index < 0 || index > count){
        // error case
        return;
    }
    // create a node for element E
    Node* newNode = new Node(E);
    if ( index == 0){ // special case, where newNode is inserted at index[0] and turn into the head 
                    // of the array
        newNode->next = head;
        if(head != nullptr){
            head->previous = newNode;
        }
        head = newNode;
        if(tail == nullptr){
            tail = newNode;
        }
    }else if ( index == count){ //even though the index < count, since index == count it means that the node
                                // is append at the end
        // tail->next = newNode;
        // newNode->previous = tail;
        // tail = tail->next;
        this->add(E);
    }else{
        // come to the node previous to the "index" for insertion
        Node* temper = head;
        for( int i = 1; i < index - 1; i++){
            temper = temper->next;
        }
        // insertion part, easy to understand by visualization
        newNode->next = temper->next;
        newNode->previous = temper;
        temper->next->previous = temper->next = new Node;
    }
    count ++;
}

template <class T>
string DLinkedList<T>::toString() {
    string res = "[";

    Node* tmp = head;
    res.append(to_string(tmp->data));
    tmp = tmp->next;
    for (int i = 1; i < this->count; i++) {
        res.append(",");
        res.append(to_string(tmp->data));
        tmp = tmp->next;
    }
    res.append("]");
    return res;
}

template<class T>
int DLinkedList<T>::size(){
    return this->count;
}

template<class T>
T DLinkedList<T>::get( int Index){
    // give the data of the element at the given index
    Node* tmp = head;
    while( Index > 0){
        tmp = tmp->next;
        Index--;
    }
    return tmp->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if ( index < 0 || index > count){
        return;
    }
    Node* tmp = head;
    while ( index > 0){
        tmp = tmp->next;
        index --;
    }
    tmp->data = e;
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return (count == 0);   
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index whether item appears in list, otherwise return -1 */
    int indexRes = 0;
    Node* tmp = head;
    while( indexRes<count){
        if (tmp->data == item){
            return indexRes;
        }
        tmp = tmp->next;
        indexRes ++;
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    Node* res = head;
    while( res){
        if ( res->data == item){
            return true;
        }
        res = res->next;
    }
    return false;
    
}

template<class T>
T DLinkedList<T>::removeAt(int index){
    Node* tmp = head;
    T removedVal;

    if ( index == 0){
        // delete head, assign new head at head ->next
        head = tmp->next;
        if ( head != nullptr){
            head->previous = nullptr;
        }else{
            tail = nullptr;
        }
        removedVal = tmp->data;
        delete tmp;
    }else{
        // traverse through the node
        for( int i = 0;  i < index; i ++){
            tmp = tmp->next;
        }
        tmp->previous->next = tmp->next; // the previous->next pointet points to current->next
        if ( tmp->next){ // normal case, 
            tmp->next->previous = tmp->previous;
        }else{ // the delete node is at the end of the list: special case
            tail = tmp->previous; // tail becomes the node before tmp
        }
        removedVal = tmp->data;
        delete tmp;
    }
    count--;
    return removedVal;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    Node* current = head;

    // Traverse the list to find the item
    while (current != nullptr) {
        if (current->data == item) {
            // Found the item, remove it
            if (current->previous != nullptr) { // special case: remove at head
                current->previous->next = current->next;
            } else {
                head = current->next; // Removing the first node
            }

            if (current->next != nullptr) { // special case: remove at tail
                current->next->previous = current->previous;
            } else {
                tail = current->previous; // Removing the last node
            }

            delete current;
            --count;
            return true;
        }

        current = current->next;
    }

    return false; // Item not found
}

template <class T>
void DLinkedList<T>::clear()
{
    Node* current = head;
    Node* nextNode;

    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = tail = nullptr;
    count = 0;
}

/* * * Function implementatio * * */
int main (){
    DLinkedList<int> list;
    int size = 10;
    int value[] = {2,5,6,3,67,332,43,1,0,9};
    for(int idx=0; idx < size; idx++){
        list.add(idx);
    }
    for(int idx=0; idx < size; idx++){
        list.set(idx, value[idx]);
    }
    cout << list.toString();
}