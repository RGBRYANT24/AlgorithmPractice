#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int key;
    TreeNode* left;
    TreeNode* right;
    int size; //当前节点为根的子树大小
    int count; //当前节点的重复数量
    //TreeNode(): val(0), left(nullptr), right(nullptr){}
    //TreeNode(int x): key(x), left(nullptr), right(nullptr), size(1){}
};

TreeNode* insert(TreeNode* root, int val)
{
    if(root == nullptr) return new TreeNode(val);
    cout  << " " << val << endl;
    //return root;
    if(root -> key > val) root -> left = insert(root -> left, val);
    else if(root -> key < val) root -> right = insert(root -> right, val);
    else root -> count ++;
    return root;
}

//遍历二叉搜索树 递归
void inorderTraversal(TreeNode* root)
{
    if(root == nullptr) return;
    inorderTraversal(root -> left);
    cout << root -> key << endl;
    inorderTraversal(root -> right);
}

int main()
{
    vector<int> nums = {2};
    TreeNode* root;
    cout << int(root == nullptr) << endl;
    for(int i = 0; i < nums.size(); i ++)
    {
        root = insert(root, nums[i]);
    }
    //inorderTraversal(root);
    system("pause");
    return 0;
}
