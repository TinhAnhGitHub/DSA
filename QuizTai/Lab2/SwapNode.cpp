#include <iostream>
#include <unordered_map>
using namespace std;



struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};


ListNode* init(int* list, int size, unordered_map<ListNode*, int>& nodeValue);
void printList(ListNode* head, const unordered_map<ListNode*, int>& nodeValue);
ListNode* traverse(ListNode* head, int a);
ListNode* reverse(ListNode* head, int a, int b);
void freeMem(ListNode* head);

ListNode*traverse( ListNode* head, int a){
    ListNode* tmp = head;
    for( int i = 1; i < a; i++){
        tmp = tmp->right;
    }
    return tmp;
}

ListNode* reverse( ListNode* head, int a, int b){
    if ( a == b){
        return head;
    }
    if ( a > b){
        swap(a,b);
    }
    ListNode* headF = head;
    ListNode* first = traverse(head, a);
    ListNode* second = traverse(head, b);
    ListNode* firstBef = first;
    ListNode* SecondBef = second;
    ListNode* prev_first;
    ListNode* next_second ;
    while (first != second){
        prev_first = first->left;
        next_second = second->right;
        if ( first->right == second){
            // situation where two swap position is next to each other
            second->right = first;
            first->right = next_second;
            first->left = second;
            second->left = prev_first;
            if ( prev_first){
                prev_first->right = second;
            }
            if ( next_second){
                next_second->left = first;
            }
            second->right->left = second;
            first->left->right = first;
            break;
        }else{
            second->right = first->right;
            first->right = next_second;
            first->left = second->left;
            second->left = prev_first;
            if ( prev_first){
                prev_first->right = second;
            }
            if ( next_second){
                next_second->left = first;
            }
            second->right->left = second;
            first->left->right = first;
        }
        if ( prev_first != nullptr && next_second != nullptr){
                if ( prev_first ){
                    first = prev_first->right;
                    first = first -> right;
                }
                if( next_second){
                    second = next_second->left;
                    second = second-> left;
                }
        }else{
            break;
        }
    }
     if ( firstBef == headF){
        head = second;
    }
    return head;
}


int main (){
    int size;
    cin >> size;
    int* list = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> list[i];
    }
    int a, b;
    cin >> a >> b;
    unordered_map<ListNode*, int> nodeValue;
    ListNode* head = init(list, size, nodeValue);
    ListNode* reversed = reverse(head, a, b);
    try {
        printList(reversed, nodeValue);
    }
    catch(char const* err) {
        cout << err << '\n';
    }
    freeMem(head);
    delete[] list;
}

ListNode* init(int* list, int size, unordered_map<ListNode*, int>& NodeVal){
    if ( size == 0){
        return nullptr;
    }
    ListNode* head = new ListNode(list[0]); // first value of list is head
    NodeVal[head] = list[0];
    ListNode* curr = head;
    for( int i = 1; i < size; i++){
        ListNode* tmp = new ListNode(list[i]);
        NodeVal[tmp] = list[i];

        curr->right = tmp;
        tmp->left = curr;
        curr = tmp;
    }
    return head;
}

void freeMem(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->right;
        delete temp;
    }
}
void printList(ListNode* head, const unordered_map<ListNode*, int>& nodeValue) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << "Value: " << nodeValue.at(current) << " ";
        if (current->right) {
            cout << "-> ";
        }
        current = current->right;
    }
    cout << endl;
}
