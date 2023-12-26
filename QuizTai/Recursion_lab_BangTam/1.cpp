#include <iostream>
#include <string>
using namespace std;


int helper( string s, int open , int count){
    if ( s.length() == 0){
        return open + count;
    }
    if ( s[0] == '('){
        return helper(s.substr(1), open + 1, count);
    }else{
        if ( open > 0){
            return helper(s.substr(1), open - 1, count);
        }else{
            return helper( s.substr(1), open, count +1);
        }
    }
}

int mininumBracketAdd(string s) {
    // STUDENT ANSWER
    return helper(s,0,0);
}
int main(){
    string s = ")))((";
    cout<< mininumBracketAdd(s);

}