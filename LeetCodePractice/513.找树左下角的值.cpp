/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        vector<int> d;
        int id = 0;
        int height = 0;//当前层的高度
        int ans = root -> val;
        queue<TreeNode*> q;
        q.push(root);
        d.push_back(0);
        while(!q.empty())
        {
            TreeNode* p = q.front();
            q.pop();
            if(height != d[id]) 
            {
                ans = p -> val;
                height = d[id];
            }
            if(p -> left != nullptr) 
            {
                q.push(p -> left);
                d.push_back(d[id] + 1);
            }
            if(p -> right != nullptr) 
            {
                q.push(p -> right);
                d.push_back(d[id] + 1);
            }
            id++;
        }
        return ans;
    }
};
// @lc code=end

