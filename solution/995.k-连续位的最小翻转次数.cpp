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
class Solution
{
public:
    int minKBitFlips(vector<int> &A, int K)
    {
        int size = A.size();
        int ans = 0, count = 0;
        vector<int> diff(size + 1, 0);
        for (int i = 0; i < size; i++)
        {
            count += diff[i];
            if ((A[i] + count) % 2 == 0)
            {
                if (i + K > size)
                {
                    return -1;
                }
                count++;
                ans++;
                diff[i + K]--;
            }
        }
        return ans;
    }
};
// @lc code=end
