
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *second = node->next;
        node->val = second->val;
        node->next = second->next;
        delete second;
    }
};

