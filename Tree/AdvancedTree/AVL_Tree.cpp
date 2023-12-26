#include <iostream>
#include <cmath>
using namespace std;

template <typename E>
class BSTNode {
public:
    E val;
    BSTNode* left;
    BSTNode* right;
    int height;
    BSTNode() {
        this->left = this->right = nullptr;
    } 
    BSTNode(E val) {
        this->val = val;
        this->left = this->right = nullptr;
    } 
    BSTNode(E val, int height){
        this->val = val;
        this->height = height;
        this->left = this->right = nullptr;
    }
    BSTNode(E val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

template<typename E>
class AVLTree {
public:
    BSTNode<E>* root = nullptr;
public:
    int height(BSTNode<E>* node) {
        if (!node) {
            return 0;
        }
        return node->height;
    }
    void updateHeight(BSTNode<E>* root) {
        root->height = 1 + max(height(root->left), height(root->right));
    }
    BSTNode<E>* rightRotate(BSTNode<E>* root) {
        BSTNode<E>* LeftNode = root->left;
        BSTNode<E>* RightOfLeftNode = LeftNode->right;
        LeftNode->right = root;
        root->left = RightOfLeftNode;
        updateHeight(root);
        updateHeight(LeftNode);
        return LeftNode;
    }
    BSTNode<E>* leftRotate(BSTNode<E>* root) {
        BSTNode<E>* rightNode = root->right;
        BSTNode<E>* leftOfRightNode = rightNode->left;
        rightNode->left = root;
        root->right = leftOfRightNode;
        updateHeight(root);
        updateHeight(rightNode);
        return rightNode;
    }
    int getBalance(BSTNode<E>* root) {
        if (root == nullptr) {
            return 0;
        }
        return height(root->left) - height(root->right);
    }
    BSTNode<E>* reBalance(BSTNode<E>* root, E key) {
        int balance = getBalance(root);
        if (balance > 1 && key < root->left->val) {
            return rightRotate(root);
        }
        if (balance < -1 && key > root->right->val) {
            return leftRotate(root);
        }
        if (balance > 1 && key > root->left->val) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && key < root->right->val) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    BSTNode<E>* insertNode(BSTNode<E>* root, E key) {
        if (!root) {
            return new BSTNode<E>(key, 1);
        }
        if (key < root->val) {
            root->left = insertNode(root->left, key);
        } else if (key > root->val) {
            root->right = insertNode(root->right, key);
        } else {
            return root;
        }
        updateHeight(root);
        return reBalance(root, key);
    }

    void addNode(E key) {
        this->root = insertNode(this->root, key);
        return;
    }

    BSTNode<E>* deleteNode(BSTNode<E>* root, E key) {
        if (!root) {
            return nullptr;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left) {
                BSTNode<E>* tmp = root->right;
                delete root;
                return tmp;
            } else if (!root->right) {
                BSTNode<E>* tmp = root->left;
                delete root;
                return tmp;
            } else {
                BSTNode<E>* sucPa = root;
                BSTNode<E>* succ = root->right;
                while (succ->left) {
                    sucPa = succ;
                    succ = succ->left;
                }
                if (sucPa != root) {
                    sucPa->left = succ->right;
                } else {
                    sucPa->right = succ->right;
                }
                root->val = succ->val;
                delete succ;
            }
        }

        updateHeight(root);
        return reBalance(root, key);
    }

    void removeNode(E key) {
        this->root = deleteNode(this->root, key);
        return;
    }
};

template <typename E>
void inOrder(BSTNode<E>* root) {
    if (root) {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

int main() {
    AVLTree<int>* tree = new AVLTree<int>;
    tree->addNode(10);
    tree->addNode(1);
    tree->addNode(20);
    tree->addNode(5);
    tree->addNode(2);
    tree->addNode(4);
    tree->addNode(30);
    tree->addNode(40);
    tree->addNode(25);
    tree->addNode(22);
    inOrder(tree->root);
    tree->removeNode(5);



    return 0;
}
