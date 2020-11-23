// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include "commoncppproblem42.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
// 双指针
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n <= 2)
            return 0;
        int ans = 0;
        int l = 0, r = n-1, lmax = 0, rmax = 0;
        while (l < r)
        {
            if (height[l] < height[r])
            {
                height[l] >= lmax ? (lmax = height[l]) : ans += lmax - height[l];
                l++;
            }
            else
            {
                height[r] >= rmax ? (rmax = height[r]) : ans += rmax - height[r];
                r--;
            }
        }

        return ans;
    }
};
// @lc code=end
