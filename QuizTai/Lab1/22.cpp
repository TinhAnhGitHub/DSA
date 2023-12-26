class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
};


LLNode* reverseLL ( LLNode* head , LLNode* tmp){
    if ( !head){
        return tmp;
    }
    LLNode* tmp2 = head->next;
    head->next = tmp;
    return reverseLL( tmp2, head);
}

LLNode* reverseLinkedList(LLNode* head) {
    // STUDENT ANSWER
    return reverseLL(head, nullptr);
}