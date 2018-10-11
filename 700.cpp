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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)
            return root;
        TreeNode *ans = root;
        while (ans != nullptr) {
            if (ans->val == val)
                return ans;
            else if (ans->val < val)
                ans = ans->right;
            else
                ans = ans->left;
        }
        return ans;
    }
};
