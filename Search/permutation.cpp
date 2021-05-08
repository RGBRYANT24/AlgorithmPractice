#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void print_permutation(int n, int* A, int cur)
{
    if(n == cur)//递归边界，用1-n填充数组0~n-1的位置
    {
        for(int i = 0; i < n; i ++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i ++)
    {
        int flag = 1;
        for(int j = 0; j < cur; j ++)//找一下之前有没有放过元素i
        {
            if(A[j] == i)
            {
                flag = 0;
            }
        }
        if(flag)
        {
            A[cur] = i;//如果之前没放过i，就在当前位置放i，然后继续递归
            print_permutation(n, A, cur + 1);
        }
    }
}

void print_dupulicate_permutation(int n, int* P, int* A, int cur)//给定排序后的数组P，输出P中元素的全排列。P中元素可能重复  终于没有bug了
{
    if(cur == n)
    {
        for(int i = 0; i < n; i ++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
        return;
    }
    else
    {
        for(int i = 0; i < n; i ++)
        {
            if(!i || P[i] != P[i-1])
            {
                int c1 = 0;
                int c2 = 0;
                for (int j = 0; j < cur; j++)
                {
                    if (A[j] == P[i])
                    {
                        c1++;
                    }
                }
                for (int j = 0; j < n; j++)
                {
                    if (P[i] == P[j])
                    {
                        c2++;
                    }
                }
                //cout << "find " << P[i] << " " << c1 << " " << c2 <<endl;
                if (c1 < c2)
                {
                    A[cur] = P[i];
                    print_dupulicate_permutation(n, P, A, cur + 1);
                }
            }          
        }
    }
}

int main()
{
    int n = 5;
    int A[5], P[5] = {5, 1, 3, 1, 4};
    /*cout << "print permutation of 1~n recursive method" << endl;
    print_permutation(n, A, 0);*/
    sort(P, P + sizeof(P) /  4);
    /*for(int i = 0; i < 5; i ++)
    {
        cout << P[i] <<" ";
    }
    cout << endl;*/
    print_dupulicate_permutation(n, P, A, 0);
    /*do
    {
        for(int i = 0; i < n; i ++)
        {
            cout << P[i] << " " ;
        }
        cout << endl;
    }while(next_permutation(P,P + sizeof(P) /  4));*/
    system("pause");
}
