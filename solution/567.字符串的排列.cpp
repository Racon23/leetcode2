// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem567.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();
        if (n > m)
            return false;
        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);
        for (int i = 0; i < n; i++)
        {
            mp1[s1[i] - 'a']++;
            mp2[s2[i] - 'a']++;
        }
        if (mp1 == mp2)
        {
            return true;
        }
        for (int i = n; i < m; i++)
        {
            mp2[s2[i] - 'a']++;
            mp2[s2[i - n] - 'a']--;
            if (mp1 == mp2)
                return true;
        }
        return false;
    }
};
// @lc code=end
