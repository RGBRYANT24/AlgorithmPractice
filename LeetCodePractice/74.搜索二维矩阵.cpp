/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode.cn/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (49.13%)
 * Likes:    885
 * Dislikes: 0
 * Total Accepted:    355.4K
 * Total Submissions: 722.6K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
 *
 * 给你一个满足下述两条属性的 m x n 整数矩阵：
 * 
 * 
 * 每行中的整数从左到右按非严格递增顺序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 * 
 * 
 * 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        //cout << m << " " << n << endl;
        int left = 0, right = m * n;
        auto get = [&matrix, &m, & n](int total) -> int
        {
            int x = total / n;
            int y = total - n * x;
            //cout << total << " " << x << " " << y << " " << matrix[x][y] << endl;
            return matrix[x][y];
        };
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(get(mid) == target) return true;
            if(get(mid) < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};
// @lc code=end

