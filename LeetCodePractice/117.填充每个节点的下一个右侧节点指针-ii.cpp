/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 *
 * https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (66.18%)
 * Likes:    751
 * Dislikes: 0
 * Total Accepted:    199.7K
 * Total Submissions: 301.1K
 * Testcase Example:  '[1,2,3,4,5,null,7]'
 *
 * 给定一个二叉树：
 * 
 * 
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 * 
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。
 * 
 * 初始状态下，所有 next 指针都被设置为 NULL 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,4,5,null,7]
 * 输出：[1,#,2,3,#,4,5,7,#]
 * 解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化输出按层序遍历顺序（由 next
 * 指针连接），'#' 表示每层的末尾。
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数在范围 [0, 6000] 内
 * -100 <= Node.val <= 100
 * 
 * 
 * 进阶：
 * 
 * 
 * 你只能使用常量级额外空间。
 * 使用递归解题也符合要求，本题中递归程序的隐式栈空间不计入额外空间复杂度。
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<pair<Node*, int>> q;
        int cur = 0;//当且层数
        Node* pre = root;
        if(!root) return root;
        q.push({root, 0});
        while(!q.empty())
        {
            Node *node;
            int level;
            tie(node, level) = q.front();
            q.pop();
            if(node != root)
            {
                if(cur == level)
                {
                    pre -> next = node;
                    pre = node;
                    cur = level;
                }
                else
                {
                    pre -> next = NULL;
                    cur = level;
                    pre = node;
                }
            }
            if(node -> left) q.push({node -> left, level + 1});
            if(node -> right) q.push({node -> right, level + 1});
        }
        return root;
    }
};
// @lc code=end

