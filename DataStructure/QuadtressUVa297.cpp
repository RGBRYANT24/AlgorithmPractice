#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>

using namespace std;

const int len = 1024;
int dot[len + 5][len + 5];
string str;
int count = 0;

void draw(int height, int width, int len, int &index) //传入左下角坐标和边长
{
    //cout<<str[index]<<endl;
    if (str[index] == 'e')
        return;
    if (str[index] == 'f')
    {
        for (int i = height; i < height + len; i++)
        {
            for (int j = width; j < width + len; j++)
            {
                if (dot[i][j] == 0)
                {
                    count++;
                }
                dot[i][j] = 1;
            }
        }
    }
    else
    {
        draw(height + len / 2, width + len / 2, len / 2, ++index); //右上
        draw(height + len / 2, width, len / 2, ++index);           //左上
        draw(height, width, len / 2, ++index);                     //左下
        draw(height, width + len / 2, len / 2, ++index);           //右下
    }
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        memset(dot, 0, sizeof(dot));
        count=0;
        cin >> str;
        int index = 0;
        draw(0, 0, 32, index);
        cin>>str;
        index = 0;
        draw(0, 0, 32, index);
        cout<<"There are "<<count<<" black pixels."<<endl;
    }
    /*getchar();
    getchar();*/
}