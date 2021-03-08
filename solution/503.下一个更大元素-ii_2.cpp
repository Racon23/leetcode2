// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem503.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
// 单调栈
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> stk;
        vector<int> ret(n, -1);
        for (int i = 0; i < 2 * n - 1; i++)
        {
            while (!stk.empty() && nums[stk.top()] < nums[i % n])
            {
                ret[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ret;
    }
};
// @lc code=end
