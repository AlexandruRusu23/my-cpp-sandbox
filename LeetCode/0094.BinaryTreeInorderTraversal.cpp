#include <vector>
#include <stack>

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
    // recursive approach
    void traverse(TreeNode* root, std::vector<int>& output)
    {
        if (root == nullptr)
            return;
        
        traverse(root->left, output);
        output.emplace_back(root->val);
        traverse(root->right, output);
    }
    
    std::vector<int> inorderTraversal(TreeNode* root) {
        if ( root == nullptr )
            return {};

        std::vector<int> output;

        // recursive approach
        //traverse(root, output);

        std::stack<TreeNode*> nodes;

        while ( root != nullptr || !nodes.empty() )
        {
            while (root != nullptr)
            {
                nodes.push(root);
                root = root->left;
            }
            
            root = nodes.top();
            nodes.pop();
            
            output.push_back(root->val);
            
            root = root->right;
        }

        return output;
    }
};

