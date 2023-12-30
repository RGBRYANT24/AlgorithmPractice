/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 K 小的数对距离
 *
 * https://leetcode.cn/problems/find-k-th-smallest-pair-distance/description/
 *
 * algorithms
 * Hard (46.97%)
 * Likes:    436
 * Dislikes: 0
 * Total Accepted:    35.9K
 * Total Submissions: 76.3K
 * Testcase Example:  '[1,3,1]\n1'
 *
 * 数对 (a,b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。
 * 
 * 给你一个整数数组 nums 和一个整数 k ，数对由 nums[i] 和 nums[j] 组成且满足 0 <= i < j < nums.length
 * 。返回 所有数对距离中 第 k 小的数对距离。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,1], k = 1
 * 输出：0
 * 解释：数对和对应的距离如下：
 * (1,3) -> 2
 * (1,1) -> 0
 * (3,1) -> 2
 * 距离第 1 小的数对是 (1,1) ，距离为 0 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,1,1], k = 2
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,6,1], k = 3
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 2 <= n <= 10^4
 * 0 <= nums[i] <= 10^6
 * 1 <= k <= n * (n - 1) / 2
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front() + 1;
        int n = nums.size();
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for(int j = 0; j < n; j ++)
            {
                int i = lower_bound(nums.begin(), nums.begin() + j, nums[j] - mid) - nums.begin();
                cnt += j - i;
            }
            if(cnt < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
// @lc code=end

