#include <queue>

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
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        ListNode *head = nullptr;
        ListNode *iter = nullptr;

        std::priority_queue<int, std::vector<int>, std::greater<int>> values;

        for (int i = 0; i < lists.size(); i++)
        {
            while (lists[i])
            {
                values.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }

        while (!values.empty())
        {
            if (head == nullptr)
            {
                head = new ListNode(values.top());
                iter = head;
            }
            else
            {
                iter->next = new ListNode(values.top());
                iter = iter->next;
            }
            values.pop();
        }

        return head;
    }
};

