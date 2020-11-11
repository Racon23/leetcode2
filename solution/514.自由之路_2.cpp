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
// 动态规划 一维
class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        int n = ring.size();
        int m = key.size();
        unordered_map<char, vector<int>> ringmap;
        // 制作字典
        for (int i = 0; i < n; i++)
        {
            ringmap[ring[i]].push_back(i);
        }

        vector<int> dp(n, INT_MAX);

        for (auto &i : ringmap[key[0]])
        {
            dp[i] = min(i, n - i) + 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (auto &j : ringmap[key[i]])
            {
                if (key[i] == key[i - 1])
                {
                    dp[j]++;
                }
                else
                {
                    dp[j] = INT_MAX;
                    for (auto &k : ringmap[key[i - 1]])
                    {
                        dp[j] = min(dp[j], dp[k] + min(abs(j - k), n - abs(j - k)) + 1);
                    }
                }
            }
        }

        int min1 = INT_MAX;
        for (auto &i : ringmap[key[m - 1]])
        {
            min1 = min(min1, dp[i]);
        }
        return min1;
    }
};
// @lc code=end
