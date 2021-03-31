// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem74.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto row = upper_bound(matrix.begin(),matrix.end(),target,[](const int b, const vector<int> &a){
            return b<a[0];
        });
        if(row==matrix.begin()){
            return false;
        }
        --row;
        return binary_search(row->begin(),row->end(),target);
    }
};
// @lc code=end

