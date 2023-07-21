/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode.cn/problems/3sum/description/
 *
 * algorithms
 * Medium (37.03%)
 * Likes:    6153
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.8M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j !=
 * k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
 * 
 * 你返回所有和为 0 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 解释：
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
 * 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
 * 注意，输出的顺序和三元组的顺序并不重要。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1,1]
 * 输出：[]
 * 解释：唯一可能的三元组和不为 0 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0,0,0]
 * 输出：[[0,0,0]]
 * 解释：唯一可能的三元组和为 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> s(nums.begin(), nums.end());
        int first = 0, second = 0;
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i : nums)
        {
            cout << i << " ";
        }
        cout << endl;
        for(int first = 0; first < n; first ++)
        {
            if(first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            int second = first + 1;
            int third = n - 1;
            int target = -nums[first];
            for(int second = first + 1; second < n; second ++)
            {
                if(second > first +1 && nums[second] == nums[second - 1])
                {
                    continue;
                }
                int pre_third = -1e9;
                int sum = nums[second] + nums[third];
                while(third > second && sum > target)
                {
                    third --;
                    sum = nums[second] + nums[third];
                }
                if(sum == target && second != third)
                {
                    // cout << second << " " <<third <<endl;
                    ans.push_back(vector<int> {nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

