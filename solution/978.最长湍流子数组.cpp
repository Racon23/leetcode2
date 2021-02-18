// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem978.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */

// @lc code=start
class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int n = arr.size();
        int flag = 0;
        int left = 0, right = 1;
        int maxn = 1;
        while (right < n)
        {
            if (arr[right] < arr[right - 1] && (flag == 0 || flag == 1))
            {
                flag = 2;
            }
            else if (arr[right] > arr[right - 1] && (flag == 0 || flag == 2))
            {
                flag = 1;
            }
            else
            {
                maxn = max(maxn, right - left);
                // flag = 0;
                if (arr[right] == arr[right - 1])
                {
                    left = right;
                }
                else
                {
                    left = right - 1;
                }
            }
            right++;
        }
        maxn = max(maxn,right-left);
        return maxn;
    }
};
// @lc code=end
