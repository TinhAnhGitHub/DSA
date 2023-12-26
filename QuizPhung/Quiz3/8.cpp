template <typename T>
void del(List<T> &L, T k){
    
    L.moveToStart();
    int i = 0;
    while( i < L.length() ){
        if( L.getValue() == k){
            L.remove();
        }else{
            L.next();
            i ++;
        }
    }
    
}