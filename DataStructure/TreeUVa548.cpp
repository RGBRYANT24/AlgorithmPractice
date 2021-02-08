#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

const int maxn = 1e5+10;
int lch[maxn],rch[maxn],root,in_order[maxn],post_order[maxn];
int n;//获取长度

bool read_input(int *a)
{
    string line;
    if(!getline(cin,line)) return false;
    stringstream ss(line);
    n=0;
    int x;
    while(ss>>x) a[n++]=x;
    return n>0;
}

int build(int L1,int R1,int L2,int R2)
{
    int root=post_order[R2];//后序遍历的最后一个就是根
    int p=L1;
    while(in_order[p]!=root)
    {
        p++;//在中序遍历中找到根
    }
    int cnt=p-L1;
    if(p>L1) lch[root]=build(L1,p-1,L2,L2+cnt-1);//左子树的根就是当前节点的左孩子
    if(R1>p) rch[root]=build(p+1,R1,L2+cnt,R2-1);
    return root;
}

int best,best_value;//最小的叶子节点编号和最小的权值和

void dfs(int u,int sum)
{
    sum+=u;//加上当前节点的权值
    //cout<<u<<endl;
    if ((!lch[u] && !rch[u]) && (sum < best_value || (sum == best_value && u < best)))
    {
        best=u;
        best_value=sum;
    }
    if(lch[u]!=0) dfs(lch[u],sum);
    if(rch[u]!=0) dfs(rch[u],sum);
}
int main()
{
    while (read_input(in_order))
    {
        read_input(post_order);
        build(0,n-1,0,n-1);
        int sum=0;
        best_value=1e8;
        dfs(post_order[n-1],sum);
        cout<<best<<endl;
        memset(in_order,0,sizeof(in_order));
        memset(post_order,0,sizeof(in_order));
        memset(lch,0,sizeof(lch));
        memset(rch,0,sizeof(rch));
    }
}