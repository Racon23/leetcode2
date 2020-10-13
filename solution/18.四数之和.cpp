// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem18.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (39.20%)
 * Likes:    652
 * Dislikes: 0
 * Total Accepted:    129.6K
 * Total Submissions: 330.6K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int len = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int l, sum;
        for (int i = 0; i <= len - 4; i++)
        {
            for (int j = i + 1; j <= len - 3; j++)
            {
                l = len - 1;
                for (int k = j + 1; k <= len - 2; k++)
                {
                    while (k < l)
                    {
                        sum = nums[i] + nums[j] + nums[k] + nums[l];
                        if (sum < target)
                        {
                            break;
                        }
                        else if (sum == target)
                        {
                            res.push_back({nums[i], nums[j], nums[k], nums[l]});
                            l--;
                            break;
                        }
                        else
                        {
                            l--;
                        }
                    }
                    while (k <= len - 2 && nums[k] == nums[k + 1])
                    {
                        k++;
                    }
                }

                while (j <= len - 3 && nums[j] == nums[j + 1])
                {
                    j++;
                }
            }

            while (i <= len - 4 && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
        return res;
    }
};
// @lc code=end
