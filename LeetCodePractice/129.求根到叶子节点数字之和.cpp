/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    void dfs(TreeNode* root, string sum, vector<string>& sums)
    {
        sum += to_string(root -> val);//把当前节点的值传入
        if(root -> left ==nullptr && root ->right == nullptr)
        {
            sums.push_back(sum);
            return;
        }
        if(root -> left != nullptr)
        {
            dfs(root -> left, sum, sums);
        }
        if(root -> right != nullptr)
        {
            dfs(root -> right, sum, sums);
        }
    }
    int sumNumbers(TreeNode* root) 
    {
        vector<string> sums;
        dfs(root, "", sums);
        int sum = 0;
        for(int i=0;i<sums.size();i++)
        {
            sum += stoi(sums[i]);
        }
        return sum;
    }
};
// @lc code=end

