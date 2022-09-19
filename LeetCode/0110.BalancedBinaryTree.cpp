#include <cmath>
#include <algorithm>

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
    int height(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        return 1 + std::max(height(node->left), height(node->right));
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        int left = height(root->left);
        int right = height(root->right);

        if (abs(left - right) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};

