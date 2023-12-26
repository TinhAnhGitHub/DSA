#include <iostream>
#include <string>

using namespace std;

void AddingString(string &s1, const string &s2, int count) {
    if (count == 0) {
        return;
    }
    s1 += s2;
    AddingString(s1, s2, count - 1);
}

string expandHelper(const string &s, size_t &pos) {
    if (pos >= s.length()) {
        return "";
    }
    string result;
    if (isdigit(s[pos])) {
        int count = s[pos] - '0';
        ++pos;
        string SubSub = expandHelper(s, pos);
        string temp;
        AddingString(temp, SubSub, count);
        result += temp;
        ++pos;
    } else if (s[pos] == '(') {
        ++pos;
        result += expandHelper(s, pos);
        
    } else if (s[pos] == ')') {
        ++pos;
        return "1";
    } else {
        result = s[pos];
        ++pos;
    }

    result += expandHelper(s, pos);
    return result;
}

string expand(const string &s) {
    size_t pos = 0;
    return expandHelper(s, pos);
}

int main() {
    string s = {"2(ab3(cde)x)"};
    cout << expand(s);
    return 0;
}
