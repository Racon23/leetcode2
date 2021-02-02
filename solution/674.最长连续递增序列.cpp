// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem674.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int n = nums.size();
        if(n<=1) return n;
        int left = 0, right = 1;
        int maxn = 1;
        while (right <= n)
        {
            if (right == n || nums[right] <= nums[right - 1])
            {
                maxn = max(maxn, right - left);
                left = right;
            }
            right++;
        }
        return maxn;
    }
};
// @lc code=end
