// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem21.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *p1, *p2;
        if (!l2)
            return l1;
        if (!l1)
            return l2;
        if (l1->val < l2->val)
        {
            p1 = p2 = l1;
            l1 = l1->next;
        }
        else
        {
            p1 = p2 = l2;
            l2 = l2->next;
        }
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                p2->next = l1;
                l1 = l1->next;
            }
            else
            {
                p2->next = l2;
                l2 = l2->next;
            }
            p2 = p2->next;
        }
        if (!l2)
        {
            p2->next = l1;
        }
        if (!l1)
        {
            p2->next = l2;
        }
        return p1;
    }
};
// @lc code=end
