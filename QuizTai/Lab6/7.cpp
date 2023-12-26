#include <bits/stdc++.h>

using namespace std;

int foldShift(long long key, int addressSize)
{
    int length = 0;
    int tmpS = key;
    while(tmpS > 0){
        length++;
        tmpS /= 10;
    }
    long long sum = 0 ;
    int i = 0;
    while(key > 0){
        long long tmp = (key / static_cast<long long>(pow(10, length - (length - (i * addressSize)))) );
         tmp = tmp / static_cast<long long>(pow(10, (length < 0 ? 0 : (length < addressSize ? 0 : length - addressSize))));
       
        sum +=  tmp;
        key = key % static_cast<long long>(pow(10, (length < 0 ? 0 : (length < addressSize ? 0 : length - addressSize))));
        length -= addressSize;

    }
    return sum % static_cast<long long>(pow(10, addressSize)) ;
}

int rotation(long long key, int addressSize)
{
    int digit = key % 10;
    int tmpS = key;
    int length = 0;
    while(tmpS){
        length++;
        tmpS /= 10;
    }
    key = key / 10;
    key = digit * pow(10,length-1) + key;
    return foldShift(key, addressSize);
}

int main (){
cout << rotation(1234567891234, 5);
}

