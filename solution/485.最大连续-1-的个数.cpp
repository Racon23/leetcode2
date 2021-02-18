/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 */

// @lc code=start
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0, maxn = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                ans++;
            }
            else
            {
                maxn = max(ans, maxn);
                ans = 0;
            }
        }
        maxn = max(ans, maxn);
        return maxn;
    }
};
// @lc code=end
