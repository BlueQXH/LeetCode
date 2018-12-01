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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> ans;
        if (root != nullptr)
        {
            queue<TreeNode *> nodes;
            nodes.push(root);
            while (!nodes.empty())
            {
                int sz = nodes.size();
                vector<int> vec;
                TreeNode *pNode;
                for (int i = 0; i < sz; ++i)
                {
                    pNode = nodes.front();
                    vec.push_back(pNode->val);
                    nodes.pop();
                    if (pNode->left != nullptr)
                    {
                        nodes.push(pNode->left);
                    }
                    if (pNode->right != nullptr)
                    {
                        nodes.push(pNode->right);
                    }
                }
                ans.push_back(move(vec));
            }
        }
        if (ans.size() > 1)
        {
            reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};

class Solution2
{
public:
    void traverse(TreeNode *root, int level)
    {
        if (root != nullptr)
        {
            if (level == ans.size())
            {
                vector<int> vec;
                ans.push_back(move(vec));
            }
            ans.at(level).push_back(root->val);
            traverse(root->left, level+1);
            traverse(root->right, level+1);
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        traverse(root, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    vector<vector<int>> ans;
};
