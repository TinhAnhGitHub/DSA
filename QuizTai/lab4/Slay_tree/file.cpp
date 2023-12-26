#include<iostream>
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
    void rotateLeft(Node* x) {
        Node* y = x->pRight;
        x->pRight = y->pLeft;
        if (y->pLeft) {
            y->pLeft->pParent = x;
        }
        y->pParent = x->pParent;
        if (!x->pParent) {
            root = y;
        } else if (x == x->pParent->pLeft) {
            x->pParent->pLeft = y;
        } else {
            x->pParent->pRight = y;
        }
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
        while (p != root) {
            Node* parent = p->pParent;
            if (!parent) {
                // Zig step
                if (p == parent->pLeft) {
                    rotateRight(parent);
                } else {
                    rotateLeft(parent);
                }
            } else {
                Node* grandparent = parent->pParent;
                if (!grandparent) {
                    // Zig step
                    if (p == parent->pLeft) {
                        rotateRight(parent);
                    } else {
                        rotateLeft(parent);
                    }
                } else {
                    // Zig-zig or Zig-zag step
                    if (p == parent->pLeft && parent == grandparent->pLeft) {
                        // Zig-zig step
                        rotateRight(grandparent);
                        rotateRight(parent);
                    } else if (p == parent->pRight && parent == grandparent->pRight) {
                        // Zig-zig step
                        rotateLeft(grandparent);
                        rotateLeft(parent);
                    } else if (p == parent->pLeft && parent == grandparent->pRight) {
                        // Zig-zag step
                        rotateRight(parent);
                        rotateLeft(grandparent);
                    } else if (p == parent->pRight && parent == grandparent->pLeft) {
                        // Zig-zag step
                        rotateLeft(parent);
                        rotateRight(grandparent);
                    }
                }
            }
        }
    }
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;
        while (current) {
            parent = current;
            if (val < current->val) {
                current = current->pLeft;
            } else if (val > current->val) {
                current = current->pRight;
            } else {
                // Duplicate value, insert to the right subtree
                current = current->pRight;
            }
        }

        if (val < parent->val) {
            parent->pLeft = newNode;
        } else {
            parent->pRight = newNode;
        }
        newNode->pParent = parent;

        splay(newNode);

        root = newNode; // Update the root pointer to the newly inserted node
    }

    bool search(int val) {
        Node* foundNode = searchHelper(root, val);
        if (foundNode) {
            // Node found, splay it to the root
            splay(foundNode);
            return true;
        } else {
            // Node not found, splay the last accessed node
            splay(findLastAccessedNode(root, val));
            return false;
        }
    }
    Node* searchHelper(Node* p, int val) {
        if (!p || p->val == val) {
            return p;
        }

        if (val < p->val) {
            return searchHelper(p->pLeft, val);
        } else {
            return searchHelper(p->pRight, val);
        }
    }

    Node* findLastAccessedNode(Node* p, int val) {
        Node* lastAccessed = nullptr;
        while (p) {
            lastAccessed = p; 
            if (val < p->val) {
                p = p->pLeft;
            } else {
                p = p->pRight;
            }
        }
        return lastAccessed;
    }


    Node* remove(int val){
    // Step 1: this->root == NULL? return this->root
        if(!this->root){
            return this->root;
        }

        // Step 2: Find the deleteNode
        Node* foundNode = searchHelper(this->root, val);
        if(!foundNode){
            Node* tmp = findLastAccessedNode(this->root, val);
            
            splay(tmp);
            return nullptr;
        } else {
            splay(foundNode);
        }
        // Step 3: Check if the new this->root's value is equal to val
        if(this->root->val != val ){
            return nullptr;
        }
        // Step 4: Remove this->root

        Node* tree1 = this->root->pLeft;
        if(tree1 ){
            tree1->pParent = nullptr;
        }
        
        Node* tree2 = this->root->pRight;
        if (tree2 != nullptr ){
            tree2->pParent = nullptr;
        }
        
        this->root->pLeft = nullptr;
        this->root->pRight = nullptr;
        this->root = nullptr;
        
        
        Node* maxi;
        if(!tree1){
            this->root = tree2;
            if(this->root->pRight){
                this->root->pRight->pParent = root;
            }
            
        } else {
            // Step 4.1: Find the maximum node in tree1
            
            maxi = findMax(tree1);
            if(maxi == tree1){
                root = maxi;
                
            }else{
                splay(maxi);
                
            }
            maxi->pRight = tree2;
                this->root = maxi;
            if(this->root->pRight){
                this->root->pRight->pParent = root;
            }
                
        }
        return foundNode;
    }

    Node* findMax(Node* p){
        // Check if the input node is nullptr
        if (!p) {
            return p;
        }

        while(p->pRight){
            p = p->pRight;
        }
        return p;
    }
};

int main(){
    SplayTree tree;

    // Test case
    tree.remove(10);
    tree.insert(13);
    tree.insert(6);
    tree.insert(3);
    tree.insert(4);
    tree.remove(15);
    tree.printPreorder(); // Expected output: 13 6 3 4
    tree.printBinaryTree();

    tree.remove(3);
    tree.insert(3);
    tree.remove(11);
    tree.printBinaryTree(); // Expected output:  6
                            //                  └── 13

    tree.remove(5);
    tree.insert(5);
    tree.insert(9);
    tree.remove(4);
    tree.printPreorder(); // Expected output: 6 5 9 13

    return 0;



}