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
    int dfs (TreeNode* root, int depth) {
        if (root == nullptr)
            return depth;
        else {
            ++depth;
            return max(dfs(root->left, depth), dfs(root->right, depth));
        }
    }
    int maxDepth(TreeNode* root) {
        int ans = 0;
        return dfs(root, ans);
    }
};
