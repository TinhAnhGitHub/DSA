KOnmj#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename E>
struct DefaultComp {
    static bool prior(const E& a, const E& b) {
        return a < b;
    }
};

template <typename E, typename Comp = DefaultComp<E>>
vector<E> mergeSort(const vector<E>& L1, const vector<E>& L2) {
    vector<E> result;
    int i = 0, j = 0;

    while (i < L1.size() && j < L2.size()) {
        if (Comp::prior(L1[i], L2[j])) {
            result.push_back(L1[i]);
            i++;
        } else {
            result.push_back(L2[j]);
            j++;
        }
    }

    while (i < L1.size()) {
        result.push_back(L1[i]);
        i++;
    }

    while (j < L2.size()) {
        result.push_back(L2[j]);
        j++;
    }

    return result;
}

template <typename E, typename Comp = DefaultComp<E>>
vector<E> mergeSort(const vector<E>& arr) {
    if (arr.size() <= 1)
        return arr;

    int mid = arr.size() / 2;
    vector<E> left(arr.begin(), arr.begin() + mid);
    vector<E> right(arr.begin() + mid , arr.end());

    left = mergeSort<E, Comp>(left);
    right = mergeSort<E, Comp>(right);

    return mergeSort<E, Comp>(left, right);
}


template <typename E, typename Comp = DefaultComp<E>>
void mergeSort( vector<E> &A, vector<E>& temp, int left, int right){
    if ( left == right){
        return;
    }
    int mid = ( left + right )/ 2;
    mergeSort<E, Comp>( A, temp, left, mid);
    mergeSort<E, Comp>(A, temp, mid + 1, right);
    // copy subarray to temp
    for( int i = left; i <= right; i++){
        temp[i] = A[i];
    }
    // Do the merge operation back to A
    int i1 = left;
    int i2 = mid + 1;
    for( int current = left; current <= right; current ++){
        if ( i1 == mid + 1){
            A[current] = temp[i2++];
        }
        else if (i2 > right){
            A[current] = temp[i1++];
        }

        else if (Comp::prior( temp[i1], temp[i2])){
            A[current] = temp[i1++];
        }else {
            A[current] = temp[i2++];
        }

    }
}
template<typename E, typename Comp = DefaultComp<E>>
void inssort( vector<E>& Arr, int n){
    for( int i = 1; i < n; i++){
        E temper = Arr[i];
        int j = i - 1;
        for( ; (j >=0) && Comp::prior(temper, Arr[j]); j--){
            Arr[j + 1] = Arr[j];
        }
        Arr[j+ 1] = temper;
    }

}

template<typename E, typename Comp= DefaultComp<E>>
void mergeSortOptimized( vector<E> & A, vector<E>& temp, int left, int right, int threshold_){
    if( ( right - left <= threshold_)){
        inssort<E, Comp>(A, A.size());
        return;
    }
    int i, j, k, mid = (left + right) / 2;
    mergeSort<E, Comp>(A, temp, left, mid);
    mergeSort<E, Comp>(A, temp, mid + 1, right);
    for( i = mid; i >=0; i --){
        temp[i] = A[i];
    }
    for( int j = mid + 1, k = right; j <= right ; j++){
        temp[j] = A[k--];
    }
    for(i = left, j = right, k = left; k <=right; k++ ){
        if (Comp::prior(temp[i], temp[j])){
            A[k] = temp[i++];
        }else {
            A[k] = temp[j--];
        }
    }
}
int main() {
    vector<int> arr = {1,4,5,6,7,9};
    vector<int>temp (arr.size());
    int left = 0;
    int right = arr.size() - 1;
    mergeSortOptimized<int>(arr, temp, left, right, 1);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
