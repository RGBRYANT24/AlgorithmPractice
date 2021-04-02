#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n, kase = 0;
    while(cin >> n)
    {
        kase ++;
        long long ans = 0;
        vector<int> a;
        for(int i = 0; i < n; i ++)
        {
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        for(int i = 0; i < n; i ++)
        {
            long long temp = 1;
            for(int j = i; j < n; j ++)
            {
                temp *= a[j];
                ans = ans <= temp ? temp : ans;
                //cout << temp << endl;
            }
        }
        cout << "Case #" << kase << ": The maximum product is " << ans << "." << endl << endl;
    }
}