#ifndef __ADT_H__
#define __ADT_H__

#include <iostream>
#include <cassert>

using namespace std;

#define defaultSize 50

void Assert(bool a, const string& str) {
    if (!a) {
        cout << str << endl;
    }
    assert(a);
}


template <typename T>
class Node {

public:
    T data;
    Node<T> * next;
    Node (): data(0), next(nullptr){}
    Node(const T& d, Node<T> * n = NULL): data(d), next(n) {};
    ~Node() { delete next; };
};





template <typename T>
class List {
private: 
    void operator = (const List& ){}
    void (const List& ){}
public:
    List() {};
    virtual ~List() {};
    virtual void clear() = 0; // clear the content of the list
    virtual int length() const = 0;
    virtual void print() const = 0;

    virtual void moveToStart() = 0;
    virtual void moveToEnd() = 0;
    virtual void moveToPos(int pos) = 0;
    virtual int currPos() const = 0;
    virtual void next() = 0;
    virtual void prev() = 0;

    virtual const T& getValue() const = 0;
    virtual void insert(const T& item) = 0;
    virtual void append(const T& item) = 0;
    virtual T remove() = 0;
    
};

template <typename T>
class Stack {
public:
    Stack() {};
    ~Stack() {};
    void push(const T& item) = 0;
    void pop() = 0;
    const T& top() const = 0;
    int length() const = 0;
    bool isEmpty() const = 0;
    void clear() = 0;
};

template <typename T>
class Queue {
public:
    void enqueue(const T& item) = 0;
    void dequeue() = 0;
    const T& front() const = 0;
    int length() const = 0;
    bool isEmpty() const = 0;
    void clear() = 0;
};
#endif