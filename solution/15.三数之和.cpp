// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem15.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (29.60%)
 * Likes:    2666
 * Dislikes: 0
 * Total Accepted:    343.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int a, b, c;
        int len = nums.size();
        int k = len - 1;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < len; i++)
        {
            a = nums[i];
            for (int j = i + 1; j < len - 1; j++)
            {
                b = nums[j];
                k = len - 1;
                while (k > j)
                {
                    if (a + b + nums[k] == 0)
                    {
                        res.push_back({a, b, c});
                    }
                    k--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
