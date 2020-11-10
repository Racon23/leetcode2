// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem31.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (34.62%)
 * Likes:    720
 * Dislikes: 0
 * Total Accepted:    96.9K
 * Total Submissions: 280K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int i = n - 1;
        while (i >= 1)
        {
            // 找到顶点
            if (nums[i] > nums[i - 1])
            {
                int j = i;
                // 找到比它大一点的点
                while (j < n && nums[j] > nums[i - 1])
                {
                    j++;
                }
                // 交换
                int temp = nums[i - 1];
                nums[i - 1] = nums[j - 1];
                nums[j - 1] = temp;
                // 倒序
                reverse(nums.begin() + i, nums.end());
                break;
            }
            i--;
        }
        if (i == 0)
        {
            reverse(nums.begin(), nums.end());
        }
    }
};
// @lc code=end
