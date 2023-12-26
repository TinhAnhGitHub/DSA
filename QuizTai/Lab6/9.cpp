#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long int midSquare(long int seed)
{
    long int tmp = seed * seed;
    long int mid = (tmp / 100) % 10000;
    return mid;
}

long int moduloDivision(long int seed, long int mod)
{
    return seed % mod;
}

long int digitExtraction(long int seed, int* extractDigits, int size)
{
    vector<int> tmp(extractDigits, extractDigits + size);
    int tmptmp = seed;
    int length = 0;
    while(tmptmp > 0){
        length ++;
        tmptmp /= 10;
    }
    long int res = 0;
    long int tmpS = seed;
    int i = length  - 1;
    while (tmpS > 0)
    {
        int digit = tmpS % 10;
        if (find(tmp.begin(), tmp.end(), i) != tmp.end())
        {
            res = res * 10 + digit;
        }
        tmpS /= 10;
        i--;
    }

    return res;
}

int main()
{
    int a[] = {1, 2, 5};
    cout << digitExtraction(122443, a, 3) << endl;
    return 0;
}
