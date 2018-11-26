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
    void inOrder(vector<int> &vec, TreeNode *root)
	{
        if (root != nullptr)
		{
            inOrder(vec, root->left);
            vec.push_back(root->val);
            inOrder(vec, root->right);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inOrder(ans, root);
        return ans;
    }
};

class Solution2
{
public:
    vector<int> inorderTraversal(TreeNode *root)
	{
        vector<int> ans;
		if (root != nullptr)
		{
			stack<TreeNode *> nodes;
			TreeNode *pNode = root;
			while (pNode != nullptr || !nodes.empty())
			{
				if (pNode != nullptr)
				{
					nodes.push(pNode);
					pNode = pNode->left;
				}
				else
				{
					ans.push_back(nodes.top()->val);
					pNode = nodes.top()->right;
					nodes.pop();
				}
			}
		}
        return ans;
    }
};
