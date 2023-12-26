#include <iostream>
#include <cmath>
using namespace std;

template <typename T>

bool jumpsearch(T arr[], int n, T k, int j){
    int i = 0;

    while(arr[i] < k ){
        if( i >= n){
            break;
        }
        cout<<arr[i]<<",";
        i += j;
        if(arr[j * i]  == k){
            cout<<arr[i]<<",";
            return true;
        }
    }
    //* Handle where arr[j]>K
    if ( i > n){
        int i_pre = i - j + 1;
        if( i_pre < 0) return false;
        for(; i_pre < n ; i_pre ++){
            cout<<arr[i_pre]<<",";
            if ( arr[i_pre] > k){
                return false;
            }
            if(arr[i_pre] == k){
                return true;
            }
    }
     return false;
    }
    cout<<arr[i]<<",";
    int i_pre = i - j + 1;
    if( i_pre < 0) return false;
    for(; i_pre < i ; i_pre ++){
        cout<<arr[i_pre]<<",";
        if ( arr[i_pre] > k){
            return false;
        }
        if(arr[i_pre] == k){
            return true;
        }
    }
    return false;
}

int main(){
	
	
int arr[]={3,5,12,16,20,21,28,29,30,33,35,36,37,38,50,56,57,58,62,66,69,72,75};
std::cout<<jumpsearch(arr,23,59,5);

}