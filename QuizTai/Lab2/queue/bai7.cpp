#include <deque>
#include <vector>
#include <iostream>
using namespace std;

int sumOfMaxSubarray(const vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;

    if (k > n) {
        return -1;  // Invalid input
    }

    deque<int> dq;

    // Initialize deque with the first k elements
    for (int i = 0; i < k; ++i) {
        while (!dq.empty() && nums[i] > nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // Process the remaining elements
    for (int i = k; i < n; ++i) {
        sum += nums[dq.front()];  // Add the maximum value of the previous subarray

        // Remove elements outside the current subarray
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove elements smaller than the current element from the back
        while (!dq.empty() && nums[i] > nums[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    sum += nums[dq.front()];  // Add the maximum value of the last subarray

    return sum;
}

int main(){
    vector<int> nums {-1, -2,- 4, -3, -6};
    int k = 3;
    cout << sumOfMaxSubarray(nums, k);
}