#include <iostream>
#include <stdio.h>

using namespace std;

bool build_mobile(int &weight)
{
    int twl, tdl, twr, tdr;
    bool left, right; //左右天平是否平衡
    cin >> twl >> tdl >> twr >> tdr;
    cout<<twl<<" "<<tdl<<" "<<twr<<" "<<tdr<<endl;
    if (twl == 0)
    {
        cout<<"build left"<<endl;
        left = build_mobile(twl);
    }
    if (!left)
        return false;
    if (twl == 0)
    {
        right = build_mobile(twr);
    }
    if (!right)
        return false;
    if (twl * tdl != twr * tdr)
    {
        return false;
    }
    else
    {
        weight += twl;
        weight += twr;
        return true;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int weight=0;
        bool result = build_mobile(weight);
        if(result) 
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    getchar();
    getchar();
}