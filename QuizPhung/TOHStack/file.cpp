#include <iostream>
#include "ADT.h"
#include <cassert>
using namespace std;
#define DEFAULTSIZE 100

void Assert(bool a, string s){
    if ( !a){
        cout<<s<< endl;
        assert(a);
        
    }
}


template <typename T>
class AStack : public Stack<T>{
    private:
        int MaxSize;
        int topPos;
        T* listArray;
    public:
        AStack(int size = DEFAULTSIZE): MaxSize(size), topPos(0), listArray(new T[size]){}
        ~AStack() { delete [] listArray;}

        void push (const T& it){
            Assert(this->topPos != this->MaxSize, "The stack is full");
            this->listArray[this->topPos++] = it;

        }
        T pop() {
            Assert ( this->topPos != 0 , "The stack is empty");
            return this->listArray[ -- this->topPos];
        }
        const T& Value() const { // top value
            Assert ( this->topPos != 0 , "The stack is empty");
            return this->listArray[this->topPos - 1];
        }
        int length() const {
            return this->topPos;
        }

};






enum TOHop { DOMOVE, DOTOH};
enum Pole {START, GOAL, TMP};

class TOHobj{
public:
    TOHop op;
    int num;
    Pole start, goal, tmp;

    // DOTOH operation
    TOHobj( int n, Pole s, Pole g, Pole t): num(n), start(s), goal(g), tmp(t), op(DOTOH){}
    // DOMOVE operation
    TOHobj ( Pole s, Pole g): start(s), goal(g), op(DOMOVE){}



};

void TOH( int n , Pole s, Pole g, Pole t, AStack<TOHobj*> & S){
    S.push( new TOHobj( n, s, g, t));
    TOHobj * t;
    while ( S.length() > 0 ){
        
    }
}