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
// 牺牲空间
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<unordered_map<int, int>> rows(9, unordered_map<int, int>());
        vector<unordered_map<int, int>> cols(9, unordered_map<int, int>());
        vector<unordered_map<int, int>> cells(9, unordered_map<int, int>());

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if(board[i][j]!='.'){
                    int n = board[i][j];
                    int box_index = i/3*3 + j/3;

                    rows[i][n]++;
                    cols[j][n]++;
                    cells[box_index][n]++;
                    if(rows[i][n]>1||cols[j][n]>1||cells[box_index][n]>1){
                        return false;
                    }
                }
                
            }
        }
        return true;
    }
};
// @lc code=end
