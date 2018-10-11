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
    void preOrder(vector<int> &vec, TreeNode* root) {
        if (root != nullptr) {
            vec.push_back(root->val);
            preOrder(vec, root->left);
            preOrder(vec, root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrder(ans, root);
        return ans;
    }
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode*> nodes;
        TreeNode* pNode = root;
        while (pNode != nullptr || !nodes.empty()) {
            if (pNode != nullptr) {
                ans.push_back(pNode->val);
                nodes.push(pNode);
                pNode = pNode->left;
            }
            else {
                pNode = nodes.top()->right;
                nodes.pop();
            }
        }
        return ans;
    }
};
