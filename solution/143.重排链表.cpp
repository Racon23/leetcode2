// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem143.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (59.25%)
 * Likes:    419
 * Dislikes: 0
 * Total Accepted:    63.7K
 * Total Submissions: 107.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
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
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
        {
            return;
        }
        // 获取中间节点
        ListNode *mid = getMiddle(head);

        // 反转后半
        ListNode *post = reverseList(mid->next);
        mid->next=nullptr;

        // 合并
        ListNode *l1 = head;
        mergeList(l1, post);
    }

    ListNode *getMiddle(ListNode *head)
    {
        ListNode *fast, *slow;
        slow = head;
        fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *mid)
    {
        ListNode *pre, *cur, *post;
        cur = mid;
        pre = nullptr;
        while (cur)
        {
            post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post;
        }
        return pre;
    }

    void mergeList(ListNode *l1, ListNode *l2)
    {
        ListNode *l1t, *l2t;
        while (l1 && l2)
        {
            l1t = l1->next;
            l2t = l2->next;
            l1->next = l2;
            l1 = l1t;
            l2->next = l1;
            l2 = l2t;
        }
    }
};
// @lc code=end
