#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int num[30];
    for(int i=0; i < 24; i ++)
    {
        cin >> num[i];
    }
    int time;
    int count = 0;
    while (cin >> time )
    {
        if(time >= 24 || time < 0)
        {
            break;
        }
        if (count)
        {
            cout << endl;
        }
        count++;
        cout << num[time];
        if(num[time] > 50)
        {
            cout << " Yes";
        }
        else
        {
            cout << " No";
        }
    }
    return 0;
}