#include <iostream>
using namespace std;


template <typename T>
void SelectionSort ( T* arr, int n);
int main (){
    int arr[] = {4,3,6,5,8,1,2};
    int n = 6;
    SelectionSort(arr,n );
    for ( int i = 0 ; i < n ; i++){
        cout<< arr[i]<<" ";
    }
    return 0;

}

template <typename T>
void SelectionSort(T * arr, int n){
    for( int i = 1; i < n ; i++){
        int lowestValueIndex = i;
        for (int j = i + 1; j < n; j++){
            if ( arr[j] < arr[lowestValueIndex]){
                lowestValueIndex = j;
            }
        }
   
        swap(arr[i], arr[lowestValueIndex]);
        
    }
}