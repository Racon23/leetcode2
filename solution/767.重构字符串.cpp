// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem767.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */

// @lc code=start
class Solution
{
public:
    string reorganizeString(string S)
    {
        int n = S.size();
        if(n==2) return S;
        vector<pair<int, int>> letters(26); // first 字母 second 数量

        for (int i = 0; i < 26; i++)
        {
            letters[i].first = i;
            letters[i].second = 0;
        }

        for (auto &it : S)
        {
            letters[it - 'a'].second++;
        }

        sort(letters.begin(), letters.end(), [](const pair<int, int> &u, const pair<int, int> &v) {
            return u.second > v.second;
        });

        char cs[n+1];
        cs[n] = '\0';
        if (letters[0].second * 2 - 1 > n)
            return "";
        int partlen = (n - 1) / letters[0].second + 1; // 间隙宽度
        int parts = letters[0].second;                 // 总共由几个间隙

        int proc = 0; // 记录进度，间隙中的第几个 ,每次+1
        int pos = 0;  // 记录当前要插入的位置，每次+partlen
        int count = 0;

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < letters[i].second; j++)
            {
                cs[pos] = letters[i].first + 'a';
                count++;
                if (pos + partlen < n)
                {
                    pos += partlen;
                }
                else
                {
                    proc++;
                    pos = proc;
                }
            }
        }
        if (count == n)
        {
            string ret = cs;
            return ret;
        }
        else
        {
            return "";
        }
    }
};
// @lc code=end
