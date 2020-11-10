// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem327.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

// @lc code=start
// 归并排序
class Solution
{
public:
    int countRangeSumRecursive(vector<long> &sums, int left, int right, int lower, int upper)
    {

        if (left == right)
            return 0;
        int ret = 0;
        int mid = (left + right) / 2;
        // 区间在左侧时的个数
        ret += countRangeSumRecursive(sums, left, mid, lower, upper);
        // 区间在右侧时的个数
        ret += countRangeSumRecursive(sums, mid + 1, right, lower, upper);

        // 区间跨越两边的个数
        int i = left;
        int l = mid + 1, r = mid + 1;
        // 由于递增，所以i增加时，l和r只会增加
        while (i <= mid)
        {
            while (l <= right && sums[l] - sums[i] < lower)
                l++;
            while (r <= right && sums[r] - sums[i] <= upper)
                r++;
            ret += r - l;
            i++;
        }

        // 合并两数组
        vector<long> sorted(right - left + 1);
        int p1 = left, p2 = mid + 1;
        int p = 0;
        while (p1 <= mid || p2 <= right)
        {
            if (p1 > mid)
            {
                sorted[p++] = sums[p2++];
            }
            else if (p2 > right)
            {
                sorted[p++] = sums[p1++];
            }
            else
            {
                if (sums[p1] < sums[p2])
                {
                    sorted[p++] = sums[p1++];
                }
                else
                {
                    sorted[p++] = sums[p2++];
                }
            }
        }

        for (int j = 0; j < sorted.size(); j++)
        {
            sums[left + j] = sorted[j];
        }

        return ret;
    }

    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        int ret = 0;
        vector<long> sums;
        // 存在只选一个的情况，所以要加0
        sums.emplace_back(0);
        long sum = 0;
        for (auto &it : nums)
        {
            sum += it;
            sums.emplace_back(sum);
        }

        return countRangeSumRecursive(sums, 0, sums.size() - 1, lower, upper);
    }
};
// @lc code=end
