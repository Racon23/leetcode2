/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        sort(points.begin(), points.end(), [](const vector<int> &u, const vector<int> &v) {
            return u[1] < v[1];
        });

        int pos = points[0][1];
        int ans = 1;
        for(int i = 1;i<n;i++){
            if(points[i][0]> pos){
                pos = points[i][1];
                ans ++;
            }
        }
        return ans;

    }
};
// @lc code=end
