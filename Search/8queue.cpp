#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <cstring>

using namespace std;

int n;
int cnt = 0;
int A[10][20];//用二维数组判断
int C[10];

void search(int cur)
{
    if(cur ==n)
    {
        cnt ++;
        /*for(int i = 0; i < n; i ++)
        {
            int temp = C[i];
            for(int j = 0; j < n; j ++)
            {
                if(j == temp)
                {
                    cout << "1 ";
                }
                else cout << "0 ";
            }
            cout <<endl;
        }
        cout << endl;*/
        return;
    }
    /*for(int i = 0; i < n; i++)
    {
        if(A[0][i] != 1 && A[1][cur + i] != 1 && A[2][cur - i + n] != 1)//用二维数组直接判断
        {
            A[0][i] = 1;
            A[1][cur + i] = 1;//左下到右上的对角线，同一条对角线横纵坐标之和相等
            A[2][cur - i + n] = 1;//左上到 右下的对角线，同一条对角线横纵坐标之差相等，+n是为了数组下标不能是负数
            C[cur] = i;
            search(cur + 1);
            //把状态改回来，好进行DFS
            A[0][i] = 0;
            A[1][cur + i] = 0;     //左下到右上的对角线，同一条对角线横纵坐标之和相等
            A[2][cur - i + n] = 0; //左上到 右下的对角线，同一条对角线横纵坐标之差相等，+n是为了数组下标不能是负数
        }
    }*/
    //一维数组
    for(int i = 0; i < n; i ++)
    {
        int flag = 1;
        C[cur] = i;//尝试将cur行的皇后放在第i列
        for(int j = 0; j < cur; j ++)//看看和之前的皇后是不是冲突
        {
            int temp = C[j];
            if(temp == i || temp + j == i + cur || j - temp  == cur - i)//注意主对角线是行-列相等 顺序不要搞反了
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            search(cur + 1);
        }
        C[cur] = 0;
    }
}
int main()
{
    n = 8;
    memset(A, 0, sizeof(A));
    search(0);
    cout << cnt << endl;
    system("pause");

}