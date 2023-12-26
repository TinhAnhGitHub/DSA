template <typename T>
int findMax(T arr[],int n){
    int curr_max = - INT8_MAX;
    int index_max = 0;
    for ( int i =0; i < n; i++){
        if ( arr[i] >= curr_max){
            curr_max = arr[i];
            index_max = i;
        }
    }
    return index_max;
    
}