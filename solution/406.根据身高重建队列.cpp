// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem406.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](const vector<int> &u, const vector<int> &v) {
            return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
        });
        vector<vector<int>> ret;
        for (auto &it : people)
        {
            ret.insert(ret.begin() + it[1], it);
        }
        return ret;
    }
};
// @lc code=end
