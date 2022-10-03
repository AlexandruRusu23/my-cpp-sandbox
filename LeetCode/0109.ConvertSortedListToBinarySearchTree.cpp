#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void addNodes(TreeNode *&node, int left, int right, std::vector<int> &nums)
    {
        if (left > right)
            return;

        int index = (left + right) / 2;

        node = new TreeNode(nums[index]);

        addNodes(node->left, left, index - 1, nums);
        addNodes(node->right, index + 1, right, nums);
    }

    TreeNode *sortedArrayToBST(std::vector<int> &nums)
    {
        TreeNode *root = new TreeNode(nums[nums.size() / 2]);

        addNodes(root->left, 0, nums.size() / 2 - 1, nums);
        addNodes(root->right, nums.size() / 2 + 1, nums.size() - 1, nums);

        return root;
    }

    TreeNode *sortedListToBST_Hacky(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        std::vector<int> nums;
        while (head != nullptr)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        return sortedArrayToBST(nums);
    }

    ListNode *getMiddle(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *first = head;
        ListNode *second = head;

        while (second != nullptr && second->next != nullptr)
        {
            prev = first;
            first = first->next;
            second = second->next->next;
        }

        if (prev != nullptr)
            prev->next = nullptr;

        return first;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *middle = getMiddle(head);
        TreeNode *root = new TreeNode(middle->val);

        if (head == middle)
            return root;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(middle->next);

        return root;
    }
};

