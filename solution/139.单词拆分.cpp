// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem139.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int len = s.size();
        vector<bool> dp(len,false);
        dp[0]=true;
        int wc = wordDict.size();
        for(int i=0;i<len;i++){
            for(int j=0;j<wc;j++){
                
            }
        }
        return dfs(0, s, wordDict);
    }

    // s位置,
    bool dfs(int pos, string s, vector<string> &wordDict)
    {
        if (pos == s.size())
            return true;
        bool flag;
        for (auto &it : wordDict)
        {
            if (it == s.substr(pos, it.size()))
            {
                flag = dfs(pos + it.size(), s, wordDict);
                if (flag == true)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
