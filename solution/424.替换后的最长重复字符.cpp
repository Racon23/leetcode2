// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem424.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> num(26, 0);
        int n = s.length();
        int left = 0, right = 0;
        int maxn = 0;
        while (right < n)
        {
            num[s[right] - 'A']++;
            maxn = max(maxn, num[s[right] - 'A']);
            if (right - left + 1 - maxn > k)
            {
                num[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};
// @lc code=end
