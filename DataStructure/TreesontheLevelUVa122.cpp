#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

#define maxn 100000

struct Node
{
    bool have_value;
    int v;
    Node *left, *right;
    Node() : have_value(false), left(NULL), right(NULL) {} //构造函数
};

Node *newnode()
{
    return new Node();
}

Node *root;
bool failed = false;
void addnode(int v, char *s)
{
    int n = strlen(s);
    Node *u = root;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            if (u->left == NULL)
                u->left = newnode();
            u = u->left;
        }
        else if (s[i] == 'R')
        {
            if (u->right == NULL)
                u->right = newnode();
            u = u->right;
        }
    }
    if (u->have_value)
        failed = true; //如果已经输入过了，表明重复输入
    u->v = v;
    u->have_value = true;
}

char s[maxn];
bool read_input()
{
    failed = false;
    root = newnode();
    for (;;)
    {
        if (scanf("%s", s) != 1)
            return false; //整个输入结束
        if (!strcmp(s, "()"))
            break; //读到结束标志，跳出循环
        int v;
        sscanf(&s[1], "%d", &v);        //读入节点值，存储在v中
        addnode(v, strchr(s, ',') + 1); //查找逗号，插入节点
    }
    return true;
}

bool bfs(vector<int> &ans)
{
    queue<Node *> q;
    ans.clear();
    q.push(root); //根节点入队
    while (!q.empty())
    {
        Node *u = q.front();
        q.pop(); //访问队首元素
        if (!u->have_value)
            return false;    //如果这个节点没有数据，就返回false
        ans.push_back(u->v); //当前节点的数据入队
        if (u->left != NULL)
            q.push(u->left); //有左孩子就左孩子入队
        if (u->right != NULL)
            q.push(u->right); //有右孩子就右孩子入队
    }
    return true;
}

void remove_tree(Node *u) //释放内存
{
    if (u == NULL)
        return;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}

int main()
{
    while (read_input())
    {
        vector<int> ans;
        if (bfs(ans) && !failed)
        {
            vector < int > :: iterator p;
            for (p = ans.begin(); p != ans.end(); p++)
            {
                if (p != ans.begin())
                    printf(" ");
                cout << *p; //这里真的是蜜汁格式错误
            }
            printf("\n");
        }
        else
            cout << "not complete" << endl;
        //cout<<endl;
        remove_tree(root);
    }
}
