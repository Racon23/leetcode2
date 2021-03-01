// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem395.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
 */

// @lc code=start
// 分治
class Solution
{
public:
    int dfs(string s, int l, int r, int k)
    {
        vector<int> cnt(26, 0);
        for (int i = l; i <= r; i++)
        {
            cnt[s[i] - 'a']++;
        }
        char split = 0;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] > 0 && cnt[i] < k)
            {
                split = i + 'a';
                break;
            }
        }
        if (split == 0)
        {
            return r - l + 1;
        }

        int ret = 0;
        int i = l;
        while (i <= r)
        {
            // 找到切割头
            while (i <= r && s[i] == split)
            {
                i++;
            }
            if (i > r)
            {
                break;
            }
            int start = i;
            // 找到切割尾
            while (i <= r && s[i] != split)
            {
                i++;
            }
            int len = dfs(s, start, i - 1, k);
            ret = max(ret, len);
        }
        return ret;
    }

    int longestSubstring(string s, int k)
    {
        int n = s.length();
        return dfs(s, 0, n - 1, k);
    }
};
// @lc code=end
