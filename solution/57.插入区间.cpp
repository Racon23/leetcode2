// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem57.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        int n = intervals.size();
        vector<vector<int>> res;
        if (n == 0)
        {
            res.emplace_back(newInterval);
            return res;
        }
        int i = 0;
        int flag = 0; 
        // 0 开始 1 去掉了头部 2 跳过中间 3 去掉尾部
        int left, right;
        // 先装入头部，并获取区间左端点
        while (i < n && flag == 0)
        {
            if (intervals[i][1] < newInterval[0])
            {
                res.emplace_back(intervals[i]);
                i++;
            }
            else
            {
                break;
            }
        }
        
        // 末尾了
        if(i==n) {
            res.emplace_back(newInterval);
            return res;
        }

        if (intervals[i][0] > newInterval[1])
        {
            res.emplace_back(newInterval);
            flag = 3;
        }
        else
        {
            left = min(newInterval[0], intervals[i][0]);
            flag = 1;
        }

        // 跳过在新区间中间的
        while (i < n && flag == 1)
        {
            if (intervals[i][0] > newInterval[1])
            {
                flag = 2;
                break;
            }
            i++;
        }
        
        // 末尾了
        if(flag==1&&i==n){
            flag = 2;
        }

        // 获取区间右端点，并装入新区间
        if (flag == 2)
        {
            right = max(intervals[i - 1][1], newInterval[1]);
            res.push_back({left, right});
            flag = 3;
        }

        // 装入尾部
        while (i < n && flag == 3)
        {
            res.emplace_back(intervals[i]);
            i++;
        }
        return res;
    }
};
// @lc code=end
