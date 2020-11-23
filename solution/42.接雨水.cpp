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
// 动态编程
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if(n<=2) return 0;
        vector<int> max_left(n);
        vector<int> max_right(n);
        int ans = 0;
        // 注意边界
        max_left[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            max_left[i] = max(max_left[i-1],height[i]);
        }
        max_right[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--)
        {
            max_right[i] = max(max_right[i+1],height[i]);
        }

        for(int i=1;i<n-1;i++){
            ans += min(max_left[i],max_right[i]) - height[i];
        }
        return ans;
    }
};
// @lc code=end
