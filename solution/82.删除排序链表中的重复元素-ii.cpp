// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem82.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *p, *pre, *hair;
        if (!head)
        {
            return head;
        }
        hair = new ListNode(-1);
        hair->next = head;
        pre = hair;
        p = pre->next;
        int num = p->val;
        p = p->next;
        int flag = 0;
        while (p)
        {
            if (p->val != num)
            {
                if (flag == 1)
                {
                    pre->next = p;
                    flag = 0;
                }
                else
                {
                    pre = pre->next;
                }
                num = p->val;
            }
            else
            {
                flag = 1;
            }
            p = p->next;
        }
        if (flag == 1)
        {
            pre->next = p;
        }
        return hair->next;
    }
};
// @lc code=end
