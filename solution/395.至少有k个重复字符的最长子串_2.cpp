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
// 滑动窗口
class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int n = s.length();
        int ret = 0;
        for (int t = 1; t <= 26; t++)
        {
            int tot = 0;
            int less = 0;
            int l = 0, r = 0;
            vector<int> cnt(26, 0);
            while (r < n)
            {
                cnt[s[r] - 'a']++;
                if (cnt[s[r] - 'a'] == 1)
                {
                    tot++;
                    less++;
                }
                if (cnt[s[r] - 'a'] == k)
                {
                    less--;
                }
                while (tot > t)
                {
                    cnt[s[l] - 'a']--;
                    if (cnt[s[l] - 'a'] == 0)
                    {
                        less--;
                        tot--;
                    }
                    if (cnt[s[l] - 'a'] == k - 1)
                    {
                        less++;
                    }
                    l++;
                }
                if (less == 0)
                {
                    ret = max(ret, r - l + 1);
                }
                r++;
            }
        }
        return ret;
    }
};
// @lc code=end
