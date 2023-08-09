/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (49.41%)
 * Likes:    1446
 * Dislikes: 0
 * Total Accepted:    390.4K
 * Total Submissions: 789.7K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * -100 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int u = 0, d = matrix.size() -1, l = 0, r = matrix[0].size() - 1;
        while(true)
        {
            for(int i = l; i <= r; i ++)
            {
                ans.emplace_back(matrix[u][i]);
            }
            if(++u > d)
            {
                break;
            }
            for(int i = u; i <= d; i ++)
            {
                ans.emplace_back(matrix[i][r]);
            }
            if(--r < l)
            {
                break;
            }
            for(int i = r; i >=l ; i --)
            {
                ans.emplace_back(matrix[d][i]);
            }
            //cout << d << " " << u << endl;
            if(--d < u)
            {
                break;
            }
            for(int i = d; i >= u; i --)
            {
                ans.emplace_back(matrix[i][l]);
            }
            //cout << l << " " << r;
            if(++l > r)
            {
                break;
            }
        }
        return ans;

    }
};
// @lc code=end

