#include <stack>
template <typename E> 
void LList<E>::reverse(){
    stack<E> revStack;
    Link<E>* tmp = head->next;
    while ( tmp){
        E value = tmp->element;
        revStack.push(value);
        tmp = tmp->next;
    }
     Link<E>* tmp2 = head->next;
    while (tmp2) {
        tmp2->element = revStack.top();
        revStack.pop();
        tmp2 = tmp2->next;
    }
    
    
}