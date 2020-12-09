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
// 数组倒推
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if(m==1||n==1) return 1;
        vector<vector<int>> rem(m, vector<int>(n, 0));
        // 最后一行和最后一列置为1
        for (int i = 0; i < m; i++)
        {
            rem[i][n - 1] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            rem[m - 1][j] = 1;
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                rem[i][j]= rem[i+1][j]+rem[i][j+1];
            }
        }
        return rem[0][0];
    }


};
// @lc code=end
