#include <iostream>
#include <stdio.h>

using namespace std;

void unpacking_bytes()
{
    unsigned int i1 = 1835098984u;
    unsigned int i2 = 1768842611u;
    unsigned char c1=(unsigned char)(i1>>24);
    cout<<c1<<endl;
    unsigned int temp1=i1<<8;
    unsigned char c2=(unsigned char)(temp1>>24);
    cout<<c2<<endl;
}

int main()
{
    unpacking_bytes();
    getchar();
}