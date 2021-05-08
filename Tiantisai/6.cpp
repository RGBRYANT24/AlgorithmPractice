#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

string q = "qiandao";
string easy = "easy";

bool match(string s)
{
    int flag = 0;
    for(int i = 0; i < s.length(); i++)
    {        
        if(s[i] == 'q' || s.length() - i >= 7)
        {
            flag = 1;
            for(int j = i + 1; j < i + q.length(); j++)
            {
                if(s[j] != q[j - i])//如果不匹配 就break
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 1)
        {
            //cout << "qiandao match " << s << endl;
            return true;
        }
        flag = 0;
        if (s[i] == 'e' || s.length() - i >= 4)
        {
            flag = 1;
            for (int j = i + 1; j < i + easy.length(); j++)
            {
                if (s[j] != easy[j - i]) //如果不匹配 就break
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag == 1)
        {
            //cout << "easy match " << s << endl;
            return true;
        }
    }
    return false;
}

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    int ak = 1;
    for(int i = 0; i <= N; i++)
    {
        string s;
        getline(cin, s);
        bool result = match(s);
        //cout << i << " " << s << " result " << result << endl;
        /*if(result == true)
        {
            cout << "match " << s << endl;
        }*/
        if(!result)
        {
            //cout << M << " " << s << endl;
            if (M == 0)
            {
                ak = 0;
                cout << s;
                break;
            }
            M--;
        }
    }
    if(ak)
    {
        cout << "Wo AK le";
    }
    system("pause");
    return 0;
}