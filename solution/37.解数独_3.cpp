// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem37.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
// 位运算 枚举优化
class Solution
{
public:
    int row[9];
    int col[9];
    int box[3][3];
    vector<pair<int, int>> spaces; // 记录空格位
    bool valid;

    void flip(int i, int j, int digit)
    {
        row[i] ^= (1 << digit);
        col[j] ^= (1 << digit);
        box[i / 3][j / 3] ^= (1 << digit);
    }

    void dfs(vector<vector<char>> &board, int pos)
    {
        if (pos == spaces.size())
        {
            valid = true;
            return;
        }
        auto [i, j] = spaces[pos];
        int mask = ~(row[i] | col[j] | box[i / 3][j / 3]) & 0x1FF;
        for (; mask && !valid; mask &= (mask - 1))
        {
            int digitMask = mask & (-mask);
            int digit = __builtin_ctz(digitMask); //返回末尾0的个数
            flip(i, j, digit);
            board[i][j] = digit + '0' + 1;
            dfs(board, pos + 1);
            // 为什么要恢复，mask已经负责迭代了，辅助数组没有这个作用，而且不恢复会影响下一次递归
            flip(i, j, digit);
        }
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));
        valid = false;

        // 先填充三个辅助数组
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int digit = board[i][j] - '0' - 1;
                    flip(i, j, digit);
                }
            }
        }

        // 剪枝，剪掉唯一确定的
        while (true)
        {
            int modified = false;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (board[i][j] == '.')
                    {
                        int mask = ~(row[i] | col[j] | box[i / 3][j / 3]) & 0x1ff;
                        // 如果mask只剩一个1
                        if (!mask & (mask - 1))
                        {
                            int digit = __builtin_ctz(mask);
                            flip(i, j, digit);
                            board[i][j] = digit + '0' + 1;
                            modified = true;
                        }
                    }
                }
            }
            if (!modified)
            {
                break;
            }
        }

        // spaces 会有变化，最后再添加
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    spaces.emplace_back(i, j);
                }
            }
        }
        
        dfs(board, 0);
    }
};
// @lc code=end
