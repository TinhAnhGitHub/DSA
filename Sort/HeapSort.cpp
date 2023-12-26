#include <iostream>
#include <vector>
using namespace std;






template<typename T>
void heapify( vector<T> &  A, int Pos, int length){
    int leftChild = 2 * Pos + 1;
    int RightChild = 2* Pos + 2;
    int max = Pos;
    if ( leftChild < length){
        max = ( A[leftChild] <= A[Pos])? Pos : leftChild;
    }
    if ( RightChild < length){
        max = ( A[RightChild] <= A[max])? max : RightChild;
    }
    if (max != Pos){
        swap( A[max], A[Pos]);
        heapify( A, max, length);
    }
}

template<typename T>
void heap_sort( vector<T> &A){
    for( int i = A.size()/2 -1; i >=0; i--){
        heapify(A, i, A.size());
    }
    for( int i = 0 ; i < A.size(); i++){
        swap( A[0], A[A.size() - i - 1]);
        heapify ( A, 0, A.size() - i - 1);
    }
}


int main (){
    vector<int> Array = {4,5,3,8,6,7,9,1,2};
    heap_sort(Array);
    for( int i = 0; i < Array.size(); i++){
        cout<< Array[i] <<" ";
    }
}