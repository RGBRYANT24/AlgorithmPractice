/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> d; //存储每个节点的高度
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode *> q;
        q.push(root);
        d.push_back(0);
        int id = 0;
        while (!q.empty())
        {
            TreeNode *p = q.front();
            q.pop();
            if (d[id] >= ans.size())
            {
                ans.push_back(vector<int>{});
            }
            if (p->left != nullptr)
            {
                q.push(p->left);
                d.push_back(d[id] + 1); //存储他们的高度是父节点+1
            }
            if (p->right != nullptr)
            {
                q.push(p->right);
                d.push_back(d[id] + 1); //存储他们的高度是父节点+1
            }
            ans[d[id]].push_back(p->val);
            id++;
        }
        return ans;
    }
};
// @lc code=end

