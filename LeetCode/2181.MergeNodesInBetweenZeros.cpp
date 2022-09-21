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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *first = head->next;
        ListNode *second = first->next;

        while (second != nullptr)
        {
            if (second->val != 0)
            {
                first->val += second->val;
                second = second->next;
            }
            else
            {
                first->next = second->next;
                first = second->next;
                if (first != nullptr)
                    second = first->next;
                else
                    break;
            }
        }

        return head->next;
    }
};

