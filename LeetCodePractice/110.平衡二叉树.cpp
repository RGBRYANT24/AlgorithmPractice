/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool flag;
    int dfs(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int left, right;
        left = dfs(root -> left) + 1;
        right = dfs(root -> right) + 1;
        if(abs(left - right) > 1) flag = false;
        return max(left, right);
    }
    bool isBalanced(TreeNode* root) 
    {
        //if((root -> left ==nullptr && root -> right == nullptr)||(root == nullptr)) return true;
        if(root == nullptr) return true;
        flag = true;
        dfs(root);
        /*bool left, right;
        if(root -> left != nullptr) left = isBalanced(root -> left);
        if(root -> right != nullptr) right = isBalanced(root -> right);*/
        return flag;
    }
};
// @lc code=end

