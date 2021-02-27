#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//z在全集里面找到一个元素个数少于等于x的子集，使其和等于T
int n, x, T;
int flag = false;

int getSum(vector<int> subset)
{
    int sum = 0;
    for (int i = 0; i < subset.size(); i++)
    {
        sum += subset[i];
    }
    return sum;
}
void findSubset(int index, vector<int> allset, vector<int> subset)
{
    int sum = getSum(subset);
    if (index == allset.size() && sum != T)
    {
        return;
    }
    if (sum == T && subset.size() <= x)
    {
        flag = true;
        for (int i = 0; i < subset.size() - 1; i++)
        {
            cout << subset[i] << ",";
        }
        cout << subset[subset.size() - 1] << endl;
    }
    else
    {
        subset.push_back(allset[index]);
        findSubset(index + 1, allset, subset);
        subset.pop_back();
        findSubset(index + 1, allset, subset);
    }
}

int main()
{
    cin >> n;
    cin >> x;
    cin >> T;
    vector<int> allset;
    vector<int> subset;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        allset.push_back(temp);
    }
    findSubset(0, allset, subset);
    if(flag == false)
    {
        cout<<"No such a subset!";
    }
    cout << "finish" << endl;
    cin >> n;
}