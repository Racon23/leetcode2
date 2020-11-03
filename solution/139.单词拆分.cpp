// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include "commoncppproblem139.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        int maxw = 0;
        vector<bool> dp(n + 1, false);
        unordered_set<string> wdset;
        // for (auto &it : wordDict)
        for (int i = 0; i < wordDict.size(); i++)
        {
            maxw = maxw > wordDict[i].size() ? maxw : wordDict[i].size();
            // if (maxw < wordDict[i].length())
            // {
            //     maxw = wordDict[i].length();
            // }
            // maxw = max(maxw,wordDict[i].size());
            wdset.emplace(wordDict[i]);
        }
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 0 && j >= i - maxw; j--)
            {
                if (dp[j] && wdset.find(s.substr(j, i - j)) != wdset.end())
                {
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end
