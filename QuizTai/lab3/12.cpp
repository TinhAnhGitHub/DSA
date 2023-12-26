#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class BinarySearchTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
        deleteDes(root);
    }

    //Helping function
    void deleteDes(Node*root){
        if(root){
            deleteDes(root->pLeft);
            deleteDes(root->pRight);
            root->pLeft = nullptr;
            root->pRight = nullptr;
            delete root;
        }
        return;
    }
    Node* addHelper(Node* root, T value){
        if(!root){
            return new Node(value);
        }
        if(root->value > value){
            root->pLeft = addHelper(root->pLeft, value);
        }else{
            root->pRight = addHelper(root->pRight, value);
        }
        return root;
    }
    void add(T value){
        this->root = this->addHelper(root,value);
    }

    Node* deleteNodeHelper(Node*root, T value){
        if(!root){
            return nullptr;
        }
        if(root->value > value){
            root->pLeft = deleteNodeHelper(root->pLeft, value);
            return root;
        }else if (root->value < value){
            root->pRight = deleteNodeHelper(root->pRight, value);
            return root;
        }
        
        if(!root->pLeft){
            Node* rightSubTree = root->pRight;
            root->pRight = nullptr;
            delete root;
            return rightSubTree;
        }else if ( !root->pRight){
            Node* leftSubTree = root->pLeft;
            root->pLeft = nullptr;
            delete root;
            return leftSubTree;
        }else{
            Node* succParent = root;
            Node* succ = root->pRight;
            while(succ->pLeft){
                succParent = succ;
                succ = succ->pLeft;
            }
            if(succParent != root){
                succParent->pLeft = succ->pRight;
            }else{
                succParent->pRight = succ->pRight;
            }
            root->value = succ->value;
            succ->pRight = succ->pLeft = nullptr;
            delete succ;
        }
        return root;
    }
    void deleteNode(T value){
        this->root = deleteNodeHelper(this->root, value);
    }
    string inOrderRec(Node* root) {
        stringstream ss;
        if (root != nullptr) {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }
    
    string inOrder(){
        return inOrderRec(this->root);
    }
    
    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;
    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
};

int main(){
    BinarySearchTree<int> bst;
    bst.add(9);
    bst.add(2);
    bst.add(10);
    bst.add(8);
    cout << bst.inOrder()<<endl;
    bst.add(11);
    bst.deleteNode(9);
    cout << bst.inOrder();
}