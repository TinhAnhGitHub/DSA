#include <iostream>
using namespace std;

template <typename T>

bool binarysearch(T arr[], int left, int right, T k){
    while(left <= right){
        int mid = left + (right - left) / 2;
        cout<< arr[mid]<<",";
        if ( arr[mid] == k){
                return true;
        }else if ( arr[mid] < k){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return false;
}
int main (){
int arr[]={3,5,12,16,20,21,28,29,30,33,35,36,37,38,50,56,57,58,62,66,69,72,75};
std::cout<<binarysearch(arr,0,22,75);
}