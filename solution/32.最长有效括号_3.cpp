// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem32.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (34.03%)
 * Likes:    1053
 * Dislikes: 0
 * Total Accepted:    110.1K
 * Total Submissions: 323.5K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * 示例 1:
 * 
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 * 
 * 
 */

// @lc code=start
// 贪心 空间优化
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        int maxans = 0;
        int left = 0, right = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                left++;
            else
                right++;
            if (left == right)
            {
                maxans = max(maxans, right * 2);
            }
            else if (left < right)
            {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '(')
                left++;
            else
                right++;
            if (left == right)
            {
                maxans = max(maxans, right * 2);
            }
            else if (left > right)
            {
                left = right = 0;
            }
        }

        return maxans;
    }
};
// @lc code=end
