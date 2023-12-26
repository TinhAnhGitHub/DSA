template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();
    void    add(const T& e);
    void    add(int index, const T& e);
    int     size();
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
void SLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* tmp = new Node(e, NULL);
    if ( head == NULL){
        head = tmp;
        tail = tmp;
        count = 1;
        return;
    }
    tail->next = tmp;
    tail = tail->next;
    count ++;
    return;
    
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */
    Node* newNode = new Node(e, NULL);
    if ( head == NULL  || index == count){
        this->add(e);
        return;
    }
    if ( index == 0){
        newNode->next = head;
        head = newNode;
        count ++ ;
        return;
    }
    Node*temper = head;
    for( int i = 0; i < index - 1; i++){
        temper = temper->next;
    }
    newNode->next = temper ->next;
    temper->next = newNode;
    count ++;
    return;
    
}

template<class T>
int SLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}
