// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem995.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=995 lang=cpp
 *
 * [995] K 连续位的最小翻转次数
 */

// @lc code=start
// 空间优化
class Solution
{
public:
    int minKBitFlips(vector<int> &A, int K)
    {
        int n = A.size();
        int ans = 0, count = 0;

        for (int i = 0; i < n; i++)
        {
            if (i >= K && A[i - K] > 1)
            {
                count ^= 1;
                A[i - K] += 2;
            }
            if (A[i] == count)
            {
                if (i + K > n)
                {
                    return -1;
                }
                count ^= 1;
                ans++;
                A[i] += 2;
            }
        }
        return ans;
    }
};
// @lc code=end
