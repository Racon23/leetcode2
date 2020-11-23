// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem41.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (auto &it : nums)
        {
            if (it <= 0)
                it = n + 1;
        }
        for (int i = 0; i < n; i++)
        {
            int temp = abs(nums[i]);
            if (temp > 0 && temp <= n)
            {
                nums[temp - 1] = -abs(nums[temp - 1]);
            }
        }
        int ret = n + 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0){
                ret = i + 1;
                break;
            }
        }
        return ret;
    }
};
// @lc code=end
