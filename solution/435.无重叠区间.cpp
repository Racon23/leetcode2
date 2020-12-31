// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem435.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int size = intervals.size();
        if (size <= 1)
            return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> &u, vector<int> &v) {
            return u[1] < v[1] || u[1] == v[1] && u[0] < v[0];
        });
        int ans = 0;
        int last = intervals[0][1];
        for (int i = 1; i < size; i++)
        {
            if (intervals[i][0] < last)
            {
                ans++;
            }else{
                last = intervals[i][1];
            }
        }
        return ans;
    }
};
// @lc code=end
