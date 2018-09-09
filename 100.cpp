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
    void printTree(TreeNode* root, vector<int> &vec) {
        if (root == nullptr) {
            vec.push_back(0);
            return;
        }
        else {
            vec.push_back(root->val);
            printTree(root->left, vec);
            printTree(root->right, vec);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> p_vec, q_vec;
        printTree(p, p_vec);
        printTree(q, q_vec);
        return p_vec == q_vec;
    }
};

class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        if ((p == nullptr && q != nullptr) ||(p != nullptr && q == nullptr))
            return false;
        if (p != nullptr && q != nullptr && p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
