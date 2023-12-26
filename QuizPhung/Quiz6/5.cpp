#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class ChainingHash {
private:
    int (*hash)(int);
    list<int> *data;
    int size;
    
public:
    ChainingHash() {
        throw "Cannot create a hash with no hash function!";
    }
    
    ChainingHash(int size, int (*hash)(int)) {
        this->hash = hash;
        this->size = size;
        this->data = new list<int>[size];
    }
    
    void insert(int key) {
        int index = hash(key);
        this->data[index].push_back(key);
    }

    void remove(int key){
        int index = hash(key);
        list<int>& slot = this->data[index];

        auto it = find(slot.begin(), slot.end(), key);
        if (it != slot.end()){
            slot.erase(it);
        }else{
            throw runtime_error("Not found!");
        }
    }

    bool search(int key){
        int index = hash(key);
        list<int>& slot = this->data[index];
        return (find(slot.begin(), slot.end(), key) != slot.end());
    }


    
    int count() {
        int total = 0;
        for (int i = 0; i < this->size; i++) {
            total += this->data[i].size();
        }
        return total;
    }
    
    void dump() {
        for (int i = 0; i < this->size; i++) {
            cout << "Slot " << i << ": " << this->data[i].size() << " element(s)" << endl;
        }
    }
};


int hashWith11(int key) {
    return key % 11;
}
int hashWith15(int key) {
    return key % 15;
}
int hashWith17(int key) {
    return key % 17;
}