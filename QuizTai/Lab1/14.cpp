
#include <iostream>
#include <vector>
using namespace std;
// bool consecutiveOnes(vector<int>& nums) {
    
//     if ( nums.size() == 0){
//         return true;
//     }
//     vector<int> tmp;
//     int res = 0;
//     for ( int i = 0 ; i < nums.size() ; i++){
//         if ( nums[i] == 1){
//             res ++;
//         }else {
//             if ( res != 0){
//                 tmp.push_back(res);
//             }
            
//             res = 0;
//         }
        
//     }
//     if ( (tmp.size() == 1) || res > 1){
//         return true;
//     }
//     return false;
// }

int findOne( vector<int>& arr, int left, int right, bool a){
    if ( a){
        for( int i = left; i <= right; i++){
            if (arr[i] == 1) return i;
        }
    }
    else {
        for( int i = right; i >= left; i--){
            if (arr[i] == 1) return i;
        }
    }
    return -1;
}
bool consecutiveOnes(vector<int>& nums){
    int InitOne = findOne( nums, 0, nums.size()  - 1, 1);
    if ( InitOne == -1) return 1;
    int FinalOne = findOne( nums, 0, nums.size() - 1, 0);
    if ( FinalOne == -1) return 1;
    for( int i = InitOne + 1; i < FinalOne; i++){
        if( nums[i] != 1){
            return 0;
        }
        
    }
    return 1;
}
