// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem86.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *small, *large;
        small = new ListNode(0);
        large = new ListNode(0);
        ListNode *smallhead, *largehead;
        smallhead = small;
        largehead = large;
        ListNode *p;
        p = head;
        while (p != nullptr)
        {
            if (p->val >= x)
            {
                large->next = p;
                large = large->next;
            }
            else
            {
                small->next = p;
                small = small->next;
            }
            p=p->next;
        }
        large->next = nullptr;
        small->next = largehead->next;

        return smallhead->next;
    }
};
// @lc code=end
