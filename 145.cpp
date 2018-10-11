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
        TreeNode *parent = nullptr, *child = nullptr;
        nodes.push(root);
        while (!nodes.empty()) {
            parent = nodes.top();
            if ((parent->left == nullptr && parent->right == nullptr) || (child != nullptr && (child == parent->left || child == parent->right))) {
                ans.push_back(parent->val);
                nodes.pop();
                child = parent;
            }
            else {
                if (parent->right != nullptr)
                    nodes.push(parent->right);
                if (parent->left != nullptr)
                    nodes.push(parent->left);
            }
        }
        return ans;
    }
};
