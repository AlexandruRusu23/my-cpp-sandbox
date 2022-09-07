
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* iter = head;
        
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                iter->next = new ListNode(list1->val);
                iter = iter->next;
                list1 = list1->next;
            }
            else
            {
                iter->next = new ListNode(list2->val);
                iter = iter->next;
                list2 = list2->next;
            }
        }
        
        if (list1 != nullptr)
            iter->next = list1;
        
        if (list2 != nullptr)
            iter->next = list2;
        
        return head->next;
    }
};
