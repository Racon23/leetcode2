// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem132.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution
{

public:
    int minCut(string s)
    {
        int n = s.length();
        vector<vector<int>> g(n,vector<int>(n,1));
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                g[i][j]=(s[i]==s[j])&&g[i+1][j-1];
            }
        }
        vector<int> f(n,INT_MAX);
        for(int i=0;i<n;i++){
            if(g[0][i]){
                f[i]=0;
            }else{
                for(int j=0;j<i;j++){
                    if(g[j+1][i]){
                        f[i]=min(f[i],f[j]+1);
                    }
                }
            }
        }
        return f[n-1];
    }
};
// @lc code=end
