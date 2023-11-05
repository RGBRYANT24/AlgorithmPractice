/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 *
 * https://leetcode.cn/problems/course-schedule/description/
 *
 * algorithms
 * Medium (53.89%)
 * Likes:    1820
 * Dislikes: 0
 * Total Accepted:    351.8K
 * Total Submissions: 652.9K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
 * 
 * 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi]
 * ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
 * 
 * 
 * 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
 * 
 * 
 * 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：numCourses = 2, prerequisites = [[1,0]]
 * 输出：true
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
 * 
 * 示例 2：
 * 
 * 
 * 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
 * 输出：false
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * prerequisites[i] 中的所有课程对 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> vis;
    bool valid = true;
public:
    void dfs(int u)
    {
        vis[u] = 1;
        for(const int v : edges[u])
        {
            if(vis[v] == 0)
            {
                dfs(v);
                if(!valid) return;
            }
            else if(vis[v] == 1)
            {
                valid = false;
                return;
            }
        }
        vis[u] = 2;
        return;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        vis.resize(numCourses);
        for(const auto& vec : prerequisites)
        {
            edges[vec[1]].push_back(vec[0]);
        }
        for(int i = 0; i < numCourses; i ++)
        {
            if(!vis[i]) dfs(i);
        }
        return valid;
    }
};
// @lc code=end

