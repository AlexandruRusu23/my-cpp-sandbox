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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> output;
        if (root == nullptr)
            return output;

        std::deque<TreeNode *> nodes;
        nodes.push_back(root);
        bool left = true;
        std::vector<int> level_nodes;

        int n_nodes = 0;
        TreeNode *node = nullptr;

        while (!nodes.empty())
        {
            n_nodes = nodes.size();
            while (n_nodes--)
            {
                node = nodes.front();
                level_nodes.emplace_back(node->val);
                if (node->left != nullptr)
                    nodes.push_back(node->left);
                if (node->right != nullptr)
                    nodes.push_back(node->right);
                nodes.pop_front();
            }

            if (!left)
                std::reverse(level_nodes.begin(), level_nodes.end());

            output.emplace_back(level_nodes);
            level_nodes.clear();
            left = !left;
        }

        return output;
    }
};

