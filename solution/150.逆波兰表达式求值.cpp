// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem150.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int n = tokens.size();
        stack<int> nums;
        for (int i = 0; i < n; i++)
        {
            int len = tokens[i].length();
            if (isdigit(tokens[i][len-1]))
            {
                int num = stoi(tokens[i]);
                nums.emplace(num);
            }
            else
            {
                int a;
                int b;
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                switch (tokens[i][0])
                {
                case '+':
                    nums.emplace(a + b);
                    break;
                case '-':
                    nums.emplace(a - b);
                    break;
                case '*':
                    nums.emplace(a * b);
                    break;
                case '/':
                    nums.emplace(a / b);
                    break;
                }
            }
        }
        return nums.top();
    }
};
// @lc code=end
