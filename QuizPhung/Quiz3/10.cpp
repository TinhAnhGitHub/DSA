template <typename E>
List<E>* merge( List<E>* in1, List<E> * in2){
    List<E>* res = new LList<E>();
    
    in1->moveToStart(); in2->moveToStart();
    while ( in1->currPos() < in1->length() && in2->currPos() < in2->length()){
        if ( in1->getValue() <= in2->getValue()){
        
                res->append( in1->getValue());
                in1->next();
            
        }
        else{
            
                res->append(in2->getValue());
                in2->next();
            
        }
    }
    while( in1->currPos() < in1->length()){
        res->append(in1->getValue());
        in1->next();
    }
    while( in2->currPos() < in2->length() ){
        res->append(in2->getValue());
        in2->next();
    }
    return res;
    
}