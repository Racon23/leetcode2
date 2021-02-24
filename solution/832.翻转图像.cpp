// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem832.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j<=(n-1)/2){
                    swap(A[i][j],A[i][n-j-1]);
                }
                A[i][j]=A[i][j]==0?1:0;
            }
        }
        return A;
    }
};
// @lc code=end

