/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 *
 * https://leetcode.cn/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (52.04%)
 * Likes:    2107
 * Dislikes: 0
 * Total Accepted:    579.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "PAYPALISHIRING", numRows = 3
 * 输出："PAHNAPLSIIGYIR"
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "PAYPALISHIRING", numRows = 4
 * 输出："PINALSIGYAHRPI"
 * 解释：
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "A", numRows = 1
 * 输出："A"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 由英文字母（小写和大写）、',' 和 '.' 组成
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int cal(int& count, const int& numRows)
    {
        int ans;
        if(count > numRows - 1)
        {
            ans = -count - 2 + numRows * 2;
        }
        else
        {
            //cout << count << " " << numRows << endl;
            ans = count;
        }
        count ++;
        count %= (2 * numRows - 2);
        return ans;
    }
    string convert(string s, int numRows) {
        string str[1005];
        string ans;
        int n = s.length();
        int count = 0;
        if(numRows == 1)
        {
            return s;
        }
        for(int i = 0; i < n; i ++)
        {
            int row = cal(count, numRows);
            cout << row << " ";
            str[row] += s[i];
        }
        cout << endl;
        for(int i = 0; i < numRows; i ++)
        {
            ans += str[i];
        }
        return ans;
    }
};
// @lc code=end

