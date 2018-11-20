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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        if (root != nullptr)
        {
            array<stack<TreeNode *>, 2> arr;
            int cur = 0, next = 1;
            arr.at(cur).push(root);
            TreeNode *node;
            while (!arr.at(cur).empty() || !arr.at(next).empty())
            {
                int sz = arr.at(cur).size();
                vector<int> vec;
                for (int i = 0; i < sz; ++i)
                {
                    node = arr.at(cur).top();
                    arr.at(cur).pop();
                    vec.push_back(node->val);
                    if (cur == 0)
                    {
                        if (node->left != nullptr)
                        {
                            arr.at(next).push(node->left);
                        }
                        if (node->right != nullptr)
                        {
                            arr.at(next).push(node->right);
                        }
                    }
                    else
                    {
                        if (node->right != nullptr)
                        {
                            arr.at(next).push(node->right);
                        }
                        if (node->left != nullptr)
                        {
                            arr.at(next).push(node->left);
                        }
                    }
                }
                ans.push_back(move(vec));
                if (arr.at(cur).empty())
                {
                    cur = 1 - cur;
                    next = 1 - next;
                }
            }
        }
        return ans;
    }
};
