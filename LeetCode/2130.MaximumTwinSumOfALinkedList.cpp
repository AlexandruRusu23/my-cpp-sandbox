
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
    int pairSum(ListNode *head)
    {
        ListNode *first = head;
        ListNode *second = head;

        while (second != nullptr)
        {
            first = first->next;
            second = second->next->next;
        }

        ListNode *tail = first;
        second = first->next;
        tail->next = nullptr;

        while (second != nullptr)
        {
            tail = second;
            second = second->next;
            tail->next = first;
            first = tail;
        }

        int output = 0;
        int sum = 0;

        while (tail != nullptr)
        {
            sum = tail->val + head->val;
            if (sum > output)
                output = sum;

            tail = tail->next;
            head = head->next;
        }

        return output;
    }
};

