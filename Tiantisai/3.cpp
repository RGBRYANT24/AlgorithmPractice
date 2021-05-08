#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s.length() > 4)
    {
        for(int i = 0; i < 4; i++)
        {
            cout << s[i] ;
        }
        cout << "-" ;
        for(int i = 4; i < s.length(); i++)
        {
            cout << s[i];
        }
    }
    else
    {
        int y = (s[0] - 48) * 10 + s[1] - 48;        
        if(y < 22)
        {
            if (y < 10)
            {
                cout << "200" << y << "-" << s[2] << s[3];
            }
            else
            {
                cout << "20" << y << "-" << s[2] << s[3];
            }
            
        }
        else
        {
            cout << "19" << y << "-" << s[2] << s[3];
        }
    }
    return 0;
}