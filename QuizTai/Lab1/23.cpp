#include <iostream>
using namespace std;


class LLNode {
    public:
        int val;
        LLNode* next;
        LLNode(){
            this->next = nullptr;
        } // Constructor: val = 0, next = nullptr
        LLNode(int val, LLNode* next){
            this->val = val;
            this->next = next;
        } // Constructor with customized data
};

LLNode* helper(LLNode* head, LLNode* tail, int turn){
    if(turn == 0) return head;
    LLNode* tmp = head;
    while(tmp->next!=tail) tmp = tmp->next;
    tmp->next = nullptr;
    tail->next = head;
    head = tail;
    LLNode* res = helper(head, tmp, turn - 1);
    return res;
}

LLNode* rotateLinkedList(LLNode* head, int k) {
    if(!head) return head;
    int length = 0;
    LLNode* tmp = head;
    while(tmp->next){
        length ++;
        tmp = tmp->next;
    }
    int l = k % (length+1);
    LLNode* res = helper(head, tmp, l);
    return res;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    LLNode* head = new LLNode(1, new LLNode(2, new LLNode(3, new LLNode(4, new LLNode(5, nullptr)))));

    // Print the original linked list
    cout << "Original Linked List: ";
    LLNode* tmp = head;
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;

    // Rotate the linked list by k positions
    int k = 2;
    LLNode* rotatedHead = rotateLinkedList(head, k);

    // Print the rotated linked list
    cout << "Rotated Linked List: ";
    tmp = rotatedHead;
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;

    return 0;
}
