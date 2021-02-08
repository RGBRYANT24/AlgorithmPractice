#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
    //cout<<pow(2,16)<<endl;
    int D,I;
    int kase;
    cin>>kase;
    while ((kase--) && (scanf("%d%d", &D, &I) == 2))
    {
        int ans=1;
        for(int i=0;i<D-1;i++)//高度是D，小球下落D-1次
        {
            if(I%2==1)//如果是奇数
            {
                ans*=2;
                I=(I+1)/2;
            }
            else
            {
                ans*=2;
                ans++;
                I/=2;
            }
        }
        cout<<ans<<endl;
    }
}