// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem213.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
// 空间优化
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 3)
            return *max_element(nums.begin(), nums.end());
        
        int t1,t2,s1,s2;
        t2 = max(nums[1],nums[0]+nums[2]);
        t1 = max(nums[0],nums[1]);
        s2 = max(nums[1],nums[2]);
        s1 = nums[1];
        for (int i = 3; i < n; i++)
        {
            t1 = max(t2,t1+nums[i]);
            s1 = max(s2,s1+nums[i]);
            swap(t1,t2);
            swap(s1,s2);
        }

        return max(t1, s2);
    }
};
// @lc code=end
