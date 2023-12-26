#include <iostream>
#include <string>
using namespace std;
string reverseSentence(string s) {
    if ( s.empty() || s.find(' ') == string::npos){
        return s;
    }
    size_t SpacePos = s.find(' ');
    string InitWord = s.substr(0, SpacePos);
    string TheRemain = s.substr(SpacePos + 1);
    string reversing = reverseSentence(TheRemain );
    return reversing + " " + InitWord;
}