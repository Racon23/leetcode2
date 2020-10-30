// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem30.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        int m = s.size();
        if (m == 0)
            return res;
        int wc = words.size();
        if (wc == 0)
            return res;
        int wl = words[0].size();
        int tl = wc * wl;
        if (tl == 0)
        {
            for (int i = 0; i <= m; i++)
                res.emplace_back(i);
            return res;
        }
        unordered_map<string, int> hm1;
        unordered_map<string, int> hm2;
        int flag = 0;
        for (auto &it : words)
        {
            hm1[it]++;
        }
        for (int k = 0; k < wl; k++)
        {
            hm2.clear();
            for (int j = 0; j < wc - 1; j++)
            {
                hm2[s.substr(k + j * wl, wl)]++;
            }
            for (int i = 0; i <= m - tl; i += wl)
            {
                flag = 0;
                hm2[s.substr(i + k + (wc - 1) * wl, wl)]++;
                for (const auto &it : hm1)
                {
                    if (it.second != hm2[it.first])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    res.emplace_back(i);
                }
                hm2[s.substr(i + k , wl)]--;
            }
        }
        return res;
    }
};
// @lc code=end
