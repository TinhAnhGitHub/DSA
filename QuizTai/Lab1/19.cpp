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
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    int     size();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(const T& item);
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

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if ( index < 0 || index > count){
        return 0;
    }
    T result;
    if ( index == 0){
        Node* tmp = head;
        head = head->next;
        result = tmp->data;
        delete tmp;
        if ( count == 1){
            tail = NULL;
        }
        count --;
        return result;
    }
    Node* temper = head;
    for ( int i = 0; i < index - 1; i++){
        temper = temper->next;
    }
    Node* tmp2 = temper->next;
    temper->next = tmp2->next;
    result = tmp2->data;
    delete tmp2;
    if ( index == count - 1) {
        // delete at last
        tail = temper;
    }
    count --;
    return result;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    Node* current = head;
    Node* previous = nullptr;
    while ( current != nullptr){
        if ( current ->data == item){
            if ( previous == nullptr){
                head = current ->next;
            }else {
                previous->next = current ->next;
                if ( current == tail){
                    tail = previous;
                }
            }
            delete current;
            count --;
            return true;
        }
        previous = current ;
        current = current ->next;
        
    }
    return false;
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    for( int i = 0 ; i < count ; i++){
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;
}

