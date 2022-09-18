
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
    bool simetry(TreeNode* left, TreeNode* right)
    {
        if (left == right)
            return true;
        
        if (left == nullptr || right == nullptr)
            return false;
        
        if (left->val != right->val)
            return false;
        
        return simetry(left->left, right->right) & simetry(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return simetry(root->left, root->right);
    }
};

