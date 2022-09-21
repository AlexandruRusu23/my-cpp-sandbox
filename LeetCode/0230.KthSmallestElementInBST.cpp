#include <stack>

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
    int kthSmallest(TreeNode *root, int k)
    {
        std::stack<TreeNode *> nodes;

        while (root != nullptr || !nodes.empty())
        {
            while (root != nullptr)
            {
                nodes.push(root);
                root = root->left;
            }

            k--;
            root = nodes.top();
            if (k == 0)
                return root->val;
            nodes.pop();

            root = root->right;
        }

        return -1;
    }
};

