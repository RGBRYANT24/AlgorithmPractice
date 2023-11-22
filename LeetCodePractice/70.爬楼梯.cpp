/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode.cn/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (54.16%)
 * Likes:    3334
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.4M
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 2
 * 输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 3
 * 输出：3
 * 解释：有三种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 45
 * 
 * 
 */

// @lc code=start
class Solution {
public:
   vector<vector<long long>> multiply(vector<vector<long long>>& a,vector<vector<long long>>& b)
    {
        vector<vector<long long>> c(a.size(), vector<long long>(a.size()));
        for(int i = 0; i < a.size(); i ++)
        {
            for(int j = 0; j < b.size(); j ++)
            {
                int temp = 0;
                for(int k = 0; k < a[i].size(); k ++)
                {
                    temp += a[i][k] * b[j][k];
                }
                c[i][j] = temp;
            }
        }
        return c;
    }

    vector<vector<long long>> matrixPow(vector<vector<long long>>& a, int n)
    {
        vector<vector<long long>> ret = {{1, 0}, {0, 1}};
        while(n > 0)
        {
            if(n % 2 == 1)
            {
                ret = multiply(ret, a);
            }
            a = multiply(a, a);
            n >>= 1;
        }
        return ret;
    }
    int climbStairs(int n) {
        vector<vector<long long>> ret = {{1, 1}, {1, 0}};
        vector<vector<long long>> res = matrixPow(ret, n);
        return res[0][0];
        
    }
};
// @lc code=end

