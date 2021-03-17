## Data Structure

#### 二叉树

- 完全二叉树根节点从1开始编号，那么第k个节点的左子节点编号是2k，右子节点编号是2k+1



#### 拓扑排序

实质上是将有向无环图（DAG）的顶点排成一个线性序列。

如果有边<u,v>那么拓扑排序时节点v在u的前面

##### 拓扑排序的步骤

###### 非DFS版本

- 从DAG图中找到一个没有前驱节点的顶点输出
- 删除以这个点为起点的边
- 重复上述步骤，直到最后一个顶点被输出。**如果有顶点没有被输出，那么说明有环**

###### DFS版本

- 对所有没有访问过的顶点进行dfs
- 如果该节点访问完，则将该节点放到当前拓扑排序的首部
  - 因为是DFS，所以产生拓扑序列时，越是孙子的节点越先被访问完。所以放在当前节点的首部
- 如果正在访问u的同时，还在访问为v。那么就说明有环。

```c++
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
```

#### 欧拉回路

- 从起点出发经过所有的顶点一次且仅一次，并且回到出发点的是**欧拉回路**
- 从起点出发经过所有的顶点一次且仅一次，但是不回到出发点的是**欧拉道路**

##### 无向图判断

- **奇点** ：度数为奇数的点
- **判断欧拉道路**：有且只有两个奇点，并且一个作为起点，一个作为终点。才能有欧拉道路
- **判断欧拉回路**：没有奇点，所有顶点的度数均为偶数。

```
void euler(int u)
{
	
}
```



##### 有向图判断

- **判断欧拉道路**：连通图，且有一个顶点出度比入度大1（起点），一个顶点入度比出度大1（终点）
- **判断欧拉回路**：连通图，所有顶点的入度等于出度。



