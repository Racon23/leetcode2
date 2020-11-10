// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem327.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

// @lc code=start
// o(n2)
class Solution
{
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        long sum = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum >= lower && sum <= upper)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end
