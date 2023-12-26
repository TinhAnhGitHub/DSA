#include <iostream>
#include <vector>
using namespace std;

vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    int Operation = operations.size();
    for( int i = 0; i < Operation; i++){
        int init = operations[i][0];
        int final = operations[i][1];
        for( int j = init; j <= final ; j++){
            nums[j] += operations[i][2];
        }
    }
    return nums;
}