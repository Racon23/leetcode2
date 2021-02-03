/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */

// @lc code=start
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 0)
            return -1;
        if (size == 1)
            return 0;

        int left = 0, right = 0;
        for (int i = 1; i < size; i++)
        {
            right += nums[i];
        }

        for (int i = 0; i < size; i++)
        {
            if (left == right)
            {
                return i;
            }
            left += nums[i];
            right -= nums[i + 1];
        }
        return -1;
    }
};
// @lc code=end
