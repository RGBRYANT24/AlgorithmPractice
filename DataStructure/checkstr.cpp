#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

bool judge(const string& str, int start, int last)
{
    cout << str[start] << " " << str [last] << endl;
    if(str[start] != str[last])
    {
        return false;
    }
    if (start + last == str.length() -1)
    {
        return true;
    }
    return judge(str, ++start, --last);
}

int main()
{
    string str;
    cin >> str;
    cout << judge(str, 0, str.length()-1);
    system("pause");
}