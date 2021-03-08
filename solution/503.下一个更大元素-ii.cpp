// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem503.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return vector<int>();
        }
        vector<int> ans(n, -1);
        vector<int> tmp(n, -1);
        int maxn = nums[0];
        int maxi = 0;
        for (int i = 1; i < n; i++)
        {
            if (maxn < nums[i])
            {
                maxn = nums[i];
                maxi = i;
            }
        }
        int j = maxi;
        int i = (maxi + n - 1) % n;
        while (i != maxi)
        {
            while (nums[i] >= nums[j])
            {
                j = tmp[j];
                if (j == -1)
                {
                    break;
                }
            }
            tmp[i] = j;

            j = i;
            i = (i + n - 1) % n;
        }

        for (int k = 0; k < n; k++)
        {
            if (tmp[k] != -1)
            {
                ans[k] = nums[tmp[k]];
            }
        }
        return ans;
    }
};
// @lc code=end
