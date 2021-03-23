/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> vis;
        int m = board.size();
        int n = board[0].size();
        queue<int> s1;//存i
        queue<int> s2;//存j
        for(int i = 0; i < m; i ++)
        {
            vis.push_back(vector<int> {});
            for(int j = 0; j < n; j ++)
            {
                vis[i].push_back(0);
                if((i == 0 || j == 0 || i == m - 1  || j == n - 1) && (board[i][j] == 'O'))
                {
                    s1.push(i);
                    s2.push(j);
                }
            }
        }
        while(!s1.empty())
        {
            int i = s1.front();
            int j = s2.front();
            s1.pop();
            s2.pop();
            vis[i][j] = 1;
            for(int k = 0; k < 4; k++)
            {
                int nexti = i + dr[k];
                int nextj = j + dc[k];
                if (nexti >= 0 && nexti < m && nextj >= 0 && nextj < n && board[nexti][nextj] == 'O' && !vis[nexti][nextj])
                {
                    s1.push(nexti);
                    s2.push(nextj);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && board[i][j] == 'O')
                    {
                        board[i][j] = 'X';
                    }
            }
        }
    }
};
// @lc code=end

