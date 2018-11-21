/**
 * Definition for a binary tree node.
 * struct TreeNode
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void Inorder(TreeNode *root, vector<int> &nums)
    {
        if (root != nullptr)
        {
            Inorder(root->left, nums);
            nums.push_back(root->val);
            Inorder(root->right, nums);
        }
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> nums;
        Inorder(root, nums);
        return nums.at(k-1);
    }
};

//若二叉搜索树经常被修改（插入/删除），并且需要频繁查找第k小的值，则维护一个优先队列（最小堆）即可
