#include <bits/stdc++.h>
using namespace std;

class BST
{
    int data;
    BST *left, *right;
public:
    BST(): data(0), left(NULL), right(NULL) {}
    BST(int n): data(n), left(NULL), right(NULL){}

    // basic implementation
    BST* Insert(BST*, int);
    BST* Search(BST*, int);
    BST* DeleteNode(BST*, int);

    // basic implementation
    void InorderRecursion(BST*);

    void InorderIteration(BST*);

    // getter and setter
    int getData(){
        return data;
    }
    BST* getLeft(){
        return left;
    }
    BST* getRight(){
        return right;
    }
    void setData(int n){
        data = n;
    }
    void setLeft(BST* l){
        left = l;
    }
    void setRight(BST* r){
        right = r;
    }

};

BST* BST::Insert(BST* root, int b){
    if ( ! root){
        return new BST(b);
    }
    if ( b > root->getData()){
        root->setRight(Insert(root->getRight(), b));
    
    }else {
        root->setLeft(Insert(root->getLeft(), b));
    }
    return root;
}
BST* BST::Search( BST* root, int key){

    if ( root == nullptr || root->getData() == key){
        return root;
    }
    if ( key > root->getData()){
        return Search(root->getRight(), key);
    }
    return Search(root->getLeft(), key);
}
BST* BST::DeleteNode(BST* root, int keyToDel){
    // Base case
    if ( root == nullptr){
        return root;
    }
    //Recursive call
    if ( keyToDel > root->getData()){
        root->setRight(DeleteNode(root->getRight(), keyToDel));
    }else if ( keyToDel < root->getData()){
        root->setLeft(DeleteNode(root->getLeft(), keyToDel));
    }
    // Reach where the node need to be deleted
    if ( root->getRight() == nullptr){
        BST* tmp = root->getLeft();
        delete root;
        return tmp;
    }else if ( root->getLeft() == nullptr){
        BST* tmp  = root->getRight();
        delete root;
        return tmp;
    }else{
        // case where there are two children
        BST* SucPar = root;
        BST* Suc = root->right;
        while(Suc->getLeft() != nullptr){
            SucPar = Suc;
            Suc = Suc->getLeft();
        }

        if ( SucPar != root){
            SucPar->setLeft(Suc->getRight());
        }else{
            SucPar->setRight(Suc->getRight());
        }
        root->setData(Suc->getData());
        delete Suc;
        return root;
        
    }

}
void BST::InorderRecursion(BST* root){
    if ( ! root){
        return;
    }
    InorderRecursion(root->getLeft());
    cout << root->getData() << endl;
    InorderRecursion(root->getRight());
}

void BST::InorderIteration(BST* root){
    
}



int main (){
    BST b, *root = NULL;
    root = b.Insert(root, 12);
    b.Insert(root, 8);
    b.Insert(root, 30);
    b.Insert(root, 6);
    b.Insert(root, 11);
    b.Insert(root, 7);
    b.Insert(root, 30);
    b.Insert(root, 25);
    b.Insert(root, 19);
    b.Insert(root, 20);
    b.Insert(root, 35);

    cout<<(b.DeleteNode(root, 12));
}