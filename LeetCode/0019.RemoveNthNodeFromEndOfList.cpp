
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* first = head;
        ListNode* second = head;
        
        while (second != nullptr)
        {
            if (n <= 0)
            {
                prev = first;
                first = first->next;
            }
            
            second = second->next;
            n--;
        }
        
        if (prev == nullptr)
        {
            head = head->next;
        }
        else
        {
            prev->next = first->next;
        }
        
        return head;
    }
};

