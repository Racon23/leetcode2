// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include "commoncppproblem205.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        if (m != n)
            return false;
        unordered_map<int, int> mpst;
        unordered_map<int, int> mpts;
        for (int i = 0; i < n; i++)
        {
            if (mpst.find(s[i]) == mpst.end() && mpts.find(t[i]) == mpts.end())
            {
                mpst[s[i]] = t[i];
                mpts[t[i]] = s[i];
            }else{
                if(mpst.find(s[i]) != mpst.end() && mpts.find(t[i]) != mpts.end()&&mpst[s[i]] == t[i] && mpts[t[i]] == s[i]){
                    continue;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
