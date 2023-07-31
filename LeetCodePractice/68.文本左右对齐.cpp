/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 *
 * https://leetcode.cn/problems/text-justification/description/
 *
 * algorithms
 * Hard (52.33%)
 * Likes:    353
 * Dislikes: 0
 * Total Accepted:    56.5K
 * Total Submissions: 107.9K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * 给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
 * 
 * 你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth
 * 个字符。
 * 
 * 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
 * 
 * 文本的最后一行应为左对齐，且单词之间不插入额外的空格。
 * 
 * 注意:
 * 
 * 
 * 单词是指由非空格字符组成的字符序列。
 * 每个单词的长度大于 0，小于等于 maxWidth。
 * 输入单词数组 words 至少包含一个单词。
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: words = ["This", "is", "an", "example", "of", "text", "justification."],
 * maxWidth = 16
 * 输出:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
 * 输出:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
 * 因为最后一行应为左对齐，而不是左右两端对齐。       
 * ⁠    第二行同样为左对齐，这是因为这行只包含一个单词。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入:words =
 * ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]，maxWidth
 * = 20
 * 输出:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= words.length <= 300
 * 1 <= words[i].length <= 20
 * words[i] 由小写英文字母和符号组成
 * 1 <= maxWidth <= 100
 * words[i].length <= maxWidth
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string blank(int n)
    {
        return string(n, ' ');
    }
    string join(vector<string>& words, int left, int right, string sep)
    {
        string s = words[left];
        for(int i = left + 1; i < right; ++ i)
        {
            s += sep + words[i];
        }
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        int right = 0;
        vector<string> ans;
        int n = words.size();
        while(true)
        {
            int left = right;
            int len = 0;
            while(right < n && len + words[right].length() + right - left <= maxWidth)
            {
                len += words[right ++].length();
            }
            if(right == n)//如果是最后一行
            {
                string temp = join(words, left, right, blank(1));
                temp += string(maxWidth - temp.length(), ' ');
                ans.emplace_back(temp);
                return ans;
            }

            int numWords = right - left;
            if(numWords == 1)
            {
                string temp = words[left];
                temp += blank(maxWidth - temp.length());
                ans.emplace_back(temp);
                continue;
            }
            int spaceLeft = maxWidth - len;
            int numSpace = spaceLeft / (numWords - 1); //单词之间的空格
            int spareSpace = spaceLeft % (numWords - 1); //行末空格
            //cout << numSpace << " " << spareSpace << " " << numWords << " " << spaceLeft << endl;
            string s1 = join(words, left, left + spareSpace + 1, blank(numSpace + 1));
            string s2 = join(words, left + spareSpace + 1, right, blank(numSpace));
            s1 += blank(numSpace) + s2;
            ans.emplace_back(s1);
        }
        return ans;
    }
};
// @lc code=end

