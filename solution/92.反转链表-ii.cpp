// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem92.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *hair = new ListNode(-1);
        hair->next = head;
        ListNode *p = hair;
        ListNode *p1, *p2,*p3;
        int i = 1;
        while (i < left)
        {
            p = p->next;
            i++;
        }
        p1 = p->next;
        p2 = p->next;
        p3 = p->next;
        while (i <= right)
        {
            p->next = p2;
            p2 = p2->next;
            p->next->next = p1;
            p1 = p->next;
            i++;
        }
        p3->next = p2;
        return hair->next;
    }
};
// @lc code=end
