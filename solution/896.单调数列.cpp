// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem896.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

// @lc code=start
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int flag = 0; //1 递增 2 递减
        int size = A.size();
        for(int i=1;i<size;i++){
            if(A[i]==A[i-1]){
                continue;
            }else if((flag==0||flag==1)&&A[i]>A[i-1]){
                flag=1;
            }else if((flag==0||flag==2)&&A[i]<A[i-1]){
                flag=2;
            }else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

