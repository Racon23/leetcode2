// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem52.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 *
 * https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (80.07%)
 * Likes:    201
 * Dislikes: 0
 * Total Accepted:    48.6K
 * Total Submissions: 59.2K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: 2
 * 解释: 4 皇后问题存在如下两个不同的解法。
 * [
 * [".Q..",  // 解法 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // 解法 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一或
 * N-1 步，可进可退。（引用自 百度百科 - 皇后 ）
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int totalNQueens(int n)
    {
        return solve(n,0,0,0,0);
    }

    int solve(int n, int row, int columns, int diagonals1, int diagonals2)
    {
        if (n == row)
        {
            return 1;
        }
        int availablePosition = (1 << n) - 1 & ~(columns | diagonals1 | diagonals2);
        int count = 0;
        // 循环的是行位置
        while (availablePosition != 0)
        {
            // 获取最后一个1，负数是补码，反码加1，01100  10011+1 10100
            int position = availablePosition & (-availablePosition);
            // 去掉最后一个1
            availablePosition = availablePosition & (availablePosition - 1);
            // 递归皇后个数
            count += solve(n, row + 1, columns | position, (diagonals1 | position) >> 1, (diagonals2 | position) << 1);
        }
        return count;
    }
};
// @lc code=end
