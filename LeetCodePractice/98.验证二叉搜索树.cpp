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
    /*int count = 0;
    bool dfs(TreeNode *root,int min, int max)
    {
        count++;
        if(root==nullptr) return true;
        if(count != 1)//不是根节点
        {
            if (root->val <= min)
                return false;
            if (root->val >= max)
            {
                return false;
            }
        }
        
        return dfs(root->left,min,root->val) && dfs(root->right,root->val,max);
        这前面是用上界和下届判断二叉搜索树的，但是样例总卡INT_MAX和IN_MIN      
    }  
    */
    TreeNode *prev;
    bool isBTS(TreeNode *root)
    {
        if(root!=nullptr)
        {
            if(!isBTS(root->left))
            {
                return false;
            }
            if(prev!=nullptr && root->val <= prev->val)
            {
                return false;
            }
            prev = root;
            if(!isBTS(root->right))
            {
                return false;
            }
        }
        return true;
    }
    bool isValidBST(TreeNode *root)
    {
        //int INT_MAX=1;
        //if (dfs(root,INT_MIN,INT_MAX))
        if(isBTS(root))
            return true;
        else
            return false;
    }
};
// @lc code=end
