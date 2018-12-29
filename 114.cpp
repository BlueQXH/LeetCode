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
    void flatten(TreeNode* root)
    {
        while (root != nullptr)
        {
            if (root->left != nullptr)
            {
                TreeNode *pNode = root->left;
                while (pNode->right != nullptr)
                {
                    pNode = pNode->right;
                }
                pNode->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};

class Soalution2
{
public:
    void flatten(TreeNode* root)
    {
        if (root == nullptr)
        {
            return ;
        }
        
        stack<TreeNode *> nodes;
        TreeNode *pRoot = root;
        nodes.push(root);
        while (!nodes.empty())
        {
            TreeNode *pNode = nodes.top();
            nodes.pop();
            
            if (pNode->right != nullptr)
            {
                nodes.push(pNode->right);
            }
            if (pNode->left != nullptr)
            {
                nodes.push(pNode->left);
            }
            
            if (pNode != pRoot)
            {
                pRoot->left = nullptr;
                pRoot->right = pNode;
                pRoot = pNode;
            }
        }
    }
};
