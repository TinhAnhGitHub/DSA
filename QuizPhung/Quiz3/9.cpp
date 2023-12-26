#include <unordered_map>
template <typename T> 
void DuplicationKiller( List<T> &L){
    unordered_map<T, int> HashTabel;
    L.moveToStart();
    for ( int i = 0; i < L.length(); i++){
        HashTabel[L.getValue()] ++;
        L.next();
    }
    L.moveToStart();
    int position = 0;
    while ( position < L.length ()){
        if ( HashTabel[L.getValue()] > 1){
            L.remove();
        }else {
            position ++;
            L.next();
        }
    }
    
}