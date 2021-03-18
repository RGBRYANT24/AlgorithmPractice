#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stdlib.h>

using namespace std;

const int maxn = 30;
int G[maxn][maxn];
int vis[maxn][maxn];
int in_degree[maxn], out_degree[maxn];

void add(const string& str)
{
    int u = str[0] - 'a';
    int v = str[str.length() - 1] - 'a';
    G[u][v] = 1;
    in_degree[v]++;
    out_degree[u]++;
}

void dfs(int u, int cnt)//判断是不是联通图，就是看连通块是不是只有一个
{
    for(int v = 0; v < 26; v++)
    {
        if((G[u][v] || G[u][v]) && !vis[u][v])//注意是底图联通（无向图）
        {
            vis[u][v] = 1;
            vis[v][u] = 1;
            dfs(v, cnt);
        }
    }
}

bool judge(int cnt)
{
    int in = 0, out = 0;
    for(int i=0; i<26; i++)
    {
        if(abs(in_degree[i] - out_degree[i]) > 1)
        {
            return false;
        }
        if(in_degree[i] - out_degree[i] == 1)//记录入度比出度大1的个数
        {
            in++;
        }
        else if(out_degree[i] - in_degree[i] == 1)//记录入度比出度小1的个数
        {
            out++;
        }
    }
    if(in!=out || in > 1 || out > 1 || cnt != 1)
    {
        return false;
    }
    return true;
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        memset(G, 0, sizeof(G));
        memset(vis, 0, sizeof(vis));
        memset(in_degree, 0, sizeof(in_degree));
        memset(out_degree, 0, sizeof(out_degree));
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string str;
            cin>>str;
            add(str);
        }
        int cnt = 0;
        int start = -1, end = -1;
        int num = 0;
        for(int i=0;i<26;i++)
        {
            if(in_degree[i] != out_degree[i])
            {
                num++;
            }
            if(out_degree[i] - in_degree[i] == 1)
            {
                start = i; //起点
            }
            if(in_degree[i] - out_degree[i] ==1)
            {
                end = i;//终点
            }
        }
        if(start != -1)
        {
            dfs(start, ++cnt);
        }
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(G[i][j]&&!vis[i][j])
                {
                    dfs(i,++cnt);
                }
            }
        }
        //cout<<"cnt "<<cnt<<" num "<<num<<" start "<<start<<" end "<<end<<endl;
        if((cnt<=1&&start!=-1&&end!=-1&&num==2)||(cnt<=1&&num==0))
        {
            cout << "Ordering is possible." << endl;
        }
        else
        {
            cout << "The door cannot be opened." << endl;
        }
    }
    system("pause");
}