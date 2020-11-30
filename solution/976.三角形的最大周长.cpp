// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem976.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 */

// @lc code=start
class Solution
{
public:
    int largestPerimeter(vector<int> &A)
    {
        int n = A.size();
        if (n <= 2)
            return 0;
        sort(A.begin(), A.end());
        int i = n - 1;
        while (i >= 2)
        {
            if (A[i - 1] + A[i - 2] > A[i])
                return A[i]+A[i-1]+A[i-2];
            i--;
        }
        return 0;
    }
};
// @lc code=end
