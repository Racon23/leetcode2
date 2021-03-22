// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem73.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m,1),col(n,1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        for(int i=0;i<m;i++){
            if(row[i]==0){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=0;j<n;j++){
            if(col[j]==0){
                for(int i=0;i<m;i++){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
// @lc code=end

