/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    UnionFind(vector<vector<char>>& board)
    {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < n; j ++)
            {
                if(board[i][j] == 'O')
                {
                    parent.push_back(i * n + j);
                }
                else
                {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
        parent.push_back(m * n);
        rank.push_back(0);
    }

    int find(int x)
    {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootx = find(x), rooty = find(y);
        if(rank[rootx] < rank[rooty])
        {
            swap(rootx, rooty);
        }
        parent[rooty] = rootx;
        rank[rootx] += rank[rooty];
    }

    bool isConnected(int node1, int node2)
    {
        return find(node1) == find(node2);
    }
};


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        UnionFind uf = UnionFind(board);
        int m = board.size();
        int n = board[0].size();
        int dummyHead = m * n;
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < n; j ++)
            {
                if(board[i][j] == 'O')
                {
                    if(i == 0 || i == m - 1 || j == 0 || j == n - 1)
                    {
                        uf.unite(i * n + j, dummyHead);//边界点连接
                    }
                    if(i + 1 < m && board[i + 1][j] == 'O') uf.unite((i + 1) * n + j, i * n + j);
                    if(j + 1 < n && board[i][j + 1] == 'O') uf.unite(i * n + j + 1, i * n + j);
                    if(i - 1 >= 0 && board[i - 1][j] == 'O') uf.unite((i - 1) * n + j, i * n + j);
                    if(j - 1 >= 0 && board[i][j - 1] == 'O') uf.unite(i * n + j - 1, i * n + j);
                }
            }
        }

        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < n; j ++)
            {
                if(board[i][j] == 'O')
                {
                    if(!uf.isConnected(i * n + j, dummyHead)) board[i][j] = 'X';
                }
            }
        }
    }
};
// @lc code=end

