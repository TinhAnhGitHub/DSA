#include <iostream>
using namespace std;

enum STATUS_TYPE {NIL, NON_EMPTY, DELETED};
class OpenHash {
private:
    int (*hp)(int, int);
    STATUS_TYPE* status;
    int* data;
    int size;
    
public:
    OpenHash() {
        throw "Cannot create a hash with no hash function!";
    }
    
    OpenHash(int size, int (*hp)(int, int)) {
        this->hp = hp;
        this->size = size;
        this->data = new int[size];
        this->status = new STATUS_TYPE[size];
        for (int i = 0; i < size; i++) {
            this->status[i] = NIL;
        }
    }
    
    int insert(int key){
        int i = 0;
        int index;
        while(i < this->size){
            index = hp(key, i);
            if(this->status[index] == NIL || this->status[index] == DELETED){
                this->data[index] = key;
                this->status[index] = NON_EMPTY;
                return index;
            }else{
                for(int i = 0; i < size; i++){
                    if (this->data[i] == key){
                        throw runtime_error("Duplicate key: "+to_string(key));
                    }
                }
            }
            i++;
        }
         throw runtime_error("Overflow!"+to_string(key));
    }

    void remove(int key){
        int i = 0;
        int index;
        while(i < this->size){
            index = hp(key,i);
            if(this->status[index] == NON_EMPTY && this->data[index] == key){
                this->status[index] = DELETED;
                return;
            }
            i++;
        }
        throw runtime_error("Not found!");
    }

    int search(int key){
        int i = 0;
        int index;
        do {
            index = hp(key, i);
            if (this->status[index] == NON_EMPTY && this->data[index] == key) {
                return index;
            }
            i++;
        } while (this->status[index] != NIL && i < this->size);
        return -1;
    }
    
    void dump() {
        for (int i = 0; i < this->size; i++) {
            if (this->status[i] != NON_EMPTY)
                cout << "Slot " << i << ": Empty" << endl;
            else cout << "Slot " << i << ": " << this->data[i] << endl;
        }
    }
};


int linearProbing(int key, int i) {
    return ((key % 11) + i) % 11;
}

int quadraticProbing(int key, int i) {
    return ((key % 11) + i + 3 * i * i) % 11;
}

int doubleHashing(int key, int i) {
    int h1 = key % 11;
    int h2 = 1 + (key % 10);
    return (h1 + i * h2) % 11;
}

int main(){
    	
	
OpenHash* hashTable = new OpenHash(11, '"""linearProbing""');
int data[] = {10, 11, 22, 77, 28, 17, 88, 59};
int size = sizeof(data) / sizeof(int);
try {
   for (int i = 0; i < size; i++) {
    hashTable->insert(data[i]);
   }
   hashTable->remove(77);
   hashTable->insert(44);
   cout <<  hashTable->search(77) << endl;

} catch (const exception& e) {
   cout << e.what();
}
}