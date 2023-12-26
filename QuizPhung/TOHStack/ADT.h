#ifndef __ADT__
#define __ADT

//stack ADT class
template <typename T>
class Stack{
    public:
        Stack(){}
        virtual ~Stack(){}
        virtual void clear () = 0;
        virtual void ( const T& it) = 0;
        virtual T pop () = 0;
        virtual const T& Value () const = 0;
        virtual int length() const  = 0;
        
};







#endif