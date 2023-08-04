/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode.cn/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (55.69%)
 * Likes:    1609
 * Dislikes: 0
 * Total Accepted:    416K
 * Total Submissions: 746.8K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left  。请你反转从位置 left 到位置 right 的链表节点，返回
 * 反转后的链表 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目为 n
 * 1 
 * -500 
 * 1 
 * 
 * 
 * 
 * 
 * 进阶： 你可以使用一趟扫描完成反转吗？
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* p = head;
        ListNode *start, *end;
        int count = 0;
        stack<ListNode*> stk;
        if(left == 1)
        {
            start = head;
        }
        while(p)
        {
            count ++;
            if(count == left - 1)
            {
                start = p;
            }
            if(count >= left && count <= right)
            {
                //cout << p -> val << endl;
                stk.push(p);
                end = p -> next;
            }
            p = p -> next;
        }
        if(left <= 1)
        {
            p = stk.top();
            head = p;
            stk.pop();
        }
        else
        {
            p = start;
        }
        
        if(end)
            cout << end -> val << endl;
        while(!stk.empty())
        {
            p -> next = stk.top();
            p = p -> next;
            cout << p -> val << " ";
            stk.pop();
        }
        p -> next = end;
        return head;

    }
};
// @lc code=end

