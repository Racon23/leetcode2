#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */

// @lc code=start
class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int left = 0, right = 0;
        int len = s.length();
        int maxn = 0;
        while (right < len)
        {
            if (maxCost < 0)
            {
                int lcost = abs(s[left] - t[left]);
                left++;
                maxCost += lcost;
            }
            else
            {
                int cost = abs(s[right] - t[right]);
                right++;
                maxCost -= cost;
                if (maxCost >= 0)
                {
                    maxn = max(maxn, right - left);
                }
            }
        }
        return maxn;
    }
};
// @lc code=end
