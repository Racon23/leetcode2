// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include "commoncppproblem514.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=514 lang=cpp
 *
 * [514] 自由之路
 */

// @lc code=start
// 动态规划 二维
class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        int n = ring.size();
        int m = key.size();
        int ret = 0;
        unordered_map<char, vector<int>> ringmap;
        // 制作字典
        for (int i = 0; i < n; i++)
        {
            ringmap[ring[i]].push_back(i);
        }

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        for (auto &i : ringmap[key[0]])
        {
            dp[0][i] = min(i, n - i) + 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (auto &j : ringmap[key[i]])
            {
                for (auto &k : ringmap[key[i - 1]])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
                }
            }
        }

        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};
// @lc code=end
