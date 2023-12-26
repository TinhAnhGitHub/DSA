void HelpFunc( int* arr, int& max, int& curr, int length){
    if ( curr >= length){
        return;
    }
    if ( arr[curr] >max ){
        max = arr[curr];
    }
    curr ++;
    
    HelpFunc( arr, max, curr, length);
}


int findMax(int* arr, int length)
{
    int MaxRes = arr[0];
    int curr = 1;
    HelpFunc( arr, MaxRes, curr, length);
    return MaxRes;
    
}

