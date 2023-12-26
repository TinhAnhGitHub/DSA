// Operation choices: DOMOVE will move a disk
// DOTOH corresponds to a recursive call
#include <iostream>
#include "ARRAYBASED.h"
using namespace std;

enum TOHop {DOMOVE, DOTOH};
class TOHobj {
private:
    TOHop op;
    int numDisk;
    char start, goal, tmp;
public:
    TOHobj ( int n, char s, char g, char t){
        numDisk = n;
        start = s;
        goal = g;
        tmp = t;
        op = DOTOH;
    }
    TOHobj ( char startt, char goall){
        op = DOMOVE;
        start = startt;
        goal = goall;
    }
    void move ( char s, char g){
        cout<<"Move disk from "<<s<<" to "<<g<<endl;
    }
    void TowerOfHanoi ( int disk, char s, char g, char tm, Stack<TOHobj*>& stack){
        stack.push( new TOHobj(disk, s, g, tm)); // initial
        TOHobj* t;
        while ( stack.length() > 0){
            t = stack.pop();
            if ( t ->op == DOMOVE){
                move(t->start, t->goal);
            }else if (t->numDisk >0){
                // three recursive statement
                int num = t->numDisk;
                char init = t->start;
                char goal = t->goal;
                char tmp = t->tmp;
                stack.push( new TOHobj(num-1, tmp, goal, init));
                stack.push( new TOHobj(init, goal)); // reversely TOH algorithm
                stack.push( new TOHobj(num-1, init, tmp, goal ));
            }
            delete t;
        }


    }

};

int main (){
    AStack<TOHobj*> stack;
    TOHobj toh(3, 'A', 'C', 'B');
    toh.TowerOfHanoi(3, 'A', 'C', 'B', stack);
    return 0;
}

