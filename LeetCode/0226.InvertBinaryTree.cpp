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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;

        std::vector<TreeNode *> nodes;
        nodes.push_back(root);
        int sz;

        while (!nodes.empty())
        {
            sz = nodes.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *aux = nodes[i]->left;
                nodes[i]->left = nodes[i]->right;
                nodes[i]->right = aux;
                if (nodes[i]->left != nullptr)
                    nodes.push_back(nodes[i]->left);
                if (nodes[i]->right != nullptr)
                    nodes.push_back(nodes[i]->right);
            }
            nodes.erase(nodes.begin(), nodes.begin() + sz);
        }

        return root;
    }
};

