#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

const int maxn = 110;
char map[maxn][maxn];
int idx[maxn][maxn];
int n, m; //变长

void dfs(int i, int j, int id)
{  
    if (i < 0 || i >= m || j < 0 || j >= n || idx[i][j] || map[i][j] != '@')
        return; //如果出了地图||访问过||不是@就返回
    else
    {
        idx[i][j] = id;
        //cout << "location " << i << " " << j << " id " << id << endl;
        for (int r = -1; r < 2; r++)
        {
            for (int c = -1; c < 2; c++)
            {
                dfs(i + r, j + c, id);
            }
        }
    }
}

int main()
{
    while (1)
    {
        memset(map,0,sizeof(map));
        memset(idx,0,sizeof(idx));
        cin >> m >> n;
        if (m == 0 || n == 0)
            break;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> map[i][j];
            }
        }
        int id = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] == '@' && !idx[i][j])
                {
                    dfs(i, j, ++id);
                }
            }
        }
        cout << id << endl;
    }
    /*getchar();
    getchar();*/
}