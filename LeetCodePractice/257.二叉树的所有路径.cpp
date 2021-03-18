/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void dfs(vector<string>&paths, TreeNode* root, string path)
    {
        path += to_string(root->val);
        if(root->left==nullptr&&root->right==nullptr)
        {
            paths.push_back(path);
            return;
        }
        if(root->left!=nullptr)
        {
            //path += "->";
            dfs(paths, root->left, path+"->");
        }
        if (root->right != nullptr)
        {
            //path += "->";
            dfs(paths, root->right, path+"->");
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> paths;
        dfs(paths, root, "");
        return paths;
    }
};
// @lc code=end

