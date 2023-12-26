#include <iostream>
using namespace std;

class Exp;
class IntLit;
class BinExp;
class UnExp;
class IntLit;

class Exp{
    public:
        float v;
        virtual float eval() = 0 ;
        virtual void printPrefix () = 0;
    
};

class BinExp : public Exp{
    public:
    
    Exp* left;
    char op;
    Exp* right;
    
    
    BinExp(Exp* leftt, char opp, Exp* rightt) : left(leftt), op(opp), right(rightt){}
    
    float eval(){
        float res = 0;
        float v1 = left->eval();
        float v2 = right->eval();
        if ( this->op == '+'){
            res =  v1 + v2;
        }else if ( this->op == '-'){
            res = v1 - v2;
        }else if ( this->op == '*'){
            res = v1 * v2;
        }else {
            res = v1 / v2;
        }
        return res;
    }
    void printPrefix(){
        string res = "";
        string tmp = "";
        if ( this->op == '+'){
           tmp = "+";
        }else if ( this->op == '-'){
            tmp = "-";
        }else if ( this->op == '*'){
            tmp = "*";
        }else {
            tmp = "/";
        }
        
        cout<<tmp<< " ";
        left->printPrefix(); 
        cout<<" ";
        right->printPrefix();
    }

    
};
class UnExp : public Exp{
    public:

    char op;
    Exp* exp;
    UnExp(char opp, Exp* expp): op(opp), exp(expp){}
    float eval(){
        float a = exp->eval();
        
        if ( this->op == '+'){
            return a;
        }else {
            return -(a);
        }
    }
    void printPrefix(){
        if (this->op == '+'){
            exp->printPrefix();
        }else if (this->op == '-'){
            cout<<"-."<<" ";
            exp->printPrefix();
        }
        

    }
    
    
};
class IntLit : public Exp{
    public:
        IntLit(float value) {
            this->v = value;
        }

        float eval(){
            return this->v;
        }
        void printPrefix(){
            cout<<v;
        }
};
