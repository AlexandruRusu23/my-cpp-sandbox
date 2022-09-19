#include <vector>

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
    void addNodes(TreeNode*& node, int left, int right, std::vector<int>& nums)
    {
        if (left > right)
            return;
        
        int index = (left + right) / 2;
        
        node = new TreeNode(nums[index]);
        
        addNodes(node->left, left, index - 1, nums);
        addNodes(node->right, index + 1, right, nums);
    }
    
    TreeNode* sortedArrayToBST(std::vector<int>& nums)
    {
        TreeNode* root = new TreeNode(nums[nums.size()/2]);
        
        addNodes(root->left, 0, nums.size()/2 - 1, nums);
        addNodes(root->right, nums.size()/2 + 1, nums.size() - 1, nums);
        
        return root;
    }
};

