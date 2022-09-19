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

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
            return head;

        int n = getLength(head);
        k = k % n;

        if (n == 0 || n == 1 || n == k || k == 0)
            return head;

        ListNode *prev = head;
        ListNode *newHead = head;
        for (int i = 0; i < n - k; i++)
        {
            prev = newHead;
            newHead = newHead->next;
        }

        prev->next = nullptr;
        ListNode *iter = newHead;
        while (iter != nullptr && iter->next != nullptr)
            iter = iter->next;
        iter->next = head;

        return newHead;
    }
};

