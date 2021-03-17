// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem115.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        if (n == 0)
        {
            return 1;
        }
        if (m == 0)
        {
            return 0;
        }
        vector<vector<long>> dp(n, vector<long>(m, 0));
        for (int j = 0; j < m; j++)
        {
            if (s[j] == t[0])
            {
                dp[0][j] = j > 0 ? dp[0][j - 1] + 1 : 1;
            }
            else
            {
                dp[0][j] = j > 0 ? dp[0][j - 1] : 0;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = i; j < m; j++)
            {
                if (s[j] == t[i])
                {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return (int)dp[n - 1][m - 1];
    }
};
// @lc code=end
