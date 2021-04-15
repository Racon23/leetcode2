// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem213.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        if (n <= 3)
            return *max_element(nums.begin(), nums.end());
        dp[0][0] = nums[0];
        dp[0][1] = max(dp[0][0], nums[1]);
        dp[1][1] = nums[1];
        dp[0][2] = max(dp[0][1], dp[0][0] + nums[2]);
        dp[1][2] = max(dp[1][1], nums[2]);
        for (int i = 3; i < n; i++)
        {
            dp[0][i] = max(dp[0][i - 1], dp[0][i - 2] + nums[i]);
            dp[1][i] = max(dp[1][i - 1], dp[1][i - 2] + nums[i]);
        }

        return max(dp[1][n - 1], dp[0][n - 2]);
    }
};
// @lc code=end
