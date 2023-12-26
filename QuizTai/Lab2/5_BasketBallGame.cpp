/*
TODO: You are keeping score for a basketball game with some new rules. The game consists of several rounds, where the scores 
TODO: of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] 
is the operation you must apply to the record, with the following rules:

* A non-negative integer x (from 0 to 9) - record a new score of x
* '+' - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
* 'D' - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
* 'C' - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
* Finally, return the sum of all scores in the record.

For example:

ops = "52CD+"

'5' - add to the record. Record now is [5]
'2' - add to the record. Record now is [5,2]
'C' - invalid the previous score (2). Record now is [5]
'D' - Record new score that is double of previous score (5*2). Record now is [5,10]
'+' - Record a new score that is the sum of the previous two scores. Record now is [5,10,15]
Return the sum: 5+10+15 = 30
*/

#include<iostream>
#include <stack>
#include <string>
using namespace std;

int baseballScore(string ops) {
    stack<int> StackInt;

    int n = ops.length();

    for (int i = 0; i < n; i++) {
        if (isdigit(ops[i])) {
            StackInt.push(ops[i] - '0'); 
        } else if (ops[i] == 'C') {
            if (!StackInt.empty()) {
                StackInt.pop();
            }
        } else if (ops[i] == 'D') {
            if (!StackInt.empty()) {
                int temper = StackInt.top();
                StackInt.push(temper * 2);
            }
        } else if (ops[i] == '+') {
            if (StackInt.size() >= 2) {
                int temper1 = StackInt.top();
                StackInt.pop();
                int temper2 = StackInt.top();
                StackInt.push(temper1);
                StackInt.push(temper1 + temper2);
            }
        }
    }

    int res = 0;

    while (!StackInt.empty()) {
        res += StackInt.top();
        StackInt.pop();
    }

    return res;
}
int main(){
    cout << baseballScore("524CD9++");
}