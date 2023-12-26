#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreater(vector<int>& arr){
    vector<int> res(arr.size(), -1);
    stack<int> stk;
    for(int i = 0; i < arr.size(); i++){
        if(!stk.empty() && arr[stk.top()] < arr[i]){
            res[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(i);
    }
}

int main (){
    vector<int> arr = {15,2,4,10};
    vector<int> greaterNums = nextGreater(arr);
    for(int i : greaterNums) 
        cout << i << ' ';
    cout << '\n';   
}