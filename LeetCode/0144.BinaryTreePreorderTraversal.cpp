#include <vector>
#include <deque>

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
    void preorder(TreeNode *node, std::vector<int> &output)
    {
        if (node == nullptr)
            return;

        output.emplace_back(node->val);
        preorder(node->left, output);
        preorder(node->right, output);
    }

    std::vector<int> preorderTraversal(TreeNode *root)
    {
        std::vector<int> output;

        if (root == nullptr)
            return output;

        std::deque<TreeNode *> nodes;
        nodes.push_back(root);

        while (!nodes.empty())
        {
            TreeNode *node = nodes.back();
            nodes.pop_back();
            output.push_back(node->val);

            if (node->right)
                nodes.push_back(node->right);
            if (node->left)
                nodes.push_back(node->left);
        }

        return output;
    }
};

