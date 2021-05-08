#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int n, m, N;
    cin >> n >> m >>N;
    //cout << to_string(n) << endl;
    string ans = "";
    ans += to_string(n);
    ans += to_string(m);
    int cur = 0;
    while(ans.length() <= N)
    {
        int temp = (ans[cur] - 48) * (ans[cur + 1] - 48);
        ans += to_string(temp);
        cur ++;
    }
    for(int i = 0; i < N - 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << ans[N - 1];
    return 0;
}