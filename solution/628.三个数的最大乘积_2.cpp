// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem628.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int n = nums.size();
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i]>max2)
            {
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i]>max3)
            {
                max3 = nums[i];
            }

            if (nums[i] < min1)
            {
                min2 = min1;
                min1 = nums[i];
            }else if(nums[i]<min2){
                min2 = nums[i];
            }
        }
        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};

// @lc code=end
