// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem28.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.65%)
 * Likes:    601
 * Dislikes: 0
 * Total Accepted:    247.2K
 * Total Submissions: 623.5K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */

// @lc code=start
// 优化后
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0)
            return 0;
        int j = 0, i = 0;
        vector<int> next = getNext(needle);
        while (i < n && j < m)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        return j == m ? i - j : -1;
    }

    vector<int> getNext(string &pat)
    {
        int m = pat.size();
        vector<int> next(m, -1);
        // 从-1开始，用于判断是不是处于重来状态
        int k = -1, j = 0;
        while (j < m - 1)
        {
            if (k == -1 || pat[k] == pat[j])
            {
                k++;
                j++;
                // 额外增加一次验证，如果匹配就赋祖宗的值
                if (pat[k] != pat[j])
                {
                    next[j] = k;
                }
                else
                {
                    next[j] = next[k];
                }
            }
            else
            {
                // 不匹配就回溯到祖宗
                k = next[k];
            }
        }
        return next;
    }
};

// @lc code=end
