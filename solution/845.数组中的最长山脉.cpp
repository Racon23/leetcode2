// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem845.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 */

// @lc code=start
class Solution
{
public:
    int longestMountain(vector<int> &A)
    {
        int n = A.size();
        int l = 0, r = 0, t = 0, maxn = 0;
        // if (A[1] > A[0])
        //     t = 1;
        for (int i = 2; i < n; i++)
        {
            if (A[i] > A[i - 1])
            {
                if (A[i - 1] <= A[i - 2])
                {
                    if (l < t && t < r)
                    {
                        maxn = max(maxn, r - l + 1);
                    }
                    l = i - 1;
                }
            }
            else if (A[i] < A[i - 1])
            {
                r = i;
                if (A[i - 1] > A[i - 2])
                {
                    t = i - 1;
                }
            }
            else
            {
                if (l < t && t < r)
                {
                    maxn = max(maxn, r - l + 1);
                }
                l = i;
            }
        }
        if (l < t && t < r)
        {
            maxn = max(maxn, r - l + 1);
        }
        return maxn;
    }
};
// @lc code=end
