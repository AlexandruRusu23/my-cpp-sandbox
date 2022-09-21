
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
            return head;

        ListNode *first = head;
        ListNode *second = head->next;
        if (first->val == val)
            head = second;

        while (second != nullptr)
        {
            if (second->val == val)
            {
                if (second == head)
                {
                    head = second->next;
                }
                first->next = second->next;
                second = second->next;
                continue;
            }

            first = first->next;
            second = second->next;
        }

        return head;
    }
};

