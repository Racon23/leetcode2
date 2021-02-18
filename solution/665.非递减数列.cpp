/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                count++;
                if (count > 1)
                {
                    return false;
                }
                if (i > 0 && nums[i + 1] < nums[i - 1])
                {
                    nums[i + 1] = nums[i];
                }
            }
        }
        return true;
    }
};
// @lc code=end
