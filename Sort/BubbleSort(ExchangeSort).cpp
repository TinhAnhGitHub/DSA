#include <iostream>
#include <vector>
using namespace std;


template <typename T>
void BubbleSort ( vector<T>& arr, int n);
int main (){
    vector<int> arr = {4,3,6,5,8,1,2};
    int n = arr.size();
    BubbleSort(arr,n);
    for ( int i = 0 ; i < n ; i++){
        cout<< arr[i]<<" ";
    }
    return 0;

}

template <typename T>
void BubbleSort(vector<T>& arr, int n){
    for( int i = 0; i < n - 1 ; i++){
        for ( int j = n - 1; j >= i ; j --){
            if ( arr[j] < arr[j - 1]){
                swap ( arr[j-1], arr[j]);
            }
        }
    }
}