#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a;
    for(int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        a.push_back(n);
    }
    sort(a.begin(), a.end());
    int min_num = a[0];
    int max_num = a[a.size()-1];
    int min_count = 1;
    int max_count = 1;
    for(int i = 1; i < N; i++)
    {
        if(min_num == a[i])
        {
            min_count ++;
        }
        else
        {
            break;
        }
    }
    for(int i = N -2; i >= 0; i --)
    {
        if(max_num == a[i])
        {
            max_count ++;
        }
        else
        {
            break;
        }
    }
    cout << min_num << " " << min_count << endl;
    cout << max_num << " " << max_count;
    return 0;
}