
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr)
            return true;
        
        ListNode* first = head;
        ListNode* second = head;
        
        while (second != nullptr && second->next != nullptr)
        {
            first = first->next;
            second = second->next->next;
        }
        
        if (second != nullptr)
            first = first->next;
        
        ListNode* tail = first;
        second = first->next;
        tail->next = nullptr;
        
        while (second != nullptr)
        {
            tail = second;
            second = second->next;
            tail->next = first;
            first = tail;            
        }
        
        while (tail != nullptr)
        {
            if (tail->val != head->val)
                return false;
            
            tail = tail->next;
            head = head->next;
        }
        
        return true;
    }
};

