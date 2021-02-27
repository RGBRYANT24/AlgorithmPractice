#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//子集树

void findSubset(int index, int length, vector<int>allset, vector<int>subset)
{
    if(index == length)
    {
        for(int i=0;i<subset.size();i++)
        {
            cout<<subset[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        subset.push_back(allset[index]);
        findSubset(index+1, length, allset, subset);
        subset.pop_back();
        findSubset(index+1, length, allset, subset);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> allset;
    vector<int> subset;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        allset.push_back(tmp);
    }
    findSubset(0,n,allset,subset);
    cout<<"finish"<<endl;
    cin>>n;
}
