#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    void remove(const T &value)
    {
        this->root = removeRec(root, value);
    }

    Node* removeRec(Node* root, const T &value){

        // * the deletion of AVL tree is like BST tree, but we get the balance latter
        if(!root){
            return root;
        }
        if (value < root->data){
            root->pLeft = removeRec(root->pLeft, value);
            
            return BalancingTree2(root);
        }else if ( value > root->data){
            root->pRight = removeRec(root->pRight, value);
            return BalancingTree2(root);
        }

        if(!root->pLeft){
            Node* tmp = root->pRight;
            root->pRight = nullptr;
            delete root;
            return BalancingTree2(tmp);
        }else if (!root->pRight){
            Node* tmp = root->pLeft;
            root->pLeft = nullptr;
            delete root;
            return BalancingTree2(tmp);
        }else{
            Node* sucPa = root;
            Node* succ  = root->pLeft;
            while(succ->pRight){
                sucPa = succ;
                succ = succ->pRight;
            }
            if(sucPa != root){
                sucPa->pRight = succ->pLeft;
            }else{
                sucPa->pLeft = succ->pLeft;
            }
            root->data = succ->data;
            succ->pRight = succ->pLeft = nullptr;
            delete succ;
        }
        root->pLeft = BalancingTree2(root->pLeft);
        root->pRight = BalancingTree2(root->pRight);
        return BalancingTree2(root);
    }


    int getBalance(Node* root){
        if(!root){
            return 0;
        }
        return this->getHeightRec(root->pLeft) - this->getHeightRec(root->pRight);
    }
    Node* rotateLeft(Node* node){
        Node* newRoot = node->pRight;
        Node* newRootLeftSubTree = newRoot->pLeft;
        newRoot->pLeft = node;
        node->pRight = newRootLeftSubTree;
        return newRoot;
    }
    Node* rotateRight(Node* node){
        Node* newRoot = node->pLeft;
        Node* newRootRightSubTree = newRoot->pRight;
        newRoot->pRight = node;
        node->pLeft = newRootRightSubTree;
        return newRoot;
    }


    void insert(const T& value){
        this->root = this->insertion(root,value);
    }

    Node* BalancingTree(Node* root, const T& val){
        int balancing = this->getBalance(root);
        if(balancing > 1 && (val < root->pLeft->data)){
            return rotateRight(root);
        }else if ( balancing > 1 && (val >= root->pLeft->data)){
            root->pLeft = rotateLeft(root->pLeft);
            return rotateRight(root);
        }else if ( balancing < -1 && ( val >= root->pRight->data)){
            return rotateLeft(root);
        }else if ( balancing < -1 && ( val < root->pRight->data)){
            root->pRight = rotateRight(root->pRight);
            return rotateLeft(root);
        }
        return root;
    }
    Node* BalancingTree2(Node*root){
        int balancing = this->getBalance(root);
        if(balancing > 1 && ( root->pLeft->pLeft)){
            return rotateRight(root);
        }else if ( balancing > 1 && (!root->pLeft->pLeft)){
            root->pLeft = rotateLeft(root->pLeft);
            return rotateRight(root);
        }else if ( balancing < -1 && ( root->pRight->pRight)){
            return rotateLeft(root);
        }else if ( balancing < -1 && ( !root->pRight->pRight)){
            root->pRight = rotateRight(root->pRight);
            return rotateLeft(root);
        }
        return root;
    }
    Node* insertion(Node* root, const T& val){
        if(!root){
            return new Node(val);
        }
        if (val < root->data){
            root->pLeft = insertion(root->pLeft, val);
        }else if (val >= root->data){
            root->pRight = insertion(root->pRight, val);
        }
        return BalancingTree(root, val);
    }

    

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};

int main(){
    	
    AVLTree<int> avl;
    int arr[] = {20,10,40,5,7,42,2};
    for (int i = 0; i < 7; i++){
        avl.insert(arr[i]);
    }
    avl.printTreeStructure();
    avl.remove(20);
    avl.printTreeStructure();
}