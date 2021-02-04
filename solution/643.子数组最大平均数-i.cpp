// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem643.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        int maxn = sum;
        for (int i = k; i < n; i++)
        {
            sum = sum - nums[i - k] + nums[i];
            maxn = max(maxn, sum);
        }
        return maxn * 1.0 / k;
    }
};
// @lc code=end
