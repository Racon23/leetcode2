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
class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        int n = A.size();
        int i = 0, j = 0;
        while (j < n)
        {
            if(i==j&&A[j]%2==i%2) {
                swap(A[i],A[j]);
                i++;j++;
            }else if(i<j&&A[j]%2==i%2){
                i+=2;
                j=j<i?i:j;
            }else{
                j++;
            }
        }

    }
};
// @lc code=end
