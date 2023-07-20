/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 *
 * https://leetcode.cn/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (52.45%)
 * Likes:    863
 * Dislikes: 0
 * Total Accepted:    298K
 * Total Submissions: 568K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 * 
 * 
 * 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 * 
 * 进阶：
 * 
 * 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T
 * 的子序列。在这种情况下，你会怎样改变代码？
 * 
 * 致谢：
 * 
 * 特别感谢 @pbrother 添加此问题并且创建所有测试用例。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abc", t = "ahbgdc"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "axc", t = "ahbgdc"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 0 
 * 两个字符串都只由小写字符组成。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int dp[m + 5][30];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < 30; i ++)
        {
            dp[m][i] = m;
        }
        for(int i = m - 1; i >= 0; i --)
        {
            int index = int(t[i] - 'a');
            for(int j = 0; j < 30; j ++)
            {
                if(index == j)
                {
                    dp[i][j] = i;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        int i = 0, j = 0;
        while(i < m && j < n)
        {
            i = dp[i][s[j] - 'a'];
            // cout << i << " " << j << endl;
            if(i < m)
            {
                j ++;
                i ++; //注意i是匹配当前字符s[j], 匹配完了之后要用i+1 匹配j + 1
            }
            else
            {
                return false;
            }
        }
        return j == n;
    }
};
// @lc code=end

