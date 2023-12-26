#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
        this->deleteNode(root);
    }
    class Node
    {
    private:
        K key;
        V value;
        Node* pLeft, * pRight;
        friend class BinaryTree<K, V>;
    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    void deleteNode(Node* root){
        if(root){
            deleteNode(root->pLeft);
            deleteNode(root->pRight);
            delete root;
        }
        return;
    }
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }
    int getHeightHelper(Node* node){
        if(node){
            return 0;
        }
        int lengthLeft = getHeightHelper(node->pLeft);
        int lengthRight = getHeightHelper(node->pRight);
        return max(lengthLeft, lengthRight) + 1;
    }  
    int getHeight(){
        return this->getHeightHelper(this->root);
    }

    void preOrderHelper(Node* node, ostringstream& os){
        if(node){
            os << node->value<<" ";
            preOrderHelper(node->pLeft, os);
            preOrderHelper(node->pRight, os);
        }
    }

    string preOrder(){
        ostringstream os;
        this->preOrderHelper(this->root, os);
        return os.str();
    }

    void inOrderHelper(Node* node, ostringstream& res){
        if ( node){
            inOrderHelper(node->pLeft, res);
            res << node->value<<" ";
            inOrderHelper(node->pRight, res);
        }
    }
    string inOrder() {
        // TODO: return the sequence of values of nodes in in-order.
        ostringstream res;
        inOrderHelper(root, res);
        return res.str();
    }

    void postOrderHelper(Node* node, ostringstream& res){
        if ( node){
            postOrderHelper(node->pLeft,res);
            postOrderHelper(node->pRight, res);
            res << node->value<<" ";
        }
    }
    string postOrder() {
        // TODO: return the sequence of values of nodes in post-order.
        ostringstream res;
        postOrderHelper(root, res);
        return res.str(); 
    }
};

int main (){
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("",2, 4);
    binaryTree.addNode("L",3, 6);
    binaryTree.addNode("R",5, 9);
    binaryTree.addNode("LL",4, 10);
    binaryTree.addNode("LR",6, -3);
    binaryTree.addNode("LLL",7, 2);
    binaryTree.addNode("LLLR",8, 7);
    binaryTree.addNode("RR",9, 30);
    binaryTree.addNode("RL",10, 307);
    binaryTree.addNode("RLL",11, 2000);
    binaryTree.addNode("RLR",12, 2000);

        cout << binaryTree.getHeight() << endl;
        cout << binaryTree.preOrder() << endl;
        cout << binaryTree.inOrder() << endl;
        cout << binaryTree.postOrder() << endl;
}