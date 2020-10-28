// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1024.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */

// @lc code=start
class Solution
{
public:
    int videoStitching(vector<vector<int>> &clips, int T)
    {
        vector<int> dp(T + 1, INT_MAX-1);
        dp[0] = 0;
        int n = clips.size();
        for (int i = 1; i <= T; i++)
        {
            for(auto &it:clips){
                if(it[0]<i&&it[1]>=i){
                    dp[i]=min(dp[i],dp[it[0]]+1);
                }
            }
        }
        return dp[T]==INT_MAX-1?-1:dp[T];
    }
};
// @lc code=end
