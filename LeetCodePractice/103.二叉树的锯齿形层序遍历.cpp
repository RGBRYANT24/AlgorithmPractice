/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> d;
        int id = 0;
        d.push_back(0);
        vector<vector<int>> ans;
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
            if(u -> right != nullptr)
            {
                q.push(u -> right);
                d.push_back(d[id] + 1);
            }
            id ++;
        }
        for(int i = 0; i < ans.size(); i++)
        {
            if(i%2 == 1)
            {
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};
// @lc code=end

