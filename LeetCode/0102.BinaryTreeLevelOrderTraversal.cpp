#include <vector>
#include <deque>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> output;    
        
        if (root == nullptr)
            return output;
        
        std::deque<TreeNode*> nodes;
        nodes.push_back(root);
        std::vector<int> level_nodes;
        TreeNode* node = nullptr;
        
        while (!nodes.empty())
        {
            int current_nodes = nodes.size();
            while (current_nodes--)
            {
                node = nodes.front();
                level_nodes.emplace_back(node->val);
                if (node->left != nullptr)
                    nodes.push_back(node->left);
                if (node->right != nullptr)
                    nodes.push_back(node->right);
                nodes.pop_front();
            }
            output.emplace_back(level_nodes);
            level_nodes.clear();
        }
        
        return output;
    }
};

