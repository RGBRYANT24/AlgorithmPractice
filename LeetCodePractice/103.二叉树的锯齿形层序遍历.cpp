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
        bool re = true;
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0)
        {
            int n = q.size();
           deque<int> levelList;
            for(int i = 0; i < n; i ++)
            {
                TreeNode* node = q.front();
                //q.erase(q.begin());
                q.pop();
                //temp.push(node -> val);
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
                if(re)
                {
                    levelList.push_back(node -> val);
                }
                else
                {
                   levelList.push_front(node -> val);
                }
            }
            ans.push_back(vector<int>(levelList.begin(), levelList.end()));
            re = !re;
        }
        return ans;
    }
};
// @lc code=end

