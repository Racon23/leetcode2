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
// 未记忆
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
        dfs(s, 0, wdset, "", res, maxn, n);
        return res;
    }

    void dfs(string &s, int st, unordered_set<string> &wdset, string str, vector<string> &res, int maxn, int n)
    {
        if (st == s.size())
        {
            // 去掉空格
            res.emplace_back(str.substr(0, str.size() - 1));
            return;
        }

        for (int i = 1; i <= maxn && st + i <= n; i++)
        {
            string tmp = s.substr(st, i);
            if (wdset.find(tmp) != wdset.end())
            {
                string rem = str;
                str += tmp + " ";
                dfs(s, st + i, wdset, str, res, maxn, n);
                str = rem;
            }
        }
        return;
    }
};
// @lc code=end
