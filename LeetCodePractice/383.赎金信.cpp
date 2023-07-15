/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 *
 * https://leetcode.cn/problems/ransom-note/description/
 *
 * algorithms
 * Easy (60.48%)
 * Likes:    724
 * Dislikes: 0
 * Total Accepted:    336.2K
 * Total Submissions: 555.5K
 * Testcase Example:  '"a"\n"b"'
 *
 * 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
 * 
 * 如果可以，返回 true ；否则返回 false 。
 * 
 * magazine 中的每个字符只能在 ransomNote 中使用一次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：ransomNote = "a", magazine = "b"
 * 输出：false
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：ransomNote = "aa", magazine = "ab"
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：ransomNote = "aa", magazine = "aab"
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote 和 magazine 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[30], n = ransomNote.length(), m = magazine.length();
        memset(a, 0, sizeof(a));
        for(int i = 0; i < m; i ++)
        {
            a[magazine[i] - 'a'] += 1;
        }
        for(int i = 0; i < n; i ++)
        {
            if(a[ransomNote[i] - 'a'] <= 0 )
            {
                return false;
            }
            a[ransomNote[i] - 'a'] --;
        }
        return true;

    }
};
// @lc code=end

