/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int k = 1;
        int i = 1;
        int pre = nums[0];
        int flag = 0;
        while (i < n)
        {
            if (nums[i] == pre)
            {
                if (flag == 1)
                {
                    i++;
                }
                else
                {
                    flag = 1;
                    nums[k++] = nums[i++];
                }
            }
            else
            {
                flag = 0;
                pre = nums[i];
                nums[k++] = nums[i++];
            }
        }
        return k;
    }
};
// @lc code=end
