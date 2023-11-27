/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 *
 * https://leetcode.cn/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (58.58%)
 * Likes:    2703
 * Dislikes: 0
 * Total Accepted:    728.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * 示例 2：
 * 
 * 输入：lists = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：lists = [[]]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
 * 
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
    ListNode* merge2Lists(ListNode* a, ListNode* b)
    {
        if((!a) || (!b)) return a ? a : b;
        ListNode* head = new ListNode();
        ListNode* tail = head;
        ListNode *pa = a, *pb = b;
        while(pa != nullptr && pb != nullptr)
        {
            if(pa -> val < pb -> val)
            {
                tail -> next = pa;
                pa = pa -> next;
            }
            else
            {
                tail -> next = pb;
                pb = pb -> next;
            }
            tail = tail -> next;
        }
        if(!pa) tail -> next = pb;
        else tail -> next = pa;
        return head -> next;
    }

    ListNode* mergeLists(vector<ListNode*>& lists, int l, int r)
    {
        if(l == r) return lists[l];
        if(l > r) return nullptr;
        int mid = (l + r) >> 1;
        return merge2Lists(mergeLists(lists, l, mid), mergeLists(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
       return mergeLists(lists, 0, lists.size() - 1);
    }
};
// @lc code=end

