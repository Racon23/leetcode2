// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <numeric>
#include "commoncppproblem227.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        vector<int> nums;
        int n = s.length();
        char preSign = '+';
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1)
            {
                switch (preSign)
                {
                case '+':
                    nums.emplace_back(num);
                    break;
                case '-':
                    nums.emplace_back(-num);
                    break;
                case '*':
                    nums.back() *= num;
                    break;
                case '/':
                    nums.back() /= num;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
// @lc code=end
