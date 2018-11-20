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
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if (root == nullptr)
        {
            root = new TreeNode(val);
            return root;
        }
        TreeNode *p = root;
        while (p != nullptr)
        {
            if (val < p->val)
            {
                if (p->left != nullptr)
                {
                    p = p->left;
                }
                else
                {
                    p->left = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if (p->right != nullptr)
                {
                    p = p->right;
                }
                else
                {
                    p->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
