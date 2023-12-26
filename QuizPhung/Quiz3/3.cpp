void remove(){
    if (this-> cursor >= this-> listSize ){
        throw out_of_range("Cannot remove element");
    }
    for ( int i = this->cursor; i < listSize -1; i++){
        data[i] = data[i + 1];
    }
    this->listSize--;
}