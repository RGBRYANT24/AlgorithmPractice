/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 *
 * https://leetcode.cn/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (69.89%)
 * Likes:    454
 * Dislikes: 0
 * Total Accepted:    155.1K
 * Total Submissions: 221.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10^-5 以内的答案可以被接受。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[3.00000,14.50000,11.00000]
 * 解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
 * 因此返回 [3, 14.5, 11] 。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 
 * 
 * 输入：root = [3,9,20,15,7]
 * 输出：[3.00000,14.50000,11.00000]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 树中节点数量在 [1, 10^4] 范围内
 * -2^31 <= Node.val <= 2^31 - 1
 * 
 * 
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<pair<TreeNode*, int>> q;
        int level = 0;
        if(!root) return {};
        q.push({root, 0});
        long long tot = 0;
        int count = 0;
        while(!q.empty())
        {
            TreeNode* node;
            int cur;
            tie(node, cur) = q.front();
            //cout << cur <<" " << node ->val  <<" " << count <<endl;
            q.pop();
            if(cur > level)
            {
                ans.push_back(double(double(tot) / double(count)));
                tot = node -> val;
                count = 1;
                level = cur;
            }
            else
            {
                count ++;
                tot += node -> val;
            }
            if(node -> right) q.push({node -> right, cur + 1});
            if(node -> left) q.push({node -> left, cur + 1});
        }
        ans.push_back(double(double(tot) / double(count)));
        return ans;
    }
};
// @lc code=end

