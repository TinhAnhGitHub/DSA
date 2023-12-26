
// template <typename T>
// void backtracking(vector<T> arr, vector<T>& Subset, vector<vector<T>>& AllSubSet, int index ){
//     int n = arr.size();
//     if (index >= n ){
//         AllSubSet.push_back(Subset);
//         return;
//     }
//     Subset.push_back(arr[index]);
//     backtracking(arr, Subset, AllSubSet, index + 1);
//     Subset.pop_back();
//     backtracking(arr, Subset, AllSubSet, index + 1);
//     return;
// }

// template <typename T>
// vector<vector<T>> powerSet(vector<T> arr){
//     vector<vector<T>> AllSubSet;
//     vector<T> subSet;
//     backtracking( arr, subSet, AllSubSet, 0);
//     return AllSubSet;  
// }

// Above is the backtracking approach, the complexity is O(n * (2^n)) since each elements 
// of the set has 2 possibilities: either include it or exclude it out of the subset.

// Since the output is bitwise-alike, here is the bitwise implementation
// the complexity is O(n * (2^n))
#include <vector>
using namespace std;
template <typename T>
vector<vector<T>> powerSet(vector<T> arr) {
    int n = arr.size();
    int subsets = 1 << n; 

    vector<vector<T>> result;

    for (int i = 0; i < subsets; ++i) {
        vector<T> subset;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << ( j))) {
                subset.push_back(arr[j]);
            }
        }
        result.push_back(subset);
    }

    return result;
}