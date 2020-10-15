// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem19.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p1, *p2;
        p1 = p2 = head;
        for (int i = 0; i < n; i++)
        {
            p2 = p2->next;
        }
        if(!p2){
            return head->next;
        }
        while(p2->next){
            p1=p1->next;
            p2=p2->next;
        }
        p1->next=p1->next->next;
        return head;
    }
};
// @lc code=end
