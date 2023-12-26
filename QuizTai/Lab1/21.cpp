class LLNode {
    public:
        int val;
        LLNode* next;
        LLNode();
        LLNode(int val, LLNode* next);

};




LLNode* addLinkedList(LLNode* l1, LLNode* l2) {
     LLNode* result = nullptr;
        LLNode* tail = nullptr;
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            int digit = sum % 10;
            carry = sum / 10;
            
            LLNode* newNode = new LLNode(digit, nullptr);
            
            if (result == nullptr) {
                result = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        
        return result;
}