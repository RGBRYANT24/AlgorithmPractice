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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;
        ListNode* dummyHead = new ListNode(0);
        dummyHead -> next = ans;
        bool flag = true;
        int n = lists.size();
        while(flag)
        {
            int id = -1;
            int count = 0;
            int min_num = INT_MAX;
            for(int i = 0; i < n; i ++)
            {
                
                
                // ListNode* p = lists[i];
                if(!lists[i])
                {
                    count ++;
                    continue;
                }
                else if(min_num > lists[i] -> val)
                {
                    //cout << i << " " << lists[i] -> val << " " << min_num ;
                    id = i;
                    min_num = lists[i] -> val;
                    //cout << " change " << min_num << endl;
                    
                }
            }
            ;
            if(count == n) return dummyHead -> next;
            if(!ans) 
            {
                ans = lists[id];
                dummyHead -> next = ans;
                //cout << " ans " << ans -> val << endl;
            }
            else
            {
                ans -> next = lists[id];
                ans = ans -> next;
                //cout << " ans " << ans -> val << endl;
            }
            lists[id] = lists[id] -> next;
            //cout << endl;
            

        }
        return dummyHead -> next;
    }
};
// @lc code=end

