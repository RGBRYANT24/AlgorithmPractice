#include <bits/stdc++.h>

using namespace std;

class Practice_12_6
{
private:
    //vector<int> *p; //使用内置指针
    shared_ptr<vector<int>> p;
public:
    //Practice_12_6(): p(new vector<int>) {};//使用内置指针
    Practice_12_6(): p(make_shared<vector<int>>()) {};
    void read();
    void print();
    //~Practice_12_6() {delete p;};
    ~Practice_12_6() {};
};

void Practice_12_6::read()
{
    int temp;
    while(cin >> temp && temp != -1)
    {
        this -> p -> push_back(temp);
    }
}

void Practice_12_6::print()
{
    for(const auto& i : *p) cout << i << " ";
    cout << endl;
}

int main()
{
    Practice_12_6 test_obj;
    test_obj.read();
    test_obj.print();
    system("pause");
    return 0;

}