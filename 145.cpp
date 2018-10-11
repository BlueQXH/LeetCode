/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    void postOrder(vector<int> &vec, TreeNode* root) {
        if (root != nullptr) {
            postOrder(vec, root->left);
            postOrder(vec, root->right);
            vec.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(ans, root);
        return ans;
    }
};

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode*> nodes;
        TreeNode *cur = nullptr, *pre = nullptr;
        nodes.push(root);
        while (!nodes.empty()) {
            cur = nodes.top();
            if ((cur->left == nullptr && cur->right == nullptr) || (pre != nullptr && (pre == cur->left || pre == cur->right))) {
                ans.push_back(cur->val);
                nodes.pop();
                pre = cur;
            }
            else {
                if (cur->right != nullptr)
                    nodes.push(cur->right);
                if (cur->left != nullptr)
                    nodes.push(cur->left);
            }
        }
        return ans;
    }
};
