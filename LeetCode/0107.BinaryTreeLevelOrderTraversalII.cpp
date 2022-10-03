#include <vector>
#include <deque>
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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        std::vector<std::vector<int>> output;
        std::vector<int> level_nodes;

        std::deque<TreeNode *> nodes;
        nodes.push_back(root);

        int n_nodes;
        TreeNode *node;
        while (!nodes.empty())
        {
            n_nodes = nodes.size();
            level_nodes.clear();

            while (n_nodes--)
            {
                node = nodes.front();
                nodes.pop_front();
                level_nodes.push_back(node->val);
                if (node->left != nullptr)
                    nodes.push_back(node->left);
                if (node->right != nullptr)
                    nodes.push_back(node->right);
            }

            output.push_back(level_nodes);
        }

        std::reverse(output.begin(), output.end());
        return output;
    }
};

