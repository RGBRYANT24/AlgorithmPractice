/*
 * @lc app=leetcode.cn id=945 lang=cpp
 *
 * [945] 使数组唯一的最小增量
 */

// @lc code=start
class Solution
{
public:
    int minIncrementForUnique(vector<int> &A)
    {
        const int maxn = 80000 + 5;
        int unique[maxn];
        memset(unique, 0, sizeof(unique));
        sort(A.begin(), A.end());
        for(int i = 0; i < A.size(); i ++)
        {
            unique[A[i]] ++;
        }
        int cnt = 0;
        for(int i = 0; i < 80000; i ++)
        {
            if(unique[i] <= 1)
                continue;
            else
            {
                cnt += unique[i] - 1;
                unique[i + 1] += unique[i] - 1;//既然重复的肯定要+1变换，那就直接全部+1，不然可能TLE
                unique[i] = 1;
            }
        }
        return cnt;
    }
};
// @lc code=end
