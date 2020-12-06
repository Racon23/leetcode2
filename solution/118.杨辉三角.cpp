// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem118.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> st;
        for(int i=0;i<numRows;i++){
            st = genTri(st);
            ans.push_back(st);
        }
        return ans;
    }

    vector<int> genTri(vector<int> &prev){
        int len = prev.size()+1;
        vector<int> ret(len);
        ret[0] = 1;
        ret[len-1] = 1;
        for(int i=1;i<len-1;i++){
            ret[i] = prev[i-1]+prev[i];
        }
        return ret;
    }
};
// @lc code=end

