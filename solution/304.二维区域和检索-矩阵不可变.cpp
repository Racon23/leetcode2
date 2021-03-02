// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem304.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix
{
public:
    vector<vector<int>> sums;
    int rows;
    int cols;

    NumMatrix(vector<vector<int>> &matrix)
    {
        rows = matrix.size();
        if (rows > 0)
        {
            cols = matrix[0].size();
            sums.resize(rows, vector<int>(cols + 1, 0));
            for (int i = 0; i < rows; i++)
            {
                for (int j = 1; j <= cols; j++)
                {
                    sums[i][j] = sums[i][j - 1] + matrix[i][j - 1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = 0;
        for (int i = row1; i <= row2; i++)
        {
            sum += sums[i][col2 + 1] - sums[i][col1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
