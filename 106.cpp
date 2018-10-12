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
    TreeNode* build(vector<int> &inorder, int in_start, int in_end, vector<int> &postorder, int post_start, int post_end) {
        if (in_start > in_end || post_start > post_end)
            return nullptr;
        int rootValue = postorder[post_end];
        TreeNode* root = new TreeNode(rootValue);
        int index = in_start;
        while (index <= in_end && inorder[index] != rootValue)
            ++index;
        if (index <= in_end) {
            root->left = build(inorder, in_start, index-1, postorder, post_start, post_start+index-in_start-1);
            root->right = build(inorder, index+1, in_end, postorder, post_start+index-in_start, post_end-1);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty())
            return nullptr;
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
