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
            if (c == '[' || c == '{' || c == '(')
            {
                stk.emplace(c);
            }
            else
            {
                if(stk.empty()){
                    return false;
                }
                if (c == ']' && stk.top() == '[' || c == '}' && stk.top() == '{' || c == ')' && stk.top() == '(')
                {
                    stk.pop();
                }else{
                    return false;
                }
            }
        }
        if(stk.empty()){
            return true;
        }
        return false;
    }
};
// @lc code=end
