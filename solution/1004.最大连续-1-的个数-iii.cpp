// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem1004.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution
{
public:
    int longestOnes(vector<int> &A, int K)
    {
        int n = A.size();
        int left = 0, right = 0;
        int maxn = 0;
        while (right < n)
        {
            if (A[right] == 0)
            {
                if (K == 0)
                {
                    break;
                }
                K--;
            }
            right++;
        }
        maxn = right - left;

        while (right < n)
        {
            if (A[right] == 0)
            {
                maxn = max(maxn, right - left);
                while (A[left] == 1)
                {
                    left++;
                }
                left++;
            }
            right++;
        }
        maxn = max(maxn,right-left);
        return maxn;
    }
};
// @lc code=end
