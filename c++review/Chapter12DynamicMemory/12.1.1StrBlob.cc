//#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
using namespace std;

class StrBlob
{
private:
    /* data */
    shared_ptr<vector<string>> data;
    //如果data[i]不合法，抛出一个异常
    void check(int i, const string& msg) const;
public:
    //typedef vector<string>:: int int;
    StrBlob();
    StrBlob(initializer_list<string> i1);
    int size() const {return data -> size();}
    bool empty() const {return data -> empty();}
    //添加和删除元素
    void push_back(const string& t) {data -> push_back(t);}
    void pop_back();
    //元素访问
    string& front();
    string& back();
    void print() const;
    ~StrBlob();
};

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> i1) : data(make_shared<vector<string>>(i1)) {}

void StrBlob::check(int i, const string &msg) const
{
    if(i >= data->size())
    {
        throw out_of_range(msg);
    }
}

string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

void StrBlob::print() const
{
    for(const auto &p : *data) cout << p << " ";
    cout << endl;
}

StrBlob::~StrBlob() {}

int main()
{
    StrBlob b1;
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b1.print();
    b2.push_back("another");
    b1.print();
    cout << " test " << endl;
    system("pause");
    return 0;
}
