#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int N;
    double M;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        double d;
        cin >> d;
        if(d < M && i < N - 1)
        {
            printf("On Sale! %.1f\n", d);
        }
        else if(d < M && i == N - 1)
        {
            printf("On Sale! %.1f", d);
        }
    }
    system("pause");
    return 0; 
}