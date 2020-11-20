// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem38.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution
{
public:
    string countAndSay(int n)
    {
        int start = 0;
        int end = 0;
        string pre = "";
        string cur = "1";
        int len;
        int count = 1;
        while (count < n)
        {
            pre = cur;
            cur = "";
            len = pre.size();
            start = 0;
            end = 1;
            while (start < len)
            {
                while (end < len && pre[end] == pre[end - 1])
                {
                    end++;
                }
                cur += to_string(end - start) + pre[start];
                start = end;
                end++;
            }
            count++;
        }

        return cur;
    }
};
// @lc code=end
