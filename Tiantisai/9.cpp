#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <stdlib.h>

using namespace std;

int N, M, S;
vector<string> lines;
vector<int> curs; //轨道的游标
stack<char> s;
string ans;

void op0()//操作0
{
    if(s.size() == 0)
    {
        return;
    }
    ans += s.top();
    s.pop();
}

void opn(int n)//其他不是0的操作
{
    if(curs[n] >= lines[n].length())
    {
        return;
    }
    if(curs[n] < lines[n].length())//如果线上还有物品
    {
        s.push(lines[n][curs[n]]);
        //cout << "op " << n << endl;
        //cout << s.top() << endl;
        curs[n] ++;//游标后移
    }
}

int main()
{
    ans = "";
    cin >> N >> M >> S;
    lines.push_back("");//占位用
    curs.push_back(0);
    for(int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        lines.push_back(temp);
        curs.push_back(0);
        //cout << lines[i] << endl;
    }
    //opn(1);
    int caozuo;
    while(cin >> caozuo && caozuo != -1)
    {
        if(caozuo != 0)//从轨道上放物品
        {
            if(s.size() == S)//如果栈满了就先操作0
            {
                op0();
            }
            opn(caozuo);
        }
        else
        {
            if(s.size() == 0)
            {
                continue;
            }
            op0();
        }
    }
    cout << ans;
    //system("pause");
    return 0;
}