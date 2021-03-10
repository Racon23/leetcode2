// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>

#include "commoncppproblem224.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        stack<int> ops;
        ops.emplace(1);
        
        int n = s.length();
        int sign = 1;
        int i = 0;
        int ret=0;
        while (i < n)
        {
            if (s[i] == ' ')
            {
                i++;
            }
            else if (s[i] == '+')
            {
                sign = ops.top();
                i++;
            }
            else if (s[i] == '-')
            {
                sign = -ops.top();
                i++;
            }
            else if (s[i] == '(')
            {
                ops.emplace(sign);
                i++;
            }
            else if (s[i] == ')')
            {
                ops.pop();
                i++;
            }
            else
            {
                long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9')
                {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                ret += sign * num;
            }
        }
        return ret;
    }
};
// @lc code=end
