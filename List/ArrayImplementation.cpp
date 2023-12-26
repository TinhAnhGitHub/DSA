#include "ADT.h"

template <typename T>
class ArrayList : public List<T> {
private:
    T * arr;
    int curr;
    int listSize;
    int MAXSIZE;
public:
    ArrayList(int size = defaultSize) {
        MAXSIZE = size;
        curr = listSize = 0;
        arr = new T[MAXSIZE];
    }
    ~ArrayList() {
        delete [] arr;
    }
    void clear() { // O(1)
        Assert(listSize != 0, "The list is empty, there is nothing to be cleared")
        delete [] arr;
        arr = new T[MAXSIZE];
        listSize = curr = 0;
    }
    int length() const { // O(1)
        return listSize;
    }
    void print() const { // O(n)
        for (int i = 0; i < listSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    void moveToStart() { // O(1)
        Assert( curr != 0, "Already at the beginning of the list");
        curr = 0;
    }
    void moveToEnd() { // O(1)
        Assert( curr != listSize -1, "Already at the end of the list");
        curr = listSize - 1;
    }
    void moveToPos(int pos) { // O(1)
        Assert( (pos >=0 && pos < listSize -1), "Wrong position !")
        curr = pos;
    }
    int currPos() const { // O(1)
        return curr;
    }
    void next() { // O(1) 
        Assert(curr < listSize-1, "Reach end of list.");
        curr++;
    }
    void prev() { // O(1)
        Assert(curr > 0, "No previous.");
        curr--;
    }
    const T& getValue() { // O(1)
        return arr[curr];
    }
    void insert(const T& item) { // best case : O(1) ; worst case : O(n) ; average case : O(n)
        Assert(listSize < MAXSIZE, "Reach limit size.");
        for (int i = listSize - 1; i >= curr ; i--) {
            arr[i+1] = arr[i];
        }
        arr[curr] = item;
        listSize++;
    }
    void append(const T& item) { // O(1)
        Assert(listSize < maxSize, "List capacity exceeded");
        listSize++;
        arr[listSize-1] = item;
    }
    T remove() {  // best case : O(1) ; worst case : O(n) ; average case : O(n)
        Assert((curr>=0) && (curr < listSize), "No element");
        T currValue = arr[curr];
        for (int i = curr; i < listSize-1; i++) {
            arr[i] = arr[i+1];
        }
        listSize--;
        return currValue;
    }
};

template <typename T>
class LinkedList : public List<T> { // dynamic memory allocation, allows memory for new elements needed
private:
    Node<T> * head;
    Node<T> * tail;
    Node<T> * curr;
    int pos;
    int listSize;
public:
    LinkedList() {
        head = tail = curr = new Node<T>();
        pos = listSize = 0;
    }
    ~LinkedList() { //  O(n)
        while (head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
    void clear() { // O(n)
        while (head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
        head = tail = curr = new Node<T>();
        listSize = 0;
    }
    int length() const { // O(1)
        return listSize;
    }
    void print() const { // O(n)
        Node<T> * temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void moveToStart() { // O(1)
        curr = head; pos = 0;
    }
    void moveToEnd() { // O(1)
        curr = tail; pos = listSize - 1;
    }
    void moveToPos(int pos) { // O(n)
        Assert( (pos < listSize -1 && pos >=0), "Out of bound");
        curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr->next;
        }
        this->pos = pos; 
    }
    void next() { // O(1)
        Assert(curr != NULL, "Reach end of list.");
        curr = curr->next; pos++;
    }
    void prev() { // O(n)
        Assert(curr != head, "No previous.");
        Node<T> * temp = head;
        while (temp->next != curr) {
            temp = temp->next;
        }
        curr = temp; pos--;
    }

    int currPos() const { return this->pos; }

    const T& getValue() const {
        return this->curr->data;
    }

    void insert(const T& item) {
        Node<T> * newitem = new Node<T>(item, curr->next);
        curr->next = newitem;
        listSize++;
    }
    void append(const T& item) {
        Node<T> * newitem = new Node<T>(item, NULL);
        tail->next = newitem;
        listSize++;
    }
    T remove() {
        Assert(head != NULL, "Nothing to remove.");
        Assert(curr != tail, "End of list.");
        Node<T> * temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        listSize--;
    }

};
/*
Some intuition:
Array-based :
    + Disadvantage:
        _ their size must be determined before an array can be allocated
        _ cannot grown beyond the predetermined size
        _ Take longer to remove and insert an element
    + Advantage:
        _ No wasted space for individual element, like using pointer in linked list
        _ Faster for random access




The amount of space required by a linked list is Θ(n), while the
space required by the array-based list implementation is Ω(n)

If the element size is small, then the overhead for links can be a significant
fraction of the total storage.

When the array for the array-based list is completely 
filled, there is no storage overhead. The array-based list will then be more space
efficient, by a constant factor, than the linked implementation.

The array-based implementation would be more efficient (if
the link field and the element field are the same size) whenever the array is more
than half full.
*/


// implement doubly linked list with free list support

template<typename T>
class DLL : public 