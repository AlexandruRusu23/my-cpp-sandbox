#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        std::stack<TreeNode *> original_nodes;
        std::stack<TreeNode *> cloned_nodes;
        original_nodes.push(original);
        cloned_nodes.push(cloned);
        TreeNode *node = nullptr;
        TreeNode *cloned_node = nullptr;
        while (!original_nodes.empty())
        {
            node = original_nodes.top();
            cloned_node = cloned_nodes.top();
            original_nodes.pop();
            cloned_nodes.pop();

            if (node == target)
                return cloned_node;

            if (node->right != nullptr)
            {
                original_nodes.push(node->right);
                cloned_nodes.push(cloned_node->right);
            }

            if (node->left != nullptr)
            {
                original_nodes.push(node->left);
                cloned_nodes.push(cloned_node->left);
            }
        }

        return nullptr;
    }
};

