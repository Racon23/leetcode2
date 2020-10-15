// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem16.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        int k;
        int sum;
        int last=INT_MAX;
        for (int i = 0; i <= n - 3; i++)
        {
            k = n - 1;
            for (int j = 1; j <= n - 2; j++)
            {
                while (j < k)
                {
                    sum = nums[i] + nums[j] + nums[k];
                    if (sum == target)
                    {
                        return sum;
                    }
                    else if (sum > target)
                    {
                        last = abs(sum - target) < abs(last - target) ? sum : last;
                        k--;
                    }
                    else
                    {
                        last = abs(sum - target) < abs(last - target) ? sum : last;
                        break;
                    }
                }
                while (j < k && nums[j] == nums[i + j])
                {
                    j++;
                }
            }
            while (i <= n - 3 && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
        return last;
    }
};
// @lc code=end
