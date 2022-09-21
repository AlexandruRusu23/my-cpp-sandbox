#include <cmath>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    int getLength(ListNode *node)
    {
        int output = 0;

        while (node)
        {
            node = node->next;
            output++;
        }

        return output;
    }

    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB)
    {
        int sizeA = getLength(headA);
        int sizeB = getLength(headB);
        int diff = std::abs(sizeA - sizeB);

        if (sizeA < sizeB)
        {
            ListNode *aux = headA;
            headA = headB;
            headB = aux;
        }

        while (diff--)
        {
            headA = headA->next;
        }

        while (headA != nullptr)
        {
            if (headA == headB)
                return headA;

            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *cHeadA = headA;
        ListNode *cHeadB = headB;

        while (headA != nullptr || headB != nullptr)
        {
            if (headA == nullptr)
                headA = cHeadB;

            if (headB == nullptr)
                headB = cHeadA;

            if (headA == headB)
                return headA;

            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};

