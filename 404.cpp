/**
 * Definition for a binary tree node.
 * struct TreeNode
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int sum = 0;
        queue<TreeNode *> nodes;
        nodes.push(root);
        TreeNode *pNode = nullptr;
        while (!nodes.empty())
        {
            pNode = nodes.front();
            nodes.pop();
            if (pNode->left != nullptr)
            {
                if (pNode->left->left == nullptr && pNode->left->right == nullptr)
                {
                    sum += pNode->left->val;
                }
                else
                {
                    nodes.push(pNode->left);
                }
            }
            if (pNode->right != nullptr)
            {
                nodes.push(pNode->right);
            }
        }
        return sum;
    }
};
