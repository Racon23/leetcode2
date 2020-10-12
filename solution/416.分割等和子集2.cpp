// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include "commoncppproblem416.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// 一维数组
// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
        {
            return false;
        }
        int target = sum / 2;
        int maxNum = *max_element(nums.begin(), nums.end());
        if (maxNum > target)
        {
            return false;
        }
        // vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        vector<int> dp(target + 1, 0);

        dp[0] = 1;
        dp[nums[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = dp[j] | dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};
// @lc code=end
