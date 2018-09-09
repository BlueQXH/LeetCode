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
    TreeNode* bulid(const vector<int>& preorder, size_t pre_start, size_t pre_end, const vector<int>& inorder, size_t in_start, size_t in_end) {
        if (pre_start > pre_end || in_start > in_end)
            return nullptr;
        int rootValue = preorder[pre_start];
        TreeNode *root = new TreeNode(rootValue);
        int index = 0;
        while (index < inorder.size() && inorder[index] != rootValue)
            ++index;
        if (index < inorder.size()) {
            root->left = bulid(preorder, pre_start+1, pre_start+index-in_start, inorder, in_start, index-1);
            root->right = bulid(preorder, pre_start+index-in_start+1, pre_end, inorder, index+1, in_end);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return nullptr;
        return bulid(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
