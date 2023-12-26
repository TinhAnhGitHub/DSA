void insert(const T& v){
    if ( this->size == MAX){
        return;
    }
    for ( int i = size ; i > cursor ; i--){
        data[i] = data[i-1];
    }
    data[cursor] = v;
    this->size ++;
    return;
    
}