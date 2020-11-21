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
// 自底向上
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        int n = 0; //记录链表长度
        ListNode *p1 = head;
        while (p1)
        {
            p1 = p1->next;
            n++;
        }

        int k = 1;     // 初始值，一个节点
        int count = 0; // 迭代k

        ListNode *mid, *nexthead, *lasttail, *p2; // 找到中位

        ListNode *start = new ListNode(-1); // 不用每次都初始化
        start->next =head;

        ListNode *lh, *rh; // 左右两部分

        while (k < n)
        {
            k *= 2;

            lasttail = start;

            while (lasttail->next)
            {
                count = 1;
                mid = lasttail->next;

                // 找到中位节点
                // mid->next 空，说明前半部分已经排好序，直接跳出
                while (count < k / 2&&mid->next)
                {
                    mid = mid->next;
                    count++;
                }
                if(!mid->next) break;

                // 断开两个有序链表
                lh = lasttail->next;
                rh = mid->next;
                mid->next = nullptr;
                mid = rh;
                while (count < k-1&&mid->next)
                {
                    mid = mid->next;
                    count++;
                }
                nexthead = mid->next;
                mid->next = nullptr;

                // 合并两个有序链表
                p2 = lasttail;

                while (lh || rh)
                {
                    if (!lh)
                    {
                        p2->next = rh;
                        rh = rh->next;
                    }
                    else if (!rh)
                    {
                        p2->next = lh;
                        lh = lh->next;
                    }
                    else
                    {
                        if (lh->val < rh->val)
                        {
                            p2->next = lh;
                            lh = lh->next;
                        }
                        else
                        {
                            p2->next = rh;
                            rh = rh->next;
                        }
                    }
                    p2 = p2->next;
                }

                // lasttail->next = hair->next;
                p2->next = nexthead;
                lasttail = p2;

            }
        }

        return start->next;
    }
};
// @lc code=end
