/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (45.22%)
 * Likes:    2593
 * Dislikes: 0
 * Total Accepted:    446.1K
 * Total Submissions: 986.2K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
 * 。
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * ^m == s.length
 * ^n == t.length
 * 1 <= m, n <= 10^5
 * s 和 t 由英文字母组成
 * 
 * 
 * 
 * 进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？
 */

// @lc code=start
class Solution {
public:
    bool check(const unordered_map<char, int>& table)
    {
        for(const auto& p : table)
        {
            if(p.second > 0)
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> table;
        set<char> t_set;
        int n = s.length(), m = t.length();
        for(int i = 0; i < m; i ++)
        {
            t_set.insert(t[i]);
            table[t[i]] ++;
        }
        int left = 0, right = -1, ans = 1e9;
        string res;
        int ansLeft = -1;
        while(right < n)
        {
            if(t_set.find(s[++right]) != t_set.end())
            {
                --table[s[right]];
            }
            while(check(table) && left <= right)
            {
                if(ans > right - left + 1)
                {
                    ans = right - left + 1;
                    ansLeft = left;
                    //res = s.substr(left, ans);
                }
                if(t_set.find(s[left]) != t_set.end())
                {
                    ++table[s[left]];
                }
                left ++;
            }
        }
        return ansLeft >= 0 ? s.substr(ansLeft, ans) : string();
        //return res;
    }
};
// @lc code=end

