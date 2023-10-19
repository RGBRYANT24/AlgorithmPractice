/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode* root) {
        int ans = 1e9;
        stack<TreeNode*> stk;
        if(!root) return -1;
        int pre = -1;
        //stk.push(root);
        TreeNode* p = root;
        while(p || !stk.empty())
        {
            while(p)
            {
                stk.push(p);
                p = p -> left;
            }
            if(!stk.empty())
            {
                p = stk.top();
                //cout << p -> val << " " << pre << endl;
                if(pre != -1) ans = min(ans, p -> val - pre);
                pre = p -> val; 
                stk.pop();
            }
            p = p -> right;

        }
        return ans;
    }
};
// @lc code=end

