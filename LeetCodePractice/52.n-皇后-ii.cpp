/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 *
 * https://leetcode.cn/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (82.41%)
 * Likes:    441
 * Dislikes: 0
 * Total Accepted:    120.7K
 * Total Submissions: 146.5K
 * Testcase Example:  '4'
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：2
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int ans = 0;
    int n;
    set<int> diag1;
    set<int> diag2;
    set<int> line;
    void search(int row)
        {
            //cout << row << " " << n <<  endl;
            if(row == n)
            {
                this -> ans ++;
                //cout << this -> ans << endl;
                return;
            }
            for(int i = 0; i < n; i ++)
            {
                /*if(line.find(i) == line.end())
                {
                    cout << "true" << endl;
                }*/
                
                if(line.find(i) == line.end() && diag1.find(i + row) == diag1.end() && diag2.find(i - row) == diag2.end())
                {
                    //cout << "in" << endl;
                    line.insert(i);
                    diag1.insert(i + row);
                    diag2.insert(i - row);
                    search(row + 1);
                    line.erase(i);
                    diag1.erase(i + row);
                    diag2.erase(i - row);
                }
            }
        }
    int totalNQueens(int n) {
        
        this -> n = n;
        // int ans = 0;
        
        
        search(0);
        return this -> ans;
    }
};
// @lc code=end

