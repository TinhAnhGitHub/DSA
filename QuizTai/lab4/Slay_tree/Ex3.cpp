#include <iostream>
using namespace std;


class SplayTree {
    public: 
    struct Node {
        int val;
        Node* pLeft;
        Node* pRight;
        Node* pParent;
        Node(int val = 0, Node* l = nullptr, Node* r = nullptr, Node* par = nullptr) : val(val), pLeft(l), pRight(r), pParent(par) { }
    };
    Node* root;

    // print the tree structure for local testing
    void printBinaryTree(string prefix, const Node* root, bool isLeft, bool hasRightSibling) {
        if (!root && isLeft && hasRightSibling) {
            cout << prefix << "├──\n";
        }
        if (!root) return;
        cout << prefix;
        if (isLeft && hasRightSibling) 
            cout << "├──";
        else 
            cout << "└──";
        cout << root->val << '\n';
        printBinaryTree(prefix + (isLeft && hasRightSibling ? "|  " : "   "), root->pLeft, true, root->pRight);
        printBinaryTree(prefix + (isLeft && hasRightSibling ? "|  " : "   "), root->pRight, false, root->pRight);
    }

    void printPreorder(Node* p) {
        if (!p) {
            return;
        }
        cout << p->val << ' ';
        printPreorder(p->pLeft);
        printPreorder(p->pRight);
    }
public:
    SplayTree() {
        root = nullptr;
    }
    ~SplayTree() {
        // Ignore deleting all nodes in the tree
    }

    void printBinaryTree() {
        printBinaryTree("", root, false, false);
    }

    void printPreorder() {
        printPreorder(root);
        cout << "\n";
    }
    //* Rotation 
    void rotateLeft(Node* x) {
        Node* y = x->pRight;
        x->pRight = y->pLeft;
        if(y->pLeft){
            y->pLeft->pParent = x;
        }
        y->pParent = x->pParent;
        //* If x->parent is null, then y is root
        if(!x->pParent){
            root = y;
        }
        else if(x == x->pParent->pLeft){
            x->pParent->pLeft = y;
        }else{
            x->pParent->pRight = y;
        }
        //* Turn x into a child of y
        y->pLeft = x;
        x->pParent = y;
    }

    // Helper function to perform a right rotation
    void rotateRight(Node* x) {
        Node* y = x->pLeft;
        x->pLeft = y->pRight;
        if (y->pRight) {
            y->pRight->pParent = x;
        }
        y->pParent = x->pParent;
        if (!x->pParent) {
            root = y;
        } else if (x == x->pParent->pLeft) {
            x->pParent->pLeft = y;
        } else {
            x->pParent->pRight = y;
        }
        y->pRight = x;
        x->pParent = y;
    }
    void splay(Node* p) {
        while(p != root){
            Node* parent = p->pParent;
            if(!p->pParent){
                //* if parent is null, then it is already a root node;
                return;
            }else{
                Node* grandParent = parent->pParent;
                if(!grandParent){
                    //* If no grandparent-> single rotation
                    if(p == parent->pLeft){
                        this->rotateRight(parent);
                    }else{
                        this->rotateLeft(parent);
                    }
                }else{
                    if(p == parent->pRight && parent == grandParent->pRight){
                        //* Right-Right case
                        rotateLeft(grandParent);
                        rotateLeft(parent);
                    }else if( p == parent->pRight && parent == grandParent->pLeft){
                        rotateLeft(parent);
                        rotateRight(grandParent);
                    }else if (p == parent->pLeft && parent == grandParent->pLeft){
                        rotateRight(grandParent);
                        rotateRight(parent);
                    }else if( p == parent->pLeft && parent == grandParent->pRight){
                        rotateRight(parent);
                        rotateLeft(grandParent);
                    }
                }       
            }
        }
    }
    void insert(int val) {
        Node* newNode = new Node(val);
        if(!root){
            root = newNode;
            return;
        }
        Node* curr = root;
        Node* parent = nullptr;
        while(curr){
            parent = curr;
            if(val < curr->val){
                curr = curr->pLeft;
            }else{
                curr = curr->pRight;
            }
        }

        if( val < parent->val){
            parent->pLeft = newNode;
        }else{
            parent->pRight = newNode;
        }
        newNode->pParent = parent;
        splay(newNode);
        root = newNode;
    }

    Node* searchHelper(Node* node, int val){
        if(!node || node->val == val){
            return node;
        }
        if(val < node->val){
            return searchHelper(node->pLeft, val);
        }else{
            return searchHelper(node->pRight, val);
        }
        
    }

    Node* findLastAccessed(Node* p, int val){
        Node* lastAcc = nullptr;
        while(p){
            lastAcc = p;
            if(val < p->val){
                p = p ->pLeft;
            }else{
                p = p->pRight;
            }
        }
        return lastAcc;
    }

    bool search(int val) {
    Node* foundNode = searchHelper(root, val);
    if (foundNode) {
        // Node found, splay it to the root
        splay(foundNode);
        return true;
    } else {
        // Node not found, splay the last accessed node
        splay(findLastAccessed(root, val));
        return false;
    }
}
};
int main(){
    SplayTree tree;
    int arr[] = {95,200,80};
    for(int i = 0; i < 3; i++){
        tree.insert(arr[i]);
    }
    tree.printBinaryTree();
    tree.search(100);
    tree.printBinaryTree();
}