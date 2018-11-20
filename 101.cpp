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
    bool isOK (TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr)
            return true;
        else if (node1 != nullptr && node2 != nullptr){
            if (node1->val != node2->val)
                return false;
            return isOK(node1->left, node2->right) && isOK(node1->right, node2->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isOK(root->left, root->right);
    }
};

/*
其他解法：1.翻转其中一颗二叉树，若翻转后的二叉树与另一颗完全相同，则两棵树是镜像对称的
		  2.同时遍历两棵树，一棵采用前序遍历，另一棵采用后序遍历，若遍历结果是相同的，则两棵树是镜像对称的
*/
