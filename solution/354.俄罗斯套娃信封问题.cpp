// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem354.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        if (n == 0)
        {
            return 0;
        }
        // 按宽度递增，但是同宽度按长度递减
        sort(envelopes.begin(), envelopes.end(), [](auto &u, auto &v) {
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
        });
        vector<int> dp(n, 1);
        int maxn = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (envelopes[i][1] > envelopes[j][1])
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            maxn = max(maxn, dp[i]);
        }
        return maxn;

        // return 0;
    }
};
// @lc code=end
