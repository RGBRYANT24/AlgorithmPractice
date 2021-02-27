#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

const int maxn = 1e4;
int sum[maxn];

void build(int index)
{
    int n;
    cin >> n;
    if (n == -1)
        return; //如果是-1就表明这个节点没有
    else
    {
        sum[index] += n;
        //cout << "index " << index << " value " << n << " sum " << sum[index] << endl;
        build(index - 1);
        build(index + 1);
    }
}

void print_result(int kase)
{
    
    int p=0;
    while(sum[p] == 0) p++;
    cout << "Case " << kase << ":\n" <<sum[p++];
    while(sum[p]!=0) cout<<" "<<sum[p++];
    cout<<"\n\n";
}

int main()
{
    int kase=0;
    while(1)
    {
        memset(sum, 0, sizeof(sum));
        int n;
        int index = maxn / 2;
        cin >> n;
        if (n != -1)
        {
            sum[index] += n;
            build(index - 1);
            build(index + 1);
            print_result(++kase);
        }
        else
        {
            return 0;
        }
    }  
}