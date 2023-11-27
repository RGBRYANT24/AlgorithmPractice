/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode.cn/problems/sort-list/description/
 *
 * algorithms
 * Medium (65.57%)
 * Likes:    2161
 * Dislikes: 0
 * Total Accepted:    448.5K
 * Total Submissions: 684.5K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 * 
 * 
 * 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
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
    ListNode* sortList(ListNode*head, ListNode* tail)
    {
        if(head == nullptr) return nullptr;
        if(head -> next == tail)//合并的区间是左闭右开的
        {
            head -> next = nullptr;//具体体现在tail是不参与当前合并的
            return head;
        }
        ListNode *fast = head, *slow = head;
        while(fast != tail)
        {
            fast = fast -> next;
            slow = slow -> next;
            if(fast != tail) fast = fast -> next;
        }
        ListNode *mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));//合并的区间是左闭右开的
    }
    ListNode* merge(ListNode* a, ListNode* b)
    {
        ListNode* dummyHead = new ListNode();
        ListNode *p = dummyHead, *pa = a, *pb = b;
        while(pa != nullptr && pb != nullptr)
        {
            if(pa -> val < pb -> val)
            {
                p -> next = pa;
                pa = pa -> next;
            }
            else
            {
                p -> next = pb;
                pb = pb -> next;
            }
            p = p -> next;
        }
        p -> next = pa ? pa : pb;
        return dummyHead -> next;
    }
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }
};
// @lc code=end

