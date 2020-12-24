// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem135.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
// 空间优化
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int size = ratings.size();
        if (size <= 1)
            return size;
        int ans = 1;
        int pre = 1, dec = 0, inc = 1;
        for (int i = 1; i < size; i++)
        {
            if (ratings[i] >= ratings[i - 1])
            {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ans += pre;
                inc = pre;
            }
            else
            {
                dec++;
                if (dec == inc)
                {
                    dec++;
                }
                ans += dec;
                pre = 1;
            }
        }
        return ans;
    }
};
// @lc code=end
