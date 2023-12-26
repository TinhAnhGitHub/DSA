    #include <iostream>
    using namespace std;

    class Eval;
    class PrintPrefix;
    class PrintPostfix;

    class VisitorInt;
    class VisitorVoid; 
    class BinExp;
    class UnExp;
    class IntLit; 

    class Exp{
        public:
            int v;
            virtual int accept(VisitorInt* ) = 0;
            virtual void accept(VisitorVoid* ) = 0;
    };


    class VisitorVoid{
        public:     
            virtual void visit(IntLit* ) = 0;
            virtual void visit(UnExp * ) = 0;
            virtual void visit(BinExp * ) = 0;
    };
    class VisitorInt{
        public:
            virtual int visit(IntLit* ) = 0;
            virtual int visit(UnExp* ) = 0;
            virtual int visit(BinExp* ) = 0;
    };


    class Eval : public VisitorInt{
        public:
        

            int visit(IntLit* k );
            int visit(UnExp* k);

            int visit(BinExp* k);
    };


    class PrintPrefix : public VisitorVoid{
        public: 
            void visit( IntLit* k);
            void visit(UnExp* k);
            void visit( BinExp * k);     
    };

    class PrintPostfix : public VisitorVoid{
        public:
            void visit( IntLit* k);
            void visit ( UnExp* k);
            void visit( BinExp * k);

    };


    class BinExp : public Exp{
        public:
        
        Exp* left;
        char op;
        Exp* right;
        
        
        BinExp(Exp* leftt, char opp, Exp* rightt) : left(leftt), op(opp), right(rightt){}
        int accept( VisitorInt* visitorr){
            return visitorr->visit(this);
        }
        void accept( VisitorVoid* visitorr){
            visitorr->visit(this);
        }
        
        

        
    };
    class UnExp : public Exp{
        public:

            char op;
            Exp* exp;
            UnExp(char opp, Exp* expp): op(opp), exp(expp){ v = 0;}
            
            void accept( VisitorVoid* visitorr ){
                visitorr->visit(this);
            }  
            int accept( VisitorInt* visitorr){
                return visitorr->visit(this);
            }
            
    };
    class IntLit : public Exp{
        public:
            IntLit(int value) {
                this->v = value;
            }
            void accept( VisitorVoid* visitorr ){
                visitorr->visit(this);
            }  
            int accept( VisitorInt* visitorr){
                return visitorr->visit(this);
            } 
            

            
    };

    /* * *  Class method implementation * * */
    //* Class eval
    int Eval::visit(IntLit* k){
            return k->v;
    }
    int Eval::visit(UnExp* k){
        if ( k->op == '-'){
            return -(k->exp->accept(this));
        }
        return k->exp->accept(this);
    }
    int Eval::visit(BinExp* k){
        int res = 0;
                int v1 = k->left->accept(this);
                int v2 = k->right->accept(this);
                char operation = k->op;
                if ( operation == '+'){
                res =  v1 + v2;
                }else if ( operation == '-'){
                    res = v1 - v2;
                }else if ( operation == '*'){
                    res = v1 * v2;
                }else {
                    res = v1 / v2;
                }
                return res;
    }
    //* End class Eval

    //TODO: Class PrintPrefix
    void PrintPrefix::visit( IntLit* k){
        cout << k->v;
    }
    void PrintPrefix::visit( UnExp* k){
        if ( k->op == '-'){
                cout<<"-.";
            }
            k->exp->accept(this);
    }
    void PrintPrefix::visit( BinExp* k){
        string tmp = "";
                if ( k->op == '+'){
                    tmp = "+";
                }else if ( k->op == '-'){
                tmp = "-";
                }else if ( k->op == '*'){
                    tmp = "*";
                }else {
                    tmp = "/";
                }
                cout<<tmp<<" ";
                k->left->accept(this);
                cout<<" ";
                k->right->accept(this);
    }
    //TODO: End class PrintPrefix

    //TODO: Class PrintPostFix implementation
    void PrintPostfix::visit( IntLit* k){
        cout<< k->v;
    }
    void PrintPostfix::visit(UnExp* k){
        if ( k->op == '-'){
                    cout<<"-.";
                }
        k->exp->accept(this);
    }
    void PrintPostfix::visit(BinExp* k){
        string tmp = "";
                if ( k->op == '+'){
                    tmp = "+";
                }else if ( k->op == '-'){
                tmp = "-";
                }else if ( k->op == '*'){
                    tmp = "*";
                }else {
                    tmp = "/";
                }
                
                k->left->accept(this);
                cout<<" ";
                k->right->accept(this);
                cout<<" "<<tmp;
    }
    //TODO: End PrintPostfix implementation




    /* * * End class method Implementation*/
    int main (){
    
        VisitorVoid* evaluation = new PrintPrefix();
        Exp* v1 = new IntLit(5);
        Exp* v2 = new IntLit(6);
        BinExp* equation = new BinExp(v1, '+', v2);
        equation->accept(evaluation);
        



    }


