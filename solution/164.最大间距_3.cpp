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
// 桶排序
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;

        int maxnum = nums[0], minnum = nums[0];
        for (int i = 1; i < n; i++)
        {
            maxnum = max(nums[i], maxnum);
            minnum = min(nums[i], minnum);
        }

        int dis = max(1, (maxnum - minnum) / (n - 1)); //桶宽
        int bucketsize = (maxnum - minnum) / dis + 1;  //桶数，加一时因为要把头占一个桶，尾占一个

        vector<pair<int, int>> bucket(bucketsize, {-1, -1});
        for (int i = 0; i < n; i++)
        {
            int t = (nums[i] - minnum) / dis;
            if (bucket[t].first == -1)
            {
                bucket[t].first = bucket[t].second = nums[i];
            }
            else
            {
                bucket[t].first = min(bucket[t].first, nums[i]);
                bucket[t].second = max(bucket[t].second, nums[i]);
            }
        }

        int ans = 0;
        int prev = -1;
        for (int i = 0; i < bucketsize; i++)
        {
            if (bucket[i].first == -1)
                continue;
            if (prev != -1)
            {
                ans = max(ans, bucket[i].first - bucket[prev].second);
            }
            prev = i;
        }

        return ans;
    }
};
// @lc code=end
