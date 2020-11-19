// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem35.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        int mid = 0;
        int ans = n;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (target <= nums[mid])
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};
// @lc code=end
