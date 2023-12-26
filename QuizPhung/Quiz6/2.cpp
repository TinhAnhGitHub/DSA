#include <iostream>
using namespace std;

template <typename T>

int binarysearch(T arr[], int n, T k){
    int left = 0;
    int right = n - 1;

    int IndexMaxLessThanK = -1;
    int value = 0;
    while(left <= right){
        int mid = left + (right - left) / 2;

        cout<< mid<<", ";
        if( arr[mid] == k){
            return mid;
        }else if( arr[mid] < k){
            if( arr[mid] > value){
                value = arr[mid];
                IndexMaxLessThanK  = mid;
            }
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return IndexMaxLessThanK;
}
int main (){
int arr[]={3,5,12,16,20,21,28,29,30,33,35,36,37,38,50,56,57,58,62,66,69,72,75};
std::cout<<binarysearch(arr,23,75);
}