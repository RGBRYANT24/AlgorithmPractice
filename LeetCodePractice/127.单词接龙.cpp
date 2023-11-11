/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode.cn/problems/word-ladder/description/
 *
 * algorithms
 * Hard (48.31%)
 * Likes:    1317
 * Dislikes: 0
 * Total Accepted:    197.3K
 * Total Submissions: 408.2K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 ->
 * s2 -> ... -> sk：
 * 
 * 
 * 每一对相邻的单词只差一个字母。
 * 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
 * sk == endWord
 * 
 * 
 * 给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列
 * 中的 单词数目 。如果不存在这样的转换序列，返回 0 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * 输出：5
 * 解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * 输出：0
 * 解释：endWord "cog" 不在字典中，所以无法进行转换。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= beginWord.length <= 10
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 5000
 * wordList[i].length == beginWord.length
 * beginWord、endWord 和 wordList[i] 由小写英文字母组成
 * beginWord != endWord
 * wordList 中的所有字符串 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    unordered_map<string, int> wordId;
    vector<vector<int>> edges; //邻接表
public:
    void initId(string beginWord, string endWord, vector<string>& wordList)
    {
        int id = 0;
        /*wordId[beginWord] = id ++;
        edges.emplace_back();*/
        for(const string& word : wordList)
        {
            if(!wordId.count(word))
            {
                wordId[word] = id ++;
                edges.emplace_back();
            }
        }
        /*if(!wordId.count(endWord))
        {
            wordId[endWord] = id ++;
            edges.emplace_back();
        }*/
    }

    bool check(const string& word1, const string& word2)
    {
        if(word1.length() != word2.length()) return false;
        int count = 0;
        for(int i = 0; i < word1.length(); i ++)
        {
            if(count > 1) return false;
            if(word1[i] != word2[i]) count ++;
        }
        return count == 1;
    }

    void addEdge(string beginWord, string endWord, vector<string>& wordList)
    {
        /*for(const string& word : wordList)
        {
            if(word != beginWord && check(word, beginWord))
            {
                int id1 = wordId[word];
                int id2 = wordId[beginWord];
                edges[id2].push_back(id1);
            }
            if(word != endWord && check(word, endWord))
            {
                int id1 = wordId[word];
                int id2 = wordId[endWord];
                edges[id2].push_back(id1);
            }
        }*/
        for(const string& word1 : wordList)
        {
            for(const string& word2 : wordList)
            {
                if(word1 != word2 && check(word1, word2))
                {
                    
                    int id1 = wordId[word1];
                    int id2 = wordId[word2];
                    //cout << word1 << " " << id1 << " " << word2 << " " << id2 << endl;
                    edges[id1].push_back(id2);
                }
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) wordList.push_back(beginWord);
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) wordList.push_back(endWord);
        initId(beginWord, endWord, wordList);
        addEdge(beginWord, endWord, wordList);
        int nodeNum = wordList.size();
        vector<int> disBegin(nodeNum, INT_MAX);
        vector<int> disEnd(nodeNum, INT_MAX);
        disBegin[wordId[beginWord]] = 0;
        disEnd[wordId[endWord]] = 0;
        queue<int> begin;
        queue<int> end;
        begin.push(wordId[beginWord]);
        end.push(wordId[endWord]);
        for(const auto& p : wordId)
        {
            cout << p.first << " " << p.second << endl;
        }
        for(int i = 0; i < edges.size(); i ++)
        {
            cout << "start " << i << " ";
            for(int j = 0; j < edges[i].size(); j ++)
            {
                cout << edges[i][j] << " ";
            }
            cout << endl;
        }
        cout << "bfs" << endl;
        while(!begin.empty() && !end.empty())
        {
            int num = begin.size();
            for(int i = 0; i < num; i ++)
            {
                int node = begin.front();
                begin.pop();
                if(disEnd[node] != INT_MAX)
                {
                    cout << "finish " << node << " " << disBegin[node] << " " << disEnd[node] <<endl;
                    return (disBegin[node] + disEnd[node] )  + 1;
                }
                cout << "start " << node << " ";
                for(int& next : edges[node])
                {
                    cout << next << " ";
                    if(disBegin[next] == INT_MAX)
                    {
                        begin.push(next);
                        disBegin[next] = disBegin[node] + 1;
                    }
                }
                cout << endl;
            }

            num = end.size();
            for(int i = 0; i < num; i ++)
            {
                int node = end.front();
                end.pop();
                if(disBegin[node] != INT_MAX)
                {
                    cout << "finish  re " << node << " " << disBegin[node] << " " << disEnd[node] <<endl;
                    return (disBegin[node] + disEnd[node] + 1) ;
                }
                 cout << "start reverse " << node << " ";
                for(int& next : edges[node])
                {   
                    cout << next << " ";
                    if(disEnd[next] == INT_MAX)
                    {
                        end.push(next);
                        disEnd[next] = disEnd[node] + 1;
                    }
                    
                }
                cout << endl;
            }
        }
        

        return 0;


    }
};
// @lc code=end

