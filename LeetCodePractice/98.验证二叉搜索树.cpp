/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
         if(!root) return false;
        int pre = 0;
        int count = 0;
        TreeNode* p = root;
        stack<TreeNode*> stk;
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
                if(count && p -> val <= pre) return false;
                count ++;
                pre = p -> val;
                stk.pop();
            }
            p = p -> right;
        }
        return true;
    }
};
// @lc code=end
