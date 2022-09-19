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
    int maxDepthRecursive(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return left > right ? left + 1 : right + 1;
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        std::deque<TreeNode*> nodes;
        nodes.push_back(root);
        
        int depth = 0;
        int max_depth = 0;
        TreeNode* node;
        while(!nodes.empty())
        {
            int n_nodes = nodes.size();
            depth++;
            if (depth > max_depth)
                max_depth = depth;
            while (n_nodes--)
            {
                node = nodes.front();
                nodes.pop_front();
                if (node->left != nullptr)
                    nodes.push_back(node->left);
                if (node->right != nullptr)
                    nodes.push_back(node->right);
            }
        }
        
        return max_depth;
    }
};

