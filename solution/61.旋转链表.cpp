// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem61.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        int n = 0;
        ListNode *nhead;
        ListNode *p = head;
        ListNode *tail;
        if (k == 0)
            return head;
        while (p)
        {
            tail = p;
            p = p->next;
            n++;
        }
        if (n == 0)
        {
            return head;
        }
        int r = k % n;
        nhead = head;
        if (r > 0)
        {
            r = n - r - 1;
            p = head;
            while (r > 0 && p->next)
            {
                p = p->next;
                r--;
            }
            nhead = p->next;
            p->next = nullptr;
            tail->next = head;
        }

        return nhead;
    }
};
// @lc code=end
