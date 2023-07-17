/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode.cn/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (43.02%)
 * Likes:    2507
 * Dislikes: 0
 * Total Accepted:    960.7K
 * Total Submissions: 2.2M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i = 0; i < strs[0].length(); i ++)
        {
            bool flag = true;
            for(int j = 1; j < strs.size(); j ++)
            {
                if(strs[j].length() > i && strs[j][i] == strs[0][i])
                {
                    //cout << strs[j] << " " << strs[0][j] << endl;
                    continue;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                //cout << strs[0][i] <<endl;
                ans += strs[0][i];
            }
            else
            {
                return ans;
            }
        }
        return ans;
    }
};
// @lc code=end

