// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem1052.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X)
    {
        int n = customers.size();
        int left = 0, right = X;
        int maxn = 0, tmp = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < X || grumpy[i] == 0)
            {
                tmp += customers[i];
            }
        }
        maxn = tmp;
        while (right < n)
        {
            if (grumpy[left] == 1)
            {
                tmp -= customers[left];
            }
            if (grumpy[right] == 1)
            {
                tmp += customers[right];
            }
            left++;
            right++;
            maxn = max(maxn, tmp);
        }
        return maxn;
    }
};
// @lc code=end
