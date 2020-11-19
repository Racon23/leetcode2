// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem34.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> ret(2, -1);
        int mid = 0;
        int l = 0, r = n - 1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] >= target)
            {
                if (nums[mid] == target && (mid == 0 || nums[mid - 1] < target))
                {
                    ret[0] = mid;
                    break;
                }
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        l = 0, r = n - 1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] <= target)
            {
                if (nums[mid] == target && (mid == n - 1 || nums[mid + 1] > target))
                {
                    ret[1] = mid;
                    break;
                }
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return ret;
    }
};
// @lc code=end
