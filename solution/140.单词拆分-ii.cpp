// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include "commoncppproblem140.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
// 加上记忆
class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        unordered_set<string> wdset;
        int maxn = 0;
        for (auto &it : wordDict)
        {
            wdset.emplace(it);
            maxn = maxn > it.size() ? maxn : it.size();
        }
        vector<string> res;
        vector<vector<string>> rem(n + 1); // 记录i之后的单词的组合
        vector<int> flags(n + 1, 0);       // 0 false 1 true 2 non-check
        dfs(s, 0, wdset, "", res, maxn, n, rem, flags);
        return rem[0];
    }

    void dfs(string &s, int st, unordered_set<string> &wdset, string str, vector<string> &res, int maxn, int n, vector<vector<string>> &rem, vector<int> &flags)
    {
        flags[st] = 1;
        if (st == s.size())
        {
            // 去掉空格
            // res.emplace_back(str.substr(0, str.size() - 1));
            return;
        }

        for (int i = 1; i <= maxn && st + i <= n; i++)
        {
            string tmp = s.substr(st, i);
            if (wdset.find(tmp) != wdset.end())
            {
                // string rem = str;
                // str += tmp + " ";
                if (flags[st + i] == 0)
                {
                    dfs(s, st + i, wdset, str, res, maxn, n, rem, flags);
                }
                if (st + i == s.size())
                {
                    rem[st].emplace_back(tmp);
                }
                else
                {
                    // 已经遍历过
                    for (auto &it : rem[st + i])
                    {
                        // rem[st].emplace_back(tmp + " " + it);
                        rem[st].emplace_back(tmp + " " + it);
                    }
                }
            }
        }
        return;
    }
};
// @lc code=end
