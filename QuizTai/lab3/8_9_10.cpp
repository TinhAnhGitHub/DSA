#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;


class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 
        static BTNode* createTree(int* start, int* end, int value[]){
            unordered_map<int, BTNode*> node;
            /*
            Example:

            int arr[] = {-1,0,0,2,2};
            int value[] = {3,5,2,1,4};
            BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
            arr[0]=-1 means the Node containing the value value[0]=3 will be the root Node. 
            Also, since arr[1]=arr[2]=0, it implies that the Nodes containing the values value[1]=5 
            and value[2]=2 will have the Node containing the value value[0]=3 as their parent. 
            Lastly, since arr[3]=arr[4]=2, it means the Nodes containing the values value[3]=1 and 
            value[4]=4 will have the Node with the value value[2]=2 as their parent. 
            Final tree of this example are shown in the figure above.
            
            Note that whichever Node appears first in the arr sequence will be the left Node, and the TestCase always ensures that the resulting tree is a binary tree.
            */

           for( int i = 0; start + i != end; i++){
            node[i] = new BTNode(value[i]);
            //  node[0] = 3 ; node[1] = 5,...
           }
           BTNode* root = nullptr;
           for(int i = 0; start + i != end; i++){
            int parentIndex = *(start + i);
            if (parentIndex == -1){
                root = node[i];
            }else{
                if (node[parentIndex]->left == nullptr){
                    node[parentIndex]->left = node[i];
                }else{
                    node[parentIndex]->right = node[i];
                }
            }
        }
        return root;
    }
};

int longestPathSum(BTNode* root){
    /*
    Request: Implement function:

    int longestPathSum(BTNode* root);

    Where root is the root node of given binary tree (this tree has between 1 and 100000 elements). 
    This function returns the sum of the largest path from the root node to a leaf node. 
    If there are more than one equally long paths, return the larger sum.
    */
    if(!root){
        return 0;
    }
    int maxLength = 0;
    int maxSum = 0;
    stack<pair<BTNode*,pair<int,int>>> stk; // <node,<length,value_previous + curr->val>>
    stk.push({root,{1,root->val}});
    while(!stk.empty()){
        BTNode* curr = stk.top().first;
        int length = stk.top().second.first;
        int sum = stk.top().second.second;
        stk.pop();
        if(!curr->left && !curr->right){
            // reach leave node, compare the length and sum with MaxLength and MaxSUm
            if( (length > maxLength) || (length == maxLength && sum > maxSum)){
                maxLength = length;
                maxSum = sum;
            }
        }
        if(curr->left){
            stk.push({curr->left, {length + 1, sum + curr->left->val}});
        }
        if(curr->right){
            stk.push({curr->right, {length + 1, sum + curr->right->val}});
        }
    }
    return maxSum;
}
int lowestAncestor(BTNode* root, int a, int b){
    /*
    Request: Implement function:

    int lowestAncestor(BTNode* root, int a, int b);
    Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). 
    This function returns the lowest ancestor node's val of node a and node b in this binary tree 
        (assume a and b always exist in the given binary tree).

    More information:

    - A node is called as the lowest ancestor node of node a and node b if node a and node b are its descendants.

    - A node is also the descendant of itself.

    - On the given binary tree, each node's val is distinguish from the others' val
    */
    if(!root){
        return -1;
    }  
    if(root->val == a || root->val == b){
        return root->val;
    }  
    int leftA = lowestAncestor(root->left, a, b);
    int rightA = lowestAncestor(root->right, a, b);
    if( leftA != -1 &&  rightA != -1){
        return root->val;
    }
    return (leftA != -1)? leftA : rightA;
    
}

int sumDigitPath(BTNode* root){
    /*
    Request: Implement function:

    int sumDigitPath(BTNode* root);
    Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). 
    This function returns the sum of all digit path numbers of this binary tree 
    (the result may be large, so you must use mod 27022001 before returning).

    More information:

    - A path is called as digit path if it is a path from the root node to the leaf node of the binary tree.

    - Each digit path represents a number in order, each node's val of this path is a digit of this number, 
    while root's val is the first digit.
    */
   const int MOD = 27022001;
    if(!root){
        return 0;
    }
    int sum = 0;
    stack<pair<BTNode*, int>> stk;
    stk.push({root, 0});
    while(!stk.empty()){
        BTNode* curr = stk.top().first;
        int pathVal = stk.top().second;
        stk.pop();
        pathVal = (pathVal * 10 + curr->val) %  MOD;
        if(!curr->left && !curr->right){
            // reach leaf nodes
            sum = (sum + pathVal) % MOD;
        }
        if(curr->left){
            stk.push({curr->left, pathVal});
        }
        if(curr->right){
            stk.push({curr->right, pathVal});
        }
    }
    return sum;
}

int main (){
    int arr[] = {-1,0,0,2,2,3,3,5};
    int value[] = {1,5,4,7,12,4,8,2};
    BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
    cout << longestPathSum(root)<<endl; // 8
    int arr2[] = {-1,0,0,2,2,3,3}; 
    int value2[] = {0,1,2,3,4,5,6};
    auto root2 = BTNode::createTree(arr2, arr2 + sizeof(arr2) / sizeof(int), value2);
    cout<< lowestAncestor(root2, 4, 5);//9
    cout<<endl;

    int arr3[] = {-1,0,0,2,2};
    int value3[] = {3,5,2,1,4};
    BTNode* root3 = BTNode::createTree(arr3, arr3 + sizeof(arr3)/sizeof(int), value3);
    cout<<sumDigitPath(root3)<<endl; //10

}