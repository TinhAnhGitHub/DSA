#include<iostream>
using namespace std;
void HelpFunc( int n, int curr){
    cout<< curr;
    if ( curr == n){
        return;
    }
    cout<<", ";
    HelpFunc(n, curr + 1);
}

void printArray(int n)
{
    HelpFunc(n, 0);
}