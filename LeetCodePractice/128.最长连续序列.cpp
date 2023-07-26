/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (54.73%)
 * Likes:    1715
 * Dislikes: 0
 * Total Accepted:    410.6K
 * Total Submissions: 752.2K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int n = nums.size(), ans = 1;
        if(nums.size() <= 1)
        {
            return nums.size();
        }
        for(const int& num : nums)
        {
            set.insert(num);
        }
        for(const int& num : nums)
        {
            if(!set.count(num - 1))
            {
                //cout << num << endl;
                int cur = num + 1;
                int curStreak = 1;
                while(set.count(cur))
                {
                    //cout << cur << " ";
                    cur = cur + 1;
                    curStreak++;
                    
                }
                ans = max(ans, curStreak);
                //cout << endl;
            }
            
        }
        return ans;
    }
};
// @lc code=end

