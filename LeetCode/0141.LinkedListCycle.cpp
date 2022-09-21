
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {

        ListNode *iter = head;
        ListNode *diter = head;

        while (diter != nullptr && diter->next != nullptr)
        {
            iter = iter->next;
            diter = diter->next->next;

            if (iter == diter)
                return true;
        }

        return false;
    }
};

