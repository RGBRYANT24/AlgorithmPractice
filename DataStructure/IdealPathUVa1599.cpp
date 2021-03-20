#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#include <stdio.h>
#include <fstream>

using namespace std;

const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;

//邻接表
int head[maxn];
int d[maxn];
int vis[maxn];
int ans[maxn];

struct edge
{
    int to;//顶点u到哪一条边
    int next;//邻接表中下一条边
    int col;
}edge[maxn<<2];

void add(int id, int u, int v, int c)
{
    edge[id].to = v;
    edge[id].col = c;
    edge[id].next = head[u];//指向当前邻接表第一条边
    head[u] = id;//当前邻接表指向这条边
}

void rbfs(int n)
{
    d[n] = 0;
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(n);
    vis[n] = 1;
    while(!q.empty())
    {
        int u = q.front(), v;
        q.pop();
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            v = edge[i].to;
            if(!vis[v])
            {
                //cout << "rbfs visit " << v << endl;
                q.push(v);
                d[v] = d[u] + 1;
                vis[v] = 1;
            }
        }
    }
}

void bfs(int n)
{
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++) ans[i] =  INF;
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty())
    {
        int u, v;
        u = q.front();
        q.pop();
        if(u == n)
            continue;
        int minc = INF;
        //cout << "bfs " << u << endl;
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            int c = edge[i].col;
            //cout << "minc " << minc << " c " << c << " vis " << vis[v] << " d[u] " << d[u] << " d[v] " << d[v] << endl;
            if(d[u] - 1 == d[v])//这里找最小颜色不用管访问过没访问过，因为访问过的点也可能更换字典序更小的边去到达
            {
                minc = min(minc, c); //找到最小颜色
            }
        }
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            int c = edge[i].col;
            if(!vis[v] && d[u] == d[v] + 1 && minc == c)
            {
                q.push(v);
                vis[v] = 1;
            }
        }
        int index = d[1] - d [u];
        ans[index] = min(ans[index], minc);
    }
}

int main()
{
    int n,m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(head, -1, sizeof(head));
        int u, v, c, id = 0;
        for(int i = 0; i < m ; i++)
        {
            cin >> u >> v >> c;
            add(++id, u, v, c);
            add(++id, v, u, c);
        }
        rbfs(n);
        //for(int i = 1; i <= n; i ++) cout << d[i] <<endl;
        bfs(n);
        printf("%d\n", d[1]);
        for (int i = 0; i < d[1]; i++)
        {
            printf("%d%c", ans[i], i == d[1] - 1 ? '\n' : ' ');
        }
    }
    system("pause");
    return 0;
}