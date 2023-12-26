template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList(): head(NULL), tail(NULL), count(0);
    ~SLinkedList() { };
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T& e);
    int     indexOf(const T& item);
    bool    contains(const T& item);
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
        Node(T data, Node* next = NULL) {
            this->data = data;
            this->next = next;
        }
    };
};
template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if ( index < 0 || index >count){
        return 0;
    }
    Node* tmp = head;
    for( int i = 0 ; i < index ; i++){
        tmp = tmp->next;
    }
    return tmp->data;
    
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if ( index < 0 || index >count){
        return;
    }
    Node* tmp = head;
    for( int i = 0 ; i < index ; i++){
        tmp = tmp->next;
    }
    tmp->data = e;
    return;
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return count == 0;
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node* tmp = head;
    for( int i = 0; i < count ; i++){
        if ( tmp->data == item){
            return i;
        }
        tmp = tmp->next;
    }
    return -1;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    Node* tmp = head;
    for( int i = 0 ; i < count ; i++){
        if ( tmp->data == item){
            return true;
        }
        tmp = tmp->next;
    }
    return false;
    
}