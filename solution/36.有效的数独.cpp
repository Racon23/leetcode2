// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem36.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, int> m1;

        // 检验行
        for (int i = 0; i < 9; i++)
        {
            m1.clear();
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] >= '1' && board[i][j] <= '9' && ++m1[board[i][j]] != 1)
                {
                    return false;
                }
            }
        }
        // 检验列
        for (int j = 0; j < 9; j++)
        {
            m1.clear();
            for (int i = 0; i < 9; i++)
            {
                if (board[i][j] >= '1' && board[i][j] <= '9' && ++m1[board[i][j]] != 1)
                    return false;
            }
        }

        // 检验9格
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                m1.clear();
                // 小9格
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        if (board[i * 3 + k][j * 3 + l] >= '1' && board[i * 3 + k][j * 3 + l] <= '9' && ++m1[board[i * 3 + k][j * 3 + l]] != 1)
                            return false;
                    }
                }
            }
        }

        return true;
    }
};
// @lc code=end
