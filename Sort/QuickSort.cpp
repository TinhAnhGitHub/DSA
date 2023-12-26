#include <iostream> 
#include <vector>
using namespace std;

template <typename E>
struct DefaultComp {
    static bool prior(const E& a, const E& b) {
        return a < b;
    }
};


template< typename E> 
int findPivot(vector<E> & A, int i , int j){
    return ( i + j) / 2;
}
template <typename E, typename Comp = DefaultComp<E>>
int Partition ( vector<E>& A, int left, int right, E& pivot){
    do {
        while( Comp::prior( A[++left], pivot));
        while( ( left < right ) && Comp::prior( pivot, A[--right]));
        swap( A[left], A[right]);
    }while( left < right);
    return left;
}

template <typename E, typename Comp = DefaultComp<E>>
void qsort(vector<E>& A, int init, int final){
    if ( final <= init){
        return;
    }
    int PivotIndex = findPivot( A, init ,final);
    swap( A[PivotIndex], A[final]);
    int k = Partition<E, Comp> ( A, init - 1, final, A[final]);
    swap ( A[k], A[final]);
    qsort<E, Comp> ( A, init , k - 1);
    qsort<E, Comp> ( A, k+ 1, final);

}

int main() {
    vector<int> arr = {59, 20, 17, 13, 28, 14, 23, 83, 36, 98, 11, 70, 65, 41, 42, 15};
    qsort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}