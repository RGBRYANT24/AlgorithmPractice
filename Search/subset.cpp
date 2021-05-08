#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>

using namespace std;
int P[] = {1, 2, 3};

void print_incremental_subset(int n, int* A, int cur)//这里输出的实际上是数组的下标 用另一个数组P来存储要输出的元素就行
{
    for(int i = 0; i < cur; i ++)
    {
        //cout << A[i] << " ";
        int c = A[i];
        cout << P[c] << " ";
    }
    if(cur != 0) 
        cout << endl;
    int s = cur ? A[cur - 1] + 1 : 0; 
    for(int i = s; i < n; i ++)
    {
        A[cur] = i;
        print_incremental_subset(n, A, cur + 1);
    }
}

void print_bit_subset(int n, int* B, int cur)
{
    if(cur == n)
    {
        for(int i = 0; i < n; i ++)
        {
            if(B[i])
            {
                cout << i << " ";
            }
        }
        cout << endl;
        return;
    }
    else
    {
        B[cur] = 1;
        print_bit_subset(n, B, cur + 1);
        B[cur] = 0;
        print_bit_subset(n, B, cur + 1);
    }
}

void print_binary_subset(int n, int s)
{
    for(int i = 0; i < n; i ++)//输出的是s的子集
    {
        if(s&(1<<i))
        {
            cout << i << " ";
        }
    }
    if(s)
        cout << endl;
    /*for (int i = 0; i < (1 << n); i++)//应该是在外面调用的
    {
        print_binary_subset(n, i);
    }*/
}

int main()
{
    //cout << (1<<1) << endl;
    int n = 3;
    int* A = new int[n];
    //print_incremental_subset(n, A, 0);
    memset(A, 0, sizeof(A));
    //print_bit_subset(n, A, 0);
    for (int i = 0; i < (1 << n); i++)
    {
        print_binary_subset(n, i);
    }
    system("pause");
}