// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem922.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
// 双指针
class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        int n = A.size();
        int i = 0, j = 1;
        while(i<n){
            if(A[i]%2==1){
                while(A[j]%2==1){
                    j+=2;
                }
                swap(A[i],A[j]);
            }
            i+=2;
        }
        return A;
    }
};
// @lc code=end
