/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 *
 * [1382] 将二叉搜索树变平衡
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
    vector<int> nums;
public:
    void bfs(TreeNode* root)
    {
        stack<TreeNode*> stk;
        if(!root) return;
        TreeNode* p = root;
        while(p || !stk.empty())
        {
            while(p)
            {
                stk.push(p);
                p = p -> left;
            }
            p = stk.top();
            stk.pop();
            //cout << p ->val <<endl;
            nums.push_back(p -> val);
            p = p -> right;
        }
    }

    TreeNode* build(int l, int r)
    {
        int mid = l + (r - l) / 2;
        //int mid = (l + r) >> 1;
        TreeNode* p = new TreeNode(nums[mid]);
        if(mid > l) p -> left = build(l, mid - 1);
        if(mid < r) p -> right = build(mid + 1, r);
        return p;
    }/*
     TreeNode* build(int l, int r) {
        int mid = (l + r) >> 1;
        TreeNode* o = new TreeNode(nums[mid]);
        if (l <= mid - 1) {
            o->left = build(l, mid - 1);
        }
        if (mid + 1 <= r) {
            o->right = build(mid + 1, r);
        }
        return o;
    }*/
    TreeNode* balanceBST(TreeNode* root) {
        bfs(root);
        //for(int i : nums) cout << i << endl;
        return build(0, nums.size() - 1);
    }
};
// @lc code=end

