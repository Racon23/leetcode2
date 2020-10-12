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

// 二维数组
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
        vector<int, vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        dp[0][nums[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < target + 1; j++)
            {
                if (nums[i] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp[n-1][target];
    }
};
// @lc code=end
