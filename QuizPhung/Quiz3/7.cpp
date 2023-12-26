template<typename E>
int count(List<E> &L, E K){
    int res = 0;
    for ( L.moveToStart(); L.currPos()< L.length(); L.next()){
        
        if ( L.getValue() == K){
            res++;
        }
    }
    return res;
}