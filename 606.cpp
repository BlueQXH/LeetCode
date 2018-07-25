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
    void dfs (string &s, TreeNode *node) {
        s = s + to_string(node->val);
        if (node->left != nullptr) {
            s.push_back('(');
            dfs(s, node->left);
            s.push_back(')');
        }
        else {
            if (node->right != nullptr) {
                s.push_back('(');
                s.push_back(')');
            }
        }
        if (node->right != nullptr) {
            s.push_back('(');
            dfs(s, node->right);
            s.push_back(')');
        }
    }
    string tree2str(TreeNode* t) {
        if (t == nullptr)
            return "";
        string result;
        dfs(result, t);
        return result;
    }
};
