#include <iostream>
using namespace std;



template<typename T>
class FrequentSearch {
    private:
        struct Node
        {
            /* data */
            T key;
            int frequency;
        };
        Node* arr;
        int size;
    public:
        //* Constructor
        FrequentSearch(T* arr, int n) {
            this->arr = new Node[n];
            this->size = n;
            for (int i = 0; i < n; ++i) {
                this->arr[i].key = arr[i];
                this->arr[i].frequency = 0;
            }
        }

        ~FrequentSearch() {
            delete[] arr;
        }
        bool search( T key){
            for(int i = 0; i < this->size; i++){
                if( arr[i].key == key){
                    arr[i].frequency ++;
                
                    for(int j = i; j > 0 && arr[j].frequency >= arr[j-1].frequency; j--){
                        swap(arr[j], arr[j-1]);
                    }
                    return true;
                }
            }
        return false;
        }

        void print(){
            for(int i = 0; i < size; i++){
                cout<<arr[i].key<<",";
               

            }

        }
};

int main(){
	
char arr[4] = {'d','b','c','a'};
FrequentSearch<char>* x = new FrequentSearch<char>(arr,4);
x->search('a');
x->search('b');
x->search('a');
x->search('a');
x->search('c');
x->print();
}