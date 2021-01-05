// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem830.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        int len = s.length();
        vector<vector<int>> ans;
        int count = 1;
        for (int i = 0; i < len; i++)
        {
            if (i == len - 1 || s[i] != s[i + 1])
            {
                if (count >= 3)
                {
                    ans.push_back({i - count + 1, i});
                }
                count = 1;
            }
            else
            {
                count++;
            }
        }
        return ans;
    }
};
// @lc code=end
