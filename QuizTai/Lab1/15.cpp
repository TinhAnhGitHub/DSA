#include<iostream>
#include <vector>
using namespace std;

// int equalSumIndex(vector<int>& nums) {
//     if ( nums.size() == 1){
//         return 0;
//     }
//     int RightSum = 0, LeftSum = 0;
//     for( int i = 1; i < nums.size() ; i++){
//         RightSum += nums[i];
//     }
//     for ( int i = 0, j = 1; j < nums.size(); i++, j++){
//         RightSum -= nums[j] ;
//         LeftSum += nums[i];
//         if ( RightSum == LeftSum){
//             return i + 1;
//         }
//     }
//     return -1;
// }

int equalSumIndex(vector<int>& nums) {
    bool Equal = false;
    int res;
    for( int i = 0; i < nums.size() ; i++){
        int LeftSum = 0;
        int RightSum = 0;
        int MoveLeft = i - 1, MoveRight = i + 1;
        while ( MoveLeft >= 0){
            LeftSum += nums[MoveLeft];
            MoveLeft--;
        }
        while ( MoveRight < nums.size() ){
            RightSum += nums[MoveRight];
            MoveRight ++;
        }
        if ( RightSum == LeftSum ){
            res = i;
            Equal = true;
            break;
        }
    }
    return (Equal)? res: -1;
    
}

int main (){
   vector<int> nums5 {-1, 2, 3, 0, 3, 2, -1};
cout << equalSumIndex(nums5);
}



