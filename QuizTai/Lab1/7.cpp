#include <iostream>
using namespace std;

void printPattern(int n) 
{ 
    /*  
     * STUD
     ENT ANSWER
     */
     if ( n <= 0 ){
         cout<< n;
         return;
     }
     cout<< n << " ";
     printPattern(n - 5);
     cout<<" "<<n;
     
}