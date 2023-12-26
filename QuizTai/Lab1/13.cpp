#include <iostream>
#include <algorithm>
using namespace std;
int buyCar(int* nums, int length, int k) {
    // sort the array
    sort( nums , nums + length);
    int MaxCar = 0;
    int MaxTotalCost =0;
    for ( int i = 0 ; i < length ; i++){
        if ( MaxTotalCost + nums[i] <= k){
            MaxTotalCost += nums[i];
            MaxCar ++;
        }else {
            break;
        }
    }
    return MaxCar;
}