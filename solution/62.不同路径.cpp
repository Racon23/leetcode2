// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem62.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
// 回溯 超时
class Solution {
public:
    int uniquePaths(int m, int n) {
        return backtrace(0,0,m,n);
    }

    int backtrace(int i,int j,int m,int n){
        if(i==m-1&&j==n-1){
            return 1;
        }
        int ans = 0;
        if(i+1<m){
            ans += backtrace(i+1,j,m,n);
        }
        if(j+1<n){
            ans+= backtrace(i,j+1,m,n);
        }
        return ans;
    }
};
// @lc code=end

