/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode.cn/problems/word-search/description/
 *
 * algorithms
 * Medium (46.41%)
 * Likes:    1718
 * Dislikes: 0
 * Total Accepted:    467.4K
 * Total Submissions: 1M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false
 * 。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCCED"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "SEE"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCB"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 
 * 1 
 * board 和 word 仅由大小写英文字母组成
 * 
 * 
 * 
 * 
 * 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
 * 
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<int>& vis, vector<vector<char>>& board, int id, string& word, int start)
    {
        
        vis[id] ++;
        int m = board.size();
        int n = board[0].size();
        int x = id / n;
        int y = id % n;
        //cout << x << " " << y << " " << start << " " << vis[1] << " " << int(board[0][1] == word[start + 1]) << endl;
        if(start == word.length() - 1) return true;
        bool result;
        if(x >= 0 && x < m - 1 && vis[id + n] == 0 && word[start + 1] == board[x + 1][y]) result = dfs(vis, board, id + n, word, start + 1);//down
        if(result) return true;
        if(x > 0 && x < m && vis[id - n] == 0 && word[start + 1] == board[x - 1][y]) result = dfs(vis, board, id - n, word, start + 1);//up
        if(result) return true;
        if(y >= 0 && y < n - 1 && vis[id + 1] == 0 && word[start + 1] == board[x][y + 1]) result = dfs(vis, board, id + 1, word, start + 1);// right
        if(result) return true;
        if(y > 0 && y < n && vis[id - 1] == 0 && word[start + 1] == board[x][y - 1]) result = dfs(vis, board, id - 1, word, start + 1);//left
        if(result) return true;
        vis[id] = 0;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int id = 0;
        bool result;
        vector<int> vis(m * n + 1, 0);
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < n; j ++)
            {
                if(word[0] == board[i][j] && !vis[id]) result = dfs(vis, board, id, word, 0);
                if(result) return true;
                id ++;
            }
        }
        return false;
    }
};
// @lc code=end

