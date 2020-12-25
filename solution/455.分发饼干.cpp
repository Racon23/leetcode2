// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem455.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int gl = g.size();
        int sl = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, ans = 0;
        while (i < gl && j < sl)
        {
            if (g[i] <= s[j])
            {
                ans++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};
// @lc code=end
