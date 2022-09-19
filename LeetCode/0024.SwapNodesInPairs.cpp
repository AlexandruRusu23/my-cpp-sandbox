
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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode *prev = new ListNode(0, head);
        ListNode *first = head;
        ListNode *second = head->next;
        head = prev;

        while (first != nullptr && second != nullptr)
        {
            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
            first = first->next;
            if (first != nullptr)
                second = first->next;
        }

        return head->next;
    }
};

