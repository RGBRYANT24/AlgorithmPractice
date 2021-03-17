#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

const int maxn = 100;
int topo[maxn];
int G[maxn][maxn];
int c[maxn]; //0没有访问 -1正在访问 1访问过
int n;       //节点个数
int t;

bool dfs(int u)
{
    c[u] = -1; //标记正在访问
    cout << "visit " << u << endl;
    for (int v = 0; v < n; v++)
    {
        if (G[u][v]) //如果从u到v有边
        {
            if (c[v] < 0)
            {
                cout << "false point " << v << endl;
                return false; //如果u到v有边，但是v这时正在访问，说明v是u的祖先，u也是v的祖先所以是环
            }

            else if (!c[v] && !dfs(v))
            {
                cout << " dfs false " << v << endl;
                return false; //!c[v]为假，就不会对后面的dfs调用，表示如果v已经访问完，就不访问v了
                              //dfs(v)表示如果没有访问过v !c[v] ,那么dfs v还发现有环了，就退出
            }
        }
    }
    c[u] = 1; //访问完
    cout << "put " << t - 1 << " " << u << endl;
    topo[--t] = u; //将访问完的节点放置在当前拓扑排序首部，但是因为是dfs，所以越先搜索完成的，越是孙子，就越靠后
    return true;
}

bool toposort()
{
    cout << "in" << endl;
    t = n;
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++)
    {
        if (!c[i])
        {
            if (!dfs(i))
                return false;
        }
    }
    return true;
}

int main()
{
    int i, j;
    cin >> n;
    for (int k = 0; k < n; k++)
    {
        cin >> i >> j;
        G[i][j] = 1;
        cout << i << " " << j << " " << G[i][j] << endl;
    }
    //n = 9;
    bool result = toposort();
    cout << "result " << result << endl;
    for (int i = 0; i < n; i++)
    {
        cout << topo[i] << " ";
    }
    cout << endl;
    system("pause");
}