#include <iostream>
using namespace std;


template <typename T>
void InsertionSort ( T* arr, int n);
int main (){
    int arr[] = {4,3,6,5,8,1,2};
    int n = 6;
    InsertionSort(arr,n );
    for ( int i = 0 ; i < n ; i++){
        cout<< arr[i]<<" ";
    }
    return 0;

}

template <typename T>
void InsertionSort(T * arr, int n){
    for( int i = 1; i < n ; i++){
        T tmp = arr[i];
        int j;
        for( j = i - 1; j >= 0 && tmp < arr[j]; j--){
            arr[j + 1] = arr[j]; // basically shifting the part of the array up a part
        }
        arr[j + 1 ] = tmp; 
    }
}
