#include <deque>
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
    std::vector<int> postorderTraversal(TreeNode *root)
    {
        std::vector<int> output;

        if (root == nullptr)
            return output;

        std::deque<TreeNode *> stack;

        while (true)
        {
            while (root)
            {
                stack.push_back(root);
                stack.push_back(root);
                root = root->left;
            }

            if (stack.empty())
                break;

            TreeNode *node = stack.back();
            stack.pop_back();

            if (!stack.empty() && node == stack.back())
            {
                root = node->right;
            }
            else
            {
                output.push_back(node->val);
                root = nullptr;
            }
        }

        return output;
    }
};

