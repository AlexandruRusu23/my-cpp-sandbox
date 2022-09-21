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
    int minimumDepthRecursive(TreeNode *node, int level)
    {
        if (node == nullptr)
            return 10000001;

        level++;
        if (node->left == nullptr && node->right == nullptr)
            return level;

        return std::min(minimumDepthRecursive(node->left, level),
                        minimumDepthRecursive(node->right, level));
    }

    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        std::deque<TreeNode *> nodes;
        nodes.push_back(root);
        int level = 1;
        TreeNode *node;

        while (!nodes.empty())
        {
            int n_nodes = nodes.size();
            while (n_nodes--)
            {
                node = nodes.front();
                nodes.pop_front();

                if (node->left == nullptr && node->right == nullptr)
                    return level;

                if (node->left != nullptr)
                    nodes.push_back(node->left);

                if (node->right != nullptr)
                    nodes.push_back(node->right);
            }
            level++;
        }

        return level;
    }
};

