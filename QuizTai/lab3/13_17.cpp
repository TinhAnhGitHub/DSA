#include <iostream>
#include <vector>
using namespace std;

class BSTNode {
public: 
    int val; 
    BSTNode *left; 
    BSTNode *right; 
    BSTNode() {
        this->left = this->right = nullptr;
    } 
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    } 
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    } 
    void addNode(int value){
        if ( value < this->val){
            if ( this->left == nullptr){
                this->left = new BSTNode(value);
            }else{
                this->left->addNode(value);
            }
        }else{
            if(this->right == nullptr){
                this->right = new BSTNode(value);
            }else{
                this->right->addNode(value);
            }
        }
    }

    static BSTNode* createBSTree(int arr[], int size){
        if (size == 0){
            return nullptr;
        }
        BSTNode* root = new BSTNode(arr[0]);
        for ( int i = 1; i < size; i++){
            root->addNode(arr[i]);
        }
        return root;
    }
};

int singleChild(BSTNode* root){
    if(!root){
        return 0;
    }
    int count = 0;
    if((!root->left && root->right) || (root->left && !root->right)){
        count = 1;
    }
    return count + singleChild(root->left) + singleChild(root->right);
}

BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi){
    if(!root){
        return nullptr;
    }
    if ( root->val < lo){
        BSTNode* rightSubTree = subtreeWithRange(root->right, lo, hi);
        delete root;
        return rightSubTree;
    }else if ( root->val > hi){
        BSTNode* leftSubTree = subtreeWithRange(root->left, lo, hi);
        delete root;
        return leftSubTree;
    }

    root->left = subtreeWithRange(root->left, lo, hi);
    root->right = subtreeWithRange(root->right, lo, hi);
    return root;
}
void rangeCountHelper(BSTNode* root, int lo, int hi, int& res){
    if(root){
        rangeCountHelper(root->left, lo, hi, res);
        if(lo<= root->val &&  root->val <= hi){
            res ++;
        }
        rangeCountHelper(root->right, lo, hi, res);
    }
    return;
}
int rangeCount(BSTNode* root, int lo, int hi){
   /* Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements), 
   lo and hi are 2 positives integer and lo ≤ hi. This function returns the number of all nodes whose values 
   are between [lo, hi] in this binary search tree.
    More information:
    TODO: If a node has val which is equal to its ancestor's, it is in the right subtree of its ancestor.*/ 
    int res = 0;
    rangeCountHelper(root, lo, hi, res);
    return res;
}
void helper(BSTNode*root, vector<int>& res){
    if(root){
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }
}

int getHeight(BSTNode* root){
    if(!root){
        return 0;
    }
    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);
    return max(leftH, rightH) + 1;
}

void levelAlterTraverseHelper(BSTNode* root, vector<int>& res, int level, bool left){
    if(!root){
        return;
    }
    if (level == 0){
        res.push_back(root->val);
    }else{
        if(left){
            levelAlterTraverseHelper(root->left, res, level - 1, left);
            levelAlterTraverseHelper(root->right, res, level - 1, left);
        }else{
            levelAlterTraverseHelper(root->right, res, level - 1, left);
            levelAlterTraverseHelper(root->left, res, level - 1, left);
        }
    }
}
vector<int> levelAlterTraverse(BSTNode* root) {
    vector<int>res;
    int heightRoot = getHeight(root);
    for(int i = 0; i < heightRoot; i++){
        levelAlterTraverseHelper(root, res, i, i % 2 == 0);
    }
    return res;
}

int kthSmallest(BSTNode* root, int k) {
    vector<int> res;
    helper(root, res);
    return res[k - 1];
}

void inorderPrint( BSTNode* root){
    if(root){
        inorderPrint(root->left);
        cout<< root->val <<" ";
        inorderPrint(root->right);
    }
    return;
}
void printVector(vector<int> a){
    cout<<"[";
    for( int i = 0; i < a.size() - 1; i++){
        cout<<a[i]<<", ";
    }
    cout<<a[a.size() - 1]<<"]";
}
int main(){
    int arr[] = {0, 3, 5, 1, 2, 4};
    int size = sizeof(arr)/sizeof(int);
    auto root = BSTNode::createBSTree(arr,size);
    cout<<"All elements in the Binary Search Tree(inorder print): ";
    inorderPrint(root);
    cout<<endl;
    cout<<"Sum of all node with single child: "<<singleChild(root)<<endl;
    int lo = 1, hi = 3;
    cout<<"The range given is from "<<lo<<" to "<<hi<<". The BST within this range would be: ";
    inorderPrint(subtreeWithRange(root, lo, hi));
    root = BSTNode::createBSTree(arr,size);
    cout<<"(with the number of nodes satisfied the require field: "<< rangeCount(root, lo,hi)<<")";
    cout<<endl;
    cout<<"The kth smallest value in the BST is: "<<kthSmallest(root,2)<<endl;

    cout<<"LevelAlterTraverse from right to left, down by a level: ";
    printVector(levelAlterTraverse(root));
    cout<<endl;
    return 0;
}




