/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> ans;
        vector<int> d;
        queue<TreeNode*> q;
        q.push(root);
        d.push_back(0);
        int id = 0;
        if(root == nullptr) return ans;
        while(!q.empty())
        {
            TreeNode* u = q.front();
            q.pop();
            if(d[id] >= ans.size())
            {
                ans.push_back(vector<int> {});
            }
            ans[d[id]].push_back(u -> val);
            if(u -> left != nullptr) 
            {
                q.push(u -> left);
                d.push_back(d[id] + 1);
            }
            if (u->right != nullptr)
            {
                q.push(u->right);
                d.push_back(d[id] + 1);
            }
            id++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

