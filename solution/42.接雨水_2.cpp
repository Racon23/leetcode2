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
// 暴力模拟 超时
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if(n<=2) return 0;
        int mh = *max_element(height.begin(), height.end());
        int last = 0;
        int ans = 0;
        for (int i = 1; i <= mh; i++)
        {
            last = -1;
            for (int j = 0; j < n; j++)
            {
                if (height[j] >= i)
                {
                    if (last != -1)
                    {
                        ans += j - last - 1;
                    }
                    last = j;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
