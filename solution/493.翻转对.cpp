// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem493.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
// 归并排序
class Solution
{
public:
    int reversePairsMerge(vector<int> &nums, int low, int high)
    {
        if (low == high)
            return 0;
        else
        {

            int mid = (low + high) / 2;
            int n1 = reversePairsMerge(nums, low, mid);
            int n2 = reversePairsMerge(nums, mid + 1, high);
            int ret = n1 + n2;

            int i = low;
            int j = mid + 1;
            while (i <= mid)
            {
                // j = mid + 1;
                while (j <= high && (long)nums[i] > 2 * (long)nums[j])
                    j++;
                ret += j - mid - 1;
                i++;
            }

            vector<int> sorted(high - low + 1);
            int p1 = low;
            int p2 = mid + 1;
            int p = 0;
            while (p1 <= mid || p2 <= high)
            {
                if (p1 > mid)
                {
                    sorted[p++] = nums[p2++];
                }
                else if (p2 > high)
                {
                    sorted[p++] = nums[p1++];
                }
                else
                {
                    if (nums[p1] < nums[p2])
                    {
                        sorted[p++] = nums[p1++];
                    }
                    else
                    {
                        sorted[p++] = nums[p2++];
                    }
                }
            }

            // 复制过去
            for (int i = 0; i < sorted.size(); i++)
            {
                nums[i + low] = sorted[i];
            }

            return ret;
        }
    }

    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;
        int ret = reversePairsMerge(nums, 0, n - 1);
        return ret;
    }
};
// @lc code=end
