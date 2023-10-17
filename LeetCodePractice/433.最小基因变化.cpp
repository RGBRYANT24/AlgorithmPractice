/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution {
public:
    bool check(string s1, string s2)
    {
        int count = 0;
        if(s1.length() != s2.length()) return false;
        for(int i = 0; i < s1.length(); i ++)
        {
            if(s1[i] != s2[i]) count ++;
            if(count > 1) return false;
        }
        // cout << s1 << " " << s2 << " " << count << endl;
        return count == 1 ? true : false;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q;
        unordered_map<string, int> vis;
        vis[startGene] = 1;
        int ans = 0;
        q.push({startGene, 0});
        while(!q.empty())
        {
            string s;
            int cur;
            tie(s, cur) = q.front();
            q.pop();
            if(s == endGene) return cur;
            for(int i = 0; i < bank.size(); i ++)
            {
                // cout << s << " " << bank[i] << " " << vis[bank[i]] << " " << check(bank[i], s) << endl;
                if(!vis[bank[i]] && check(bank[i], s))
                {
                    
                    vis[bank[i]] = 1;
                    q.push({bank[i], cur + 1});
                }
            }
        }
        return -1;
    }
};
// @lc code=end

