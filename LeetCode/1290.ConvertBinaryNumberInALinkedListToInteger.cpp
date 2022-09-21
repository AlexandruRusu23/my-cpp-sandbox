
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
    int getLength(ListNode *head)
    {
        int output = 0;

        while (head != nullptr)
        {
            output++;
            head = head->next;
        }

        return output;
    }

    int getDecimalValue(ListNode *head)
    {
        int sz = getLength(head);
        sz--;
        int output = 0;

        while (head != nullptr)
        {
            output += head->val << sz;
            sz--;
            head = head->next;
        }

        return output;
    }
};

