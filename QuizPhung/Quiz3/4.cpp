
void insertBefore(const E& v, const E& k){
    Link<E>* tmp = this->head;
    while ( tmp->next && tmp->next->element != k){
        tmp = tmp -> next;
    }
    if (!(tmp->next)) return;
    
    tmp->next = new Link<E>(v, tmp->next);
    curr = tmp;
    
}