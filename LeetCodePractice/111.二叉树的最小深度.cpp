/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root -> right == nullptr && root  -> left == nullptr) return 1;//当前节点是叶子节点 返回当前叶子节点的高度1
        int left = INT_MAX, right = INT_MAX;
        if(root -> left != nullptr) left = minDepth(root -> left) + 1;
        if(root -> right != nullptr) right = minDepth(root -> right) + 1;
        return min(left, right);
    }
};
// @lc code=end

