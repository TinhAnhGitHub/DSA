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

    Node* rotateLeft(Node* subroot){
        Node* newRoot = subroot->pRight;
        Node* newSubTree = newRoot->pLeft;
        newRoot->pLeft = subroot;
        subroot->pRight = newSubTree;
        return newRoot;
    }
    Node* rotateRight(Node* subroot){
        Node* newRoot = subroot->pLeft;
        Node* newSubTree = newRoot->pRight;
        newRoot->pRight = subroot;
        subroot->pLeft = newSubTree;
        return newRoot;
    }

    int getBalance (Node* root){
        if(!root){
            return 0;
        }
        return getHeightRec(root->pLeft) - getHeightRec(root->pRight);
    }

    Node* BalancingTree(Node* root){
        int BalancingNum = this->getBalance(root);
        if( BalancingNum > 1 && root->pLeft->pLeft){
            return rotateRight(root);
        }else if (BalancingNum > 1 && !(root->pLeft->pLeft)){
            root->pLeft = rotateLeft(root->pLeft);
            return rotateRight(root);
        }else if ( BalancingNum < -1 && root->pRight->pRight){
            return rotateLeft(root);
        }else if (BalancingNum < -1 && !(root->pRight->pRight)){
            root->pRight = rotateRight(root->pRight);
            return rotateLeft(root);
        }
        return root;
    }

    Node* removeRec(Node* root, const T& val){
        if(!root){
            return nullptr;
        }
        if(val < root->data){
            root->pLeft = this->removeRec(root->pLeft, val);
            return BalancingTree(root);
        }else if ( val > root->data){
            root->pRight = this->removeRec(root->pRight, val);
            return BalancingTree(root);
        }

        if(!root->pLeft){
            Node* tmp = root->pRight;
            root->pRight = nullptr;
            delete root;
            return BalancingTree(tmp);
        }else if (!root->pRight){
            Node* tmp = root->pLeft;
            root->pLeft = nullptr;
            delete root;
            return BalancingTree(tmp);
        }else{
            Node* sucPa = root;
            Node* suc   = root->pLeft;
            while(suc->pRight){
                sucPa = suc;
                suc = suc->pRight;
            }
            if(sucPa != root){
                sucPa->pRight = suc->pLeft;
            }else{
                sucPa->pLeft = suc->pLeft;
            }
            root->data = suc->data;
            suc->pLeft = suc->pRight = nullptr;
            delete suc;
        }
        if(!root){
            return root;
        }
        root->pLeft = BalancingTree(root->pLeft);
        root->pRight = BalacingTree(root->pRight);
        return BalancingTree(root);
    }
    void remove(const T &value)
    {
        this->root = removeRec(root, value);
    }

    int checkBalance(Node* root){
        if (!root){
            return 0;
        }
        return this->getHeightRec(root->pLeft) - this->getHeightRec(root->pRight);
    }
    Node* BalancingTree2(Node* root, const T& val){
        int BalancingNum = this->checkBalance(root);
        if(BalancingNum > 1 && val < root->pLeft->data){
            return rotateRight(root);
        }else if ( BalancingNum > 1 && val >= root->pLeft->data){
            root->pLeft = rotateLeft(root->pLeft);
            return rotateRight(root);
        }else if ( BalancingNum < -1 && val >= root->pRight->data){
            return rotateLeft(root);
        }else if ( BalancingNum < -1 && val < root->pRight->data){
            root->pRight = rotateRight(root->pRight);
            return rotateLeft(root);
        }
        return root;
    }
    Node* insertHelper(Node* root, const T& val){
        if(!root){
            //* if root is null add new Node;
            return new Node(val);
        }
        if ( root->data > val){
            root->pLeft = insertHelper(root->pLeft, val);
        }else {
            root->pRight = insertHelper(root->pRight, val); 
        }
        return BalancingTree2(root, val);
    }
    void insert(const T &value)
    {
        this->root = insertHelper(root, value);
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

int main (){
	
AVLTree<int> avl;
int arr[] = {20,10,40,5,7,42,2};
for (int i = 0; i < 7; i++){
    avl.insert(arr[i]);
}
avl.printTreeStructure();
avl.remove(20);
avl.printTreeStructure();
}