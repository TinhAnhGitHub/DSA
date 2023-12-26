#include <iostream>
#include <cmath>
using namespace std;


template <typename T>

bool dictionarySearch(T arr[], int left, int right, T k){
    int n = right - left + 1;
    while(left <= right && k >= arr[left] && k <= arr[right]){
        double c = (double)(left + (double)( (double)(k - arr[left]) * (right - left ) / (double)(arr[right] - arr[left]) ) );
        int p = round(c);
        if ( p > (n) || p < 0){
            return false;
        }
        cout<<arr[p]<<",";
        if(arr[p] == k){
            return true;
        }else if(arr[p] < k){
            left = p + 1;
        }else{
            right = p - 1;
        }
    }
    return false;
}
int main(){

int arr[]={1,5,7,8,16,30,33,35,41,49,51,52,59,61,65,68,69,71,72,75,76,83,85,89,97};
std::cout<<dictionarySearch(arr,0,24,49);
}