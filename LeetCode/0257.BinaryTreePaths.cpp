#include <string>
#include <vector>

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
    void recursivePath(TreeNode *node, std::string path, std::vector<std::string> &output)
    {
        if (node == nullptr)
            return;

        if (node->left == nullptr && node->right == nullptr)
        {
            output.push_back(path + "->" + std::to_string(node->val));
            return;
        }

        if (node->left != nullptr)
            recursivePath(node->left, path + "->" + std::to_string(node->val), output);

        if (node->right != nullptr)
            recursivePath(node->right, path + "->" + std::to_string(node->val), output);
    }

    std::vector<std::string> binaryTreePaths(TreeNode *root)
    {
        std::vector<std::string> output;
        if (root == nullptr)
            return output;

        if (root->left == nullptr && root->right == nullptr)
        {
            output.push_back(std::to_string(root->val));
            return output;
        }

        if (root->left != nullptr)
            recursivePath(root->left, std::to_string(root->val), output);
        if (root->right != nullptr)
            recursivePath(root->right, std::to_string(root->val), output);
        return output;
    }
};

