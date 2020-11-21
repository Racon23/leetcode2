// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem148.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
// 自顶向下
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
    }

    ListNode *mergeSort(ListNode *sh)
    {
        if (!sh||!sh->next)
        {
            return sh;
        }

        ListNode *fast, *slow;
        fast = slow = sh;

        // 找到中位
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 断开
        ListNode *lh = sh, *rh = slow->next;
        slow->next = nullptr;

        lh = mergeSort(lh);
        rh = mergeSort(rh);

        // 合并两个有序链表
        ListNode *hair, *p1;
        hair = new ListNode(-1);
        p1 = hair;
        while (lh || rh)
        {
            if (!lh)
            {
                p1->next = rh;
                rh = rh->next;
            }
            else if (!rh)
            {
                p1->next = lh;
                lh = lh->next;
            }
            else
            {
                if (lh->val < rh->val)
                {
                    p1->next = lh;
                    lh = lh->next;
                }
                else
                {
                    p1->next = rh;
                    rh = rh->next;
                }
            }
            p1 = p1->next;
        }

        return hair->next;
    }
};
// @lc code=end
