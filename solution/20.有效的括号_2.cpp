// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem20.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (char c : s)
        {
            if (c == '{')
                stk.emplace('}');
            else if (c == '[')
                stk.emplace(']');
            else if (c == '(')
                stk.emplace(')');
            else if (stk.empty() || c != stk.top())
                return false;
            else stk.pop();
        }
        return stk.empty();
    }
};
// @lc code=end
