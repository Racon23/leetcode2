// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem131.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution
{
    vector<vector<int>> rem;
    vector<vector<string>> ret;
    vector<string> tmp;
    int len;

public:
    int isPalindrome(string &s, int i, int j)
    {
        if (rem[i][j])
            return rem[i][j];
        if (i >= j)
            return rem[i][j] = 1;
        return rem[i][j] = (s[i] == s[j] ? isPalindrome(s, i + 1, j - 1) : -1);
    }

    void dfs(string &s, int i)
    {
        if (i == len)
        {
            ret.emplace_back(tmp);
            return;
        }
        for (int k = i; k < len; k++)
        {
            if (isPalindrome(s, i, k) == 1)
            {
                tmp.push_back(s.substr(i, k - i + 1));
                dfs(s, k + 1);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        len = s.length();
        rem.resize(len, vector<int>(len, 0));
        dfs(s, 0);
        return ret;
    }
};
// @lc code=end
