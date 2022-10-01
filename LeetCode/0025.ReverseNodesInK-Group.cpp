
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
    ListNode *reverseK(ListNode *head, ListNode *tailNext, int k)
    {
        ListNode *first = head;
        ListNode *second = head->next;
        head->next = tailNext;
        k--;

        while (k--)
        {
            head = second;
            second = second->next;
            head->next = first;
            first = head;
        }

        return head;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head->next == nullptr || k == 1)
            return head;

        ListNode *kthNode = head;
        for (int i = 0; i < k; i++)
        {
            kthNode = kthNode->next;
        }
        ListNode *missingLink = head;
        head = reverseK(head, kthNode, k);

        bool bOk = true;
        ListNode *interHead = kthNode;
        while (kthNode != nullptr)
        {
            interHead = kthNode;
            for (int i = 0; i < k; i++)
            {
                if (kthNode == nullptr)
                {
                    bOk = false;
                    break;
                }
                kthNode = kthNode->next;
            }

            if (bOk)
            {
                missingLink->next = reverseK(interHead, kthNode, k);
                missingLink = interHead;
            }
        }

        return head;
    }
};

