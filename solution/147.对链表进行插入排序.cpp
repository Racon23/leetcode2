// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem147.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *hair = new ListNode(-1);
        ListNode *p1, *p2, *p3; // p1 记录当前节点，p2下一节点，p3迭代
        hair->next = head;

        p1 = head->next;
        head->next = nullptr;
        while (p1)
        {
            p2 = p1->next;
            // p1->next = nullptr;
            p3 = hair;
            while (p3->next && p3->next->val < p1->val)
            {
                p3 = p3->next;
            }
            p1->next = p3->next;
            p3->next = p1;

            p1 = p2;
        }
        return hair->next;
    }
};
// @lc code=end
