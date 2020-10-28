// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem1024.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */

// @lc code=start
// 贪心
class Solution
{
public:
    int videoStitching(vector<vector<int>> &clips, int T)
    {
        vector<int> maxn(T);
        int n = clips.size();
        int last = 0, prev = 0, res = 0;
        for (vector<int> &it : clips)
        {
            if (it[0] < T)
            {
                maxn[it[0]] = max(maxn[it[0]], it[1]);
            }
        }
        for (int i = 0; i < T; i++)
        {
            last = max(last, maxn[i]);
            if (i == last)
            {
                return -1;
            }
            if (i == prev)
            {
                res++;
                prev = last;
            }
        }
        return res;
    }
};

// @lc code=end
