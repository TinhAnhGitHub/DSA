#include<bits/stdc++.h>

using namespace std;

int leastAfter(vector<int>& nums, int k) {
    // STUDENT ANSWER
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(),nums.end());
    for (int i = 0; i < k; i++) {
        int min = pq.top();
        if (min == 0) return 0;
        pq.pop();
        pq.push(min*2);
    }
    return pq.top();
}
int main (){
    	
    vector<int> nums {1, 3, 3, 2};
    int k = 4;
    cout << leastAfter(nums, k);
}