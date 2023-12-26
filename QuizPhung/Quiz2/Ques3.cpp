

#include <iostream> 
using namespace std;
unsigned int fibo(int n){
    int res = 0;
    unsigned int f0 = 0;
    unsigned int f1 = 1;
    if ( n == 0) return f0;
    if ( n == 1) return f1;
    for ( int i = 2; i <=n ; i++){
        res = f0 + f1;
        f0 = f1;
        f1 = res;
    }
    return res;
}