#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting {
private:
    static void printArray(T* start, T* end)
    {
        int  size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << " ";
        cout << start[size - 1];
        cout << endl;
    }

    static void merge(T* start, T* middle, T* end) ;
public:
    static void InsertionSort(T* start, T* end) ;
    static void TimSort(T* start, T* end, int min_size) ;
};

//*  Implement merge function
template<class T>
void Sorting<T>::merge(T* start, T* middle, T* end){
    int leftSize = middle - start + 1;
    int rightSize = end - middle;
    int left[leftSize];
    int right[rightSize];

    //* Copy data from arr -> temporary arrau 
    for(int i = 0; i < leftSize; i++){
        start[i] = left[i];
    }
    for(int j = 0; j < rightSize; j++){
        right[j] = middle[j + 1];
    }
    int i = 0,  j = 0,  k = 0;
    while(i < leftSize && j < rightSize){
        if (left[i] <= right[i]){
            start[k++] = left[i++];
        }else{
            start[k++] = right[j++];
        }
    }
    while(i<leftSize) start[k++] = left[i++];
    while(j<rightSize) start[k++] = right[j++];
}

template <class T>
void Sorting<T>::InsertionSort(T* start, T* end){
    int n = end - start;
    for(int i = 1; i < n; i++){
        for(int j = i; j >= 0 && start[j] < start[j-1]; j--){
            swap(start[j], start[j-1]);
        }
    }
}

template <class T>
void Sorting<T>::TimSort(T* start, T* end, int minSize){
    int n = end - start;
    T* s = start, *e = end;
    for(int i = 0; i < n; i += minSize){
        if( i + minSize <= n){
            InsertionSort(s, s + minSize);
        }else{
            InsertionSort(s, e);
        }
    }
    cout<<"Insertion Sort: ";
    printArray(start, end);

    int count = 0;
    for( int gap = minSize; gap < n; gap *= 2){
        s = start;
        for(int j = 0; j < n; j +=(2* gap)){
            T* mid = s + gap - 1;
            if ( j + gap - 1 >= n) mid = end - 1;
            if ( j + 2*gap -1 < n){
                e = j + 2*gap - 1;
            }else{
                e = end - 1;
            }
            merge(s,mid,e);
            cout << "Merge " << ++count << ": ";
            printArray(start, end);
            s += 2* gap;
        }
    }
}

int main(){

}