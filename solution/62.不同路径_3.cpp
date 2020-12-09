// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem62.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
// 组合
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        long long ans = 1;
        // n个连续自然数能被n! 整除，可以直接这样写
        for(int x = n,y=1;y<m;x++,y++){
            ans = ans * x / y;
        }
        return ans;
    }


};
// @lc code=end
