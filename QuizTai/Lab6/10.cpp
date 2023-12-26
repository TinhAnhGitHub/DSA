#include <bits/stdc++.h>

using namespace std;


// int pairMatching(vector<int>& nums, int target) {
//     int count = 0;
//     bool tmpB;
  
//         for(int i = 0; i < nums.size(); i++){
//             int tmp = nums[i];
//             tmpB = false;
//             for(int j = i + 1; j < nums.size(); j++){
//                 int tmp2 = nums[j];
//                 if (tmp + tmp2 == target){
//                     count++;
//                     nums.erase(nums.begin() + i);
//                     nums.erase(nums.begin() + j - 1);
//                     i = -1;
//                     tmpB = true;
//                     cout<<tmp<<""<<tmp2<<" ";
//                     break;
//                 }
//             }
//             if(!tmpB && i == nums.size() - 1){
//                 break;
//             }
//         }
    
//     return count;
// }
int pairMatching(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numFrequency; // Map to store frequency of each number
    int pairCount = 0;

    for (int num : nums) {
        int complement = target - num;

        if (numFrequency.find(complement) != numFrequency.end() && numFrequency[complement] > 0) {
            // Found a pair
            pairCount++;
            numFrequency[complement]--; // Decrement the frequency of the complement
        } else {
            // Update the frequency of the current number
            numFrequency[num]++;
        }
    }

    return pairCount;
}

int main (){
    int target = 11;
vector<int>items{2,6,9,2,2,9,8,4,7,5};
cout << pairMatching(items, target);
}