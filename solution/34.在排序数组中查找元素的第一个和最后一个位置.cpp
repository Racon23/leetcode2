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

        int left, right, mid;
        left = 0;
        right = n - 1;
        vector<int> ret(2, -1);
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target && (mid == 0 || nums[mid - 1] < target))
            {
                ret[0] = mid;
                break;
            }
            else if (nums[mid] >= target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }


        left = 0;
        right = n - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target && (mid == n-1 || nums[mid + 1] > target))
            {
                ret[1] = mid;
                break;
            }
            else if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ret;
    }
};
// @lc code=end
