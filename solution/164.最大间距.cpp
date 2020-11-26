// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem164.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;

        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1;i<n;i++){
            ans = max(ans, nums[i]-nums[i-1]);
        }
        return ans;
    }
};
// @lc code=end
