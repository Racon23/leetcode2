// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem234.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (43.56%)
 * Likes:    672
 * Dislikes: 0
 * Total Accepted:    137.6K
 * Total Submissions: 315.5K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 * 
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
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }
        ListNode *fast = head->next, *slow = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid;
        // 偶数
        if (fast->next == nullptr)
        {
            mid = slow->next;
        }
        else if (fast->next->next == nullptr)
        {
            // 奇数
            mid = slow->next->next;
        }
        // 反转
        ListNode *pre, *post, *cur;
        pre = nullptr;
        cur = head;
        while (cur && pre != slow)
        {
            post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post;
        }
        // pre为反转头
        while (pre && mid)
        {
            if (pre->val == mid->val)
            {
                pre = pre->next;
                mid = mid->next;
            }else{
                break;
            }
        }
        if (!pre)
            return true;
        else
            return false;
    }
};
// @lc code=end
