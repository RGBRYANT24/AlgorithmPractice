/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) 
    {
        int id = 0;
        vector<int> d;
        queue<int> q;
        for(int i = 1; i <= (int)sqrt(n); i++)
        {
            int u = n - i * i;
            if(u == 0) return 1;
            q.push(u);//把当前节点和target差多少push进去，然后BFS
            d.push_back(1);
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i = 1; i <= (int)sqrt(u); i++)
            {
                int p = u - i * i;
                if(p == 0) return d[id] + 1;
                q.push(p);
                d.push_back(d[id] + 1);
            }
            id++;
        }
        return d[id];//如果遍历到最后（队列为空）那返回的就是最后一个高度
    }
};
// @lc code=end

