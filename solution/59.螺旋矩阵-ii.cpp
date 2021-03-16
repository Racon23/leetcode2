// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem59.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n1 = n;
        int i = 0;
        int j = 0;
        int c = 1;
        while (n1 > (n + 1) / 2 && n > 1)
        {
            for (int d = 0; d < 4; d++)
            {
                while (!(d & 1) && j + dir[d][1] < n1 && j + dir[d][1] >= n - n1 || d & 1 && i + dir[d][0] < n1 && i + dir[d][0] >= n - n1)
                {
                    ret[i][j] = c;
                    c++;
                    i += dir[d][0];
                    j += dir[d][1];
                }
            }
            i++;
            j++;
            n1--;
        }
        if (n & 1)
        {
            ret[i][j]=c;
        }
        return ret;
    }
};
// @lc code=end
