#include <string>
#include <iostream>
#include <queue>
using namespace std;
int prefix(const string * L, int n) {
    queue<string> q;
    for(int i=0; i<n; i++){
        q.push(L[i]);
    }
    string temp1;
    string temp2;
    if (q.size() != 0) {temp1 = q.front(); 
    q.pop();}
    if (q.size() != 0) {temp2 = q.front(); 
    q.pop();}
    while (q.size() != 0) {
        string temp3 = q.front(); q.pop();
        if ((temp1 == "+" || temp1 == "-")&&(temp2 != "+" && temp2 != "-") && (temp3 != "+" && temp3 != "-") && q.size() == 0){
            int temp = stoi(temp2);
            if (temp1 == "+") {
                temp += stoi(temp3);
                return temp;
            } else {
                temp -= stoi(temp3);
                return temp;
            }
        }
        if ((temp1 == "+" || temp1 == "-")&&(temp2 != "+" && temp2 != "-") && (temp3 != "+" && temp3 != "-")) {
            int temp = stoi(temp2);
            if (temp1 == "+") {
                temp += stoi(temp3);
            } else {
                temp -= stoi(temp3);
            }
            q.push(to_string(temp));
            if (q.size() > 2) {
                temp1 = q.front(); q.pop();
                temp2 = q.front(); q.pop();
            }
        } else {
            q.push(temp1);
            temp1 = temp2;
            temp2 = temp3;
        }
    }
    return stoi(temp1);
}
int main(){
    string t[] = {"-","+","2","-","9","6","4"};
cout << prefix(t,7);
//1

string a[] = {"+","3","-","5","4"};
cout << prefix(a,5);
//4

string b[] = {"-","5","4"};
cout << prefix(b,3);
//1

string c[] = {"+","+","3","2","-","5","4"};
cout << prefix(c,7);
//6

string d[] = {"4"};
cout << prefix(d,1);
//4

string e[] = {"-","3","-","5","4"};
cout << prefix(e,5);
//2

string f[] = {"-","-","9","5","4"};
cout << prefix(f,5);
//0
}