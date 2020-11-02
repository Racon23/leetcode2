// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
#include "commoncppproblem349.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (72.94%)
 * Likes:    276
 * Dislikes: 0
 * Total Accepted:    130.9K
 * Total Submissions: 179.5K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        unordered_set<int> s1;
        unordered_set<int> s2;
        for (auto &it : nums1)
        {
            s1.emplace(it);
        }
        for (auto &it : nums2)
        {
            s2.emplace(it);
        }
        for (auto &it : s1)
        {
            if (s2.find(it) != s2.end())
            {
                res.emplace_back(it);
            }
        }

        return res;
    }
};
// @lc code=end
