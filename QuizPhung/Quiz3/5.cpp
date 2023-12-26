template <typename E>
void LList<E>::print() const{
    Link<E>* tmp = head->next;
    cout<<"< ";
    while(tmp){
        if ( tmp == curr->next){
            cout<<"| "<<tmp->element<<" ";
        }else{
            cout<<tmp->element<<" ";
        }
        tmp = tmp->next;
    }
    if (tmp == curr->next){
        cout<<"| ";
    }
    cout<<">";
}