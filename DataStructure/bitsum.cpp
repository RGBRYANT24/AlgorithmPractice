//输入长度n，求一个长度为2n的二进制串，使得前n位和后n位数字和相同（不计算权值）

#include <iostream>
#include <string>
#include <queue>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int n;
int count1=0;
int count2=0;
//vector<vector<string> > set;
map<int ,vector<string> > set;
/*void build_bits(string t)
{
    count1++;
    if(t.length()==n)
    {
        cout<<t<<endl;
        return;
    }
    else
    {
        build_bits(t+"0");
        build_bits(t+"1");
    }
}//递归版本复杂度是2^n;
*/
int calSum(string str)
{
    int sum=0;
    for(int i=0;i<str.length();i++)
    {
        sum+=str[i]-48;
    }
    set[sum].push_back(str);
    //cout<<sum<<" "<<set[sum].size()<<endl;
    return sum;
}

int main()
{
    cin>>n;
    int temp=n;
    queue<string> q;
    q.push("0");
    q.push("1");
    while(--temp)
    {
        int m = q.size();
        for (int i = 0; i < m; i++)
        {
            string t = q.front();
            q.pop();
            q.push(t + "0");
            q.push(t + "1");
            count2++;
        }
    }
    int m=q.size();
    for(int i=0;i<m;i++)
    {
        calSum(q.front());
        q.pop();
    }
    cout<<n<<endl;
    cout<<set[2].size()<<endl;
    for(int i=0;i<=n;i++)
    {
        for (int j = 0; j < set[i].size(); j++)
        {
            for(int k=0;k<set[i].size();k++)
            cout << set[i][j]+set[i][k] << endl;
        }
    }
    //system("pause");
    getchar();
    getchar();
}