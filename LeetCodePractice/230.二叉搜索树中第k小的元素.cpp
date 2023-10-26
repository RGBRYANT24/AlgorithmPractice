/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
private:
    unordered_map<TreeNode*, int> nodeNum;//记录当前节点为根的子树中节点个数
public:
    int count(TreeNode* root)
    {
        if(!root) return 0;
        int left = count(root -> left);
        int right = count(root -> right);
        nodeNum[root] = 1 + left + right;
        return nodeNum[root];
    }

    int kthSmallest(TreeNode* root, int k) {
        count(root);
        TreeNode* p = root;
        while(k && p)
        {
            int count = nodeNum[p -> left];
            if(k - 1 > count)
            {
                p = p -> right;
                k = k - 1 - count;
                continue;
            }
            else if(k - 1 < count)
            {
                p = p -> left;
                continue;
            }
            else return p -> val;
        }
        return -1;
    }
};
// @lc code=end

