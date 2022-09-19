
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        bool carriedValue = false;
        ListNode *output = new ListNode((l1->val + l2->val) % 10);
        ListNode *returnList = output;
        if (l1->val + l2->val >= 10)
            carriedValue = true;

        l1 = l1->next;
        l2 = l2->next;

        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 != nullptr && l2 != nullptr)
            {
                output->next = new ListNode(l1->val + l2->val);
                output = output->next;
                if (carriedValue)
                {
                    output->val++;
                    carriedValue = false;
                }
                if (output->val >= 10)
                {
                    carriedValue = true;
                    output->val %= 10;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1 != nullptr)
            {
                output->next = new ListNode(l1->val);
                output = output->next;
                if (carriedValue)
                {
                    output->val++;
                    carriedValue = false;
                }
                if (output->val >= 10)
                {
                    output->val %= 10;
                    carriedValue = true;
                }
                l1 = l1->next;
            }
            else if (l2 != nullptr)
            {
                output->next = new ListNode(l2->val);
                output = output->next;
                if (carriedValue)
                {
                    output->val++;
                    carriedValue = false;
                }
                if (output->val >= 10)
                {
                    carriedValue = true;
                    output->val %= 10;
                }
                l2 = l2->next;
            }
        }

        if (carriedValue)
            output->next = new ListNode(1);

        return returnList;
    }
};

