#include<bits/stdc++.h>
using namespace std;

class PrinterQueue {
    // your attributes
    vector<pair<int, pair<int, string>>> q;
    int i = 0;

public:
    // your methods
    static bool Compare(const pair<int, pair<int, string>>& a, const pair<int, pair<int, string>>& b) {
        if( a.second.first == b.second.first){
            return a.first < b.first;
        }
        return a.second.first > b.second.first;
    }

    void addNewRequest(int priority, string fileName) {
        q.push_back({this->i, {priority, fileName}});
        this->i++;
        sort(q.begin(), q.end(), Compare);
    }

    void print() {
        // your code here
        // After some logic code, you have to print fileName with endline
        if (q.empty()) {
            cout << "No file to print" << endl;
            return;
        }
        cout << q[0].second.second << endl;
        q.erase(q.begin());
    }
};

int main (){
    PrinterQueue* myPrinterQueue = new PrinterQueue();
    myPrinterQueue->addNewRequest(1, "hello.pdf");
    myPrinterQueue->addNewRequest(2, "goodbye.pdf");
    myPrinterQueue->addNewRequest(2, "goodnight.pdf");
    myPrinterQueue->print();
    myPrinterQueue->print();
    myPrinterQueue->print();
}