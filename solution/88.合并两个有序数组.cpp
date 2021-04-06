/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 || j >= 0)
        {
            if (j < 0)
            {
                nums1[k--] = nums1[i--];
            }
            else if (i < 0)
            {
                nums1[k--] = nums2[j--];
            }
            else
            {
                if (nums2[j] > nums1[i])
                {
                    nums1[k--] = nums2[j--];
                }
                else
                {
                    nums1[k--] = nums1[i--];
                }
            }
        }
    }
};
// @lc code=end
