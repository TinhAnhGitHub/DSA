#include <iostream>
#include <vector>
using namespace std;

template <typename E>
struct DefaultComp {
    static bool prior(const E& a, const E& b) {
        return a < b; // Change this according to your priority condition
    }
};

template <typename E, typename Comp = DefaultComp<E> >
void Inssort( vector<E>& arr,  int n, int incr){
    for( int i = incr ; i <n ; i+= incr){
        for( int j = i ; (j >= incr) && (Comp::prior(arr[j], arr[j- incr])) ; j -= incr){
            swap(arr[j] , arr[ j - incr]);
        }
    }
}

template< typename E, typename Comp = DefaultComp<E>>
void shellsort( vector<E> &A){
    int n = A.size();
    for( int i = n / 2; i > 2; i /=  2){
        for( int j = 0 ; j < i ; j ++){
            Inssort<E, Comp> ( A, n - j, i);
        }
        Inssort<E, Comp> ( A, n , 1);
    }
}




template <typename E, typename Comp = DefaultComp<E>>
void ShellSort( vector<E>& A, int gap){
    while ( gap >=1){
        for( int i = 0; i < gap ; i++){
            for( int j = i + gap; j < A.size(); j++){
                E tmp = A[j];
                int w = j - gap;
                for(; (w >=i) && Comp::prior(tmp, A[w]); w-= gap){
                    A[w + gap] = A[w];
                }
                A[w+gap] = tmp;
            }
        }
        gap --;
    }
}
int main() {
    vector<int> arr = {0,5,4,3,6,7};
    int gap = 3;

    ShellSort<int>(arr, gap);

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}