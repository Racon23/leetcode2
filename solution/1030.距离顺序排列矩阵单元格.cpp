// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem1030.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
    {
        vector<int> dr = {1, 1, -1, -1};
        vector<int> dc = {1, -1, -1, 1};
        vector<vector<int>> ret;
        // 最大距离
        int maxDict = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
        int row = r0, col = c0;
        ret.push_back({row, col});

        for (int dist = 1; dist <= maxDict; dist++)
        {
            row--;
            for (int i = 0; i < 4; i++)
            {
                while ((i % 2 == 0 && row != r0) || (i % 2 != 0 && col != c0))
                {
                    if(row>=0&&row<R&& col>=0&&col<C){
                        ret.push_back({row,col});
                    }
                    row += dr[i];
                    col += dc[i];
                }
            }
        }

        return ret;
    }
};
// @lc code=end
