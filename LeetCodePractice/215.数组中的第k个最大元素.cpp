/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (62.68%)
 * Likes:    2368
 * Dislikes: 0
 * Total Accepted:    963.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3,2,1,5,6,4], k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 * 
 * 
 * 
 * 提示： 
 * 
 * 
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void down(int x, int n, vector<int>& h)
    {
        while(x * 2 + 1 < n)
        {
            int t = x * 2 + 1;
            if(t + 1 < n && h[t] < h[t + 1]) t ++;
            if(h[t] <= h[x]) break;
            swap(h[t], h[x]);
            x = t;
        }
    }
    void build(int n, vector<int>& h)
    {
        for(int i = n / 2; i >= 0; i--)
        {
            down(i, n, h);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        build(n, nums);
        for(int i = nums.size() - 1; i >= nums.size() - k + 1; i --)
        {
            swap(nums[0], nums[i]);
            --n;
            down(0, n, nums);
        }
        return nums[0];
    }
};
// @lc code=end

