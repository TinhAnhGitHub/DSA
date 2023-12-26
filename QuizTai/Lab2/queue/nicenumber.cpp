#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long long nthNiceNumber(long long  n) {
    queue<long long > q;
    long long  a = 2;
    long long  b = 5;
    if(n==1) return a;
    if(n==2) return b;
    q.push(a);
    q.push(b);
    long long  count = 2;
    while(!q.empty()){
        long long  tmp = q.front();
        q.pop();
        long long  tmp1 = tmp * 10 + a;
        long long  tmp2 = tmp * 10 + b;
        if(++count == n) return tmp1;
        if(++count == n) return tmp2;
        q.push(tmp1);
        q.push(tmp2);
    }
    return -1;
    
}

int main (){
    	
int n;
cin >> n;
cout << nthNiceNumber(n) << endl;
}