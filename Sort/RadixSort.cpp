#include <iostream> 
#include <vector>

using namespace std;

void RadixSort(vector<int>& A, int left, int right, int mask) {
    int init = left;
    int last = right;
    if (right <= left || mask == 0) {
        return;
    }

    while (last != init) {
        while ((A[init] & mask) == 0 && (init < last)) {
            init++;
        }
        while ((A[last] & mask) == mask && (init < last)) {
            last--;  
        }
        swap(A[init], A[last]);
       
    }

    RadixSort(A, left, last - 1, mask >> 1);
    RadixSort(A, last, right, mask >> 1);
}
int main() {
    vector<int> arr = {3,4,6,5,7,8};
    
    
    RadixSort(arr, 0, arr.size() - 1, 8); 

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
