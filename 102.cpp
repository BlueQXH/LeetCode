/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            vector<int> vec;
            queue<TreeNode*>::size_type len = nodes.size();
            for (auto i = 0; i < len; ++i) {
                TreeNode *tmp = nodes.front();
                vec.push_back(tmp->val);
                nodes.pop();
                if (tmp->left != nullptr)
                    nodes.push(tmp->left);
                if (tmp->right != nullptr)
                    nodes.push(tmp->right);
            }
            ans.push_back(move(vec));
        }
        return ans;
    }
};
