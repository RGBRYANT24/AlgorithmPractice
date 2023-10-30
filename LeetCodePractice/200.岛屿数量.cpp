/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode.cn/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (59.60%)
 * Likes:    2339
 * Dislikes: 0
 * Total Accepted:    722.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 
 * grid[i][j] 的值为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        set<pair<int, int>> vis;
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < m; j ++)
            {
                if(grid[i][j] == '1')
                {
                    ans ++;
                    queue<pair<int, int>> q;
                    grid[i][j] = '0';
                    q.push({i, j});
                    while(!q.empty())
                    {
                        int x, y;
                        tie(x, y) = q.front();
                        //cout << x << " " << y << " " << ans << endl;
                        q.pop();
                        if(x + 1 < n && grid[x + 1][y] == '1') 
                        {
                            q.push({x + 1, y});
                            grid[x + 1][y] = '0';
                        }
                        if(x - 1 >= 0 && grid[x - 1][y] == '1')
                        {
                            q.push({x - 1, y});
                            grid[x - 1][y] = '0';
                        }
                        if(y + 1 < m && grid[x][y + 1] == '1') 
                        {
                            q.push({x, y + 1});
                            grid[x][y + 1] = '0';
                        }
                        if(y - 1 >= 0 && grid[x][y - 1] == '1')
                        {
                            q.push({x, y - 1});
                            grid[x][y - 1] = '0';
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};
// @lc code=end

