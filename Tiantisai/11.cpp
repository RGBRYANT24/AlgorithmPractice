#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct codes
{
    int cnt;
    vector<int> ans;
    codes(int c, vector<int> a):cnt(c),ans(a) {};
    bool operator<(const codes c2)
    {
        if(this->cnt > c2.cnt)
        {
            return true;
        }
        else if(this->cnt == c2.cnt)
        {
            for(int i = 0; i < this->ans.size(); i++)
            {
                if(this->ans[i] < c2.ans[i])
                {
                    return true;
                }
            }
            return false;
        }
        return false;
    }
}codes;

int main()
{
    int N, M;
    cin >> N >> M;
    vector< vector < int > > lists;
    vector<int> cnts;
    for(int i = 0; i < N; i++)
    {
        vector<int> temp;
        for(int j = 0; j < M; j++)
        {
            int n;
            cin >> n;
            temp.push_back(n);
        }
        /*for (int j = 0; j < M; j++)
        {
            cout << temp[j] << " ";
        }*/
        //cout << endl;
        if(lists.size() == 0)
        {
            cnts.push_back(1);
            lists.push_back(temp);
            continue;
        }
        //cout << lists.size() << endl;
        int flag = 1;
        for(int j = 0; j < lists.size(); j++)//和前面的查重比较
        {
            flag = 1;
            /*cout << "lists " << j << " ";
            for (int k = 0; k < M; k++)
            {
                cout << lists[j][k] << " ";
            }
            cout << endl;*/
            for(int k = 0; k < M; k ++)
            {
                if(lists[j][k] != temp[k])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)//如果有重复的
            {
                cnts[j] ++;
                break;
            }
        }
        if(!flag)
        {
            cnts.push_back(1);
            lists.push_back(temp);
        }
    }
    vector<codes> codelists;
    for(int i = 0; i < lists.size(); i ++)
    {
        codelists.push_back(codes(cnts[i], lists[i]));
    }
    sort(codelists.begin(), codelists.end());
    cout << cnts.size() << endl;
    for(int i = 0; i < lists.size() - 1; i++)
    {
        cout << codelists[i].cnt << " ";
        for(int j = 0; j < M - 1; j++)
        {
            cout << codelists[i].ans[j] << " ";
        }
        cout << codelists[i].ans[M - 1];
        cout << endl;
    }
    cout << codelists[cnts.size() - 1].cnt << " ";
    for (int j = 0; j < M - 1; j++)
    {
        cout << codelists[lists.size() - 1].ans[j] << " ";
        //cout << lists[lists.size() - 1][j] << " ";
    }
    cout << codelists[lists.size() - 1].ans[M - 1];
    system("pause");
    return 0; 
}