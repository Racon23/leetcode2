// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem330.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */

// @lc code=start
class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int size = nums.size();
        long long x = 1;
        int idx = 0;
        int patches = 0;
        // 由于覆盖x-1，未覆盖x，所以等于x还要继续
        while (x <= n)
        {
            if (idx < size && nums[idx] <= x)
            {
                x += nums[idx];
                idx++;
            }
            else
            {
                x <<= 1;
                patches++;
            }
        }

        return patches;
    }
};
// @lc code=end
