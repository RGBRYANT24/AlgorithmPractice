/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 *
 * https://leetcode.cn/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (59.02%)
 * Likes:    1038
 * Dislikes: 0
 * Total Accepted:    85.8K
 * Total Submissions: 145.4K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * 给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和
 * values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
 * 
 * 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj
 * = ? 的结果作为答案。
 * 
 * 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0
 * 替代这个答案。
 * 
 * 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
 * 
 * 注意：未在等式列表中出现的变量是未定义的，因此无法确定它们的答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
 * [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 * 输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
 * 解释：
 * 条件：a / b = 2.0, b / c = 3.0
 * 问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 * 结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
 * 注意：x 是未定义的 => -1.0
 * 
 * 示例 2：
 * 
 * 
 * 输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0],
 * queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 * 输出：[3.75000,0.40000,5.00000,0.20000]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：equations = [["a","b"]], values = [0.5], queries =
 * [["a","b"],["b","a"],["a","c"],["x","y"]]
 * 输出：[0.50000,2.00000,-1.00000,-1.00000]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= equations.length <= 20
 * equations[i].length == 2
 * 1 <= Ai.length, Bi.length <= 5
 * values.length == equations.length
 * 0.0 < values[i] <= 20.0
 * 1 <= queries.length <= 20
 * queries[i].length == 2
 * 1 <= Cj.length, Dj.length <= 5
 * Ai, Bi, Cj, Dj 由小写英文字母与数字组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
         vector<double> ans;
        unordered_map<string, vector<pair<string, double>>> table;
        for(int i = 0; i < equations.size(); i ++)
        {
            auto eq = equations[i];
            string a = eq[0];
            string b = eq[1];
            table[a].push_back({b, values[i]});
            table[b].push_back({a, 1 / values[i]});
        }
        for(const auto eq : queries)
        {
            unordered_map<string, int> vis;
            //cout << "eq " << eq[0] << " " << eq[1] << endl;
            string start = eq[0], end = eq[1];
            if(table.find(start) == table.end() || table.find(end) == table.end())
            {
                ans.push_back(-1.0000);
                continue;
            }
            vis[start] = 1;
            queue<pair<string, double>> q;
            q.push({start, 1});
            bool flag = false;
            while(!q.empty())
            {
                // count += 1;
                string c;
                double temp;
                tie(c, temp) = q.front();
                //cout << c << " " << temp << endl;
                if(c == end)
                {
                    ans.push_back(temp);
                    flag = true;
                    break;
                }
                q.pop();
                for(const auto p : table[c])
                {
                    string next = p.first;
                    double scale = p.second;
                    if(vis[next] > 0) continue;
                    q.push({next, scale * temp});
                    vis[next] = 1;
                }
            }
            if(!flag) ans.push_back(-1.0000);
        }
        return ans;
    }
};
// @lc code=end

