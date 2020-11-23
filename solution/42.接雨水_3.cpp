// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem42.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
// 暴力 超时
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int max_left = 0;
        int max_right = 0;
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            max_left = 0;
            max_right = 0;
            for (int j = i; j >= 0; j--)
            {
                max_left = max(max_left, height[j]);
            }
            for (int j = i; j < n; j++)
            {
                max_right = max(max_right, height[j]);
            }
            ans += min(max_left,max_right) - height[i];
        }
        return ans;
    }
};
// @lc code=end
