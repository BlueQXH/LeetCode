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
class Solution1
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr)
        {
            return root;
        }
        TreeNode *tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};

class Solution2
{
public:
    TreeNode* invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return root;
        }
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *tmp;
        while (!st.empty())
        {
            tmp = st.top();
            st.pop();
            if (tmp->left != nullptr)
            {
                st.push(tmp->left);
            }
            if (tmp->right != nullptr)
            {
                st.push(tmp->right);
            }
            swap(tmp->left, tmp->right);
        }
        return root;
    }
};
