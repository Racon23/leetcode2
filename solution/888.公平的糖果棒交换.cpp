// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem888.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果棒交换
 */

// @lc code=start
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        int an = A.size();
        int bn = B.size();
        int sa = 0,sb = 0;
        for(int i=0;i<an;i++){
            sa += A[i];
        }
        for(int j=0;j<bn;j++){
            sb+=B[j];
        }
        int d = (sa-sb)/2;
        int i = 0,j=0;
        while(d!= A[i]-B[j]){
            if(A[i]-B[j]>d){
                j++;
            }else{
                i++;
            }
        }
        vector<int> ans(2);
        ans[0] = A[i];
        ans[1] = B[j];
        return ans;
    }
};
// @lc code=end

