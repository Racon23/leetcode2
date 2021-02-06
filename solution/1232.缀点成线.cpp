#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
 */

// @lc code=start
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int size = coordinates.size();
        int dy = coordinates[0][1] - coordinates[1][1];
        int dx = coordinates[0][0] - coordinates[1][0];
        double k = 0;
        if (dx != 0)
            k = dy * 1.0 / dx;
        for (int i = 2; i < size; i++)
        {
            int dy1 = coordinates[0][1] - coordinates[i][1];
            int dx1 = coordinates[0][0] - coordinates[i][0];
            if (dx == 0)
            {
                if (dx1 != 0)
                {
                    return false;
                }
            }
            else
            {
                double k1 = dy1 * 1.0 / dx1;
                if (k1 != k)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
