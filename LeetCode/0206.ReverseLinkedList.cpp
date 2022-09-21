
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *newHead = head;
        ListNode *first = head;
        ListNode *second = head->next;
        first->next = nullptr;

        while (second != nullptr)
        {
            first = second->next;
            second->next = newHead;
            newHead = second;
            second = first;
            first = newHead;
        }

        return newHead;
    }
};

