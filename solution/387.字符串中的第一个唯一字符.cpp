// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem387.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int len = s.length();
        vector<int> num(26, 0);
        for (char &ch : s)
        {
            num[ch - 'a']++;
        }
        for (int i = 0; i < len; i++)
        {
            if (num[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end
