#include <iostream>
#include <stdio.h>

using namespace std;

bool build_mobile(int &weight)
{
    int twl, tdl, twr, tdr;
    bool left=true, right=true; //左右天平是否平衡
    cin >> twl >> tdl >> twr >> tdr;
    //cout<<twl<<" "<<tdl<<" "<<twr<<" "<<tdr<<endl;
    if (twl == 0)
    {
        //cout<<"build left"<<endl;
        left = build_mobile(twl);
    }
    if (twr == 0)
    {
        right = build_mobile(twr);
    }
    weight=twl+twr;//这里传进来的weight一定是0，因为只有是0才会构建子树
    return left && right && (twl * tdl == twr *tdr);
    /*cout<<"weight left "<<twl*tdl<<" right "<<twr*tdr<<endl;
    if (twl * tdl != twr * tdr)
    {
        return false;
    }
    else
    {
        weight += twl;
        weight += twr;
        return true;
    }*/
}

int main()
{
    int T,W=0;
    cin>>T;
    while(T--)
    {
        if(build_mobile(W))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        if(T) cout<<endl;
    }
    /*getchar();
    getchar();*/
}