// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem11.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int temp = 0;
        int ma = 0;
        while (i < j)
        {
            temp = (j - i) * min(height[i], height[j]);
            ma = max(ma, temp);
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return ma;
    }
};
// @lc code=end
