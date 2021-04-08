/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();

        int left = 0, right = n - 1;
        if (nums[left] <= nums[right])
        {
            return nums[left];
        }
        int k;

        while (left < right)
        {
            k = (left + right) / 2;
            if (nums[right] > nums[k])
            {
                right = k;
            }
            else
            {
                left = k + 1;
            }
        }

        return nums[left];
    }
};
// @lc code=end
