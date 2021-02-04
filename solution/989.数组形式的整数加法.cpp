// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem989.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 */

// @lc code=start
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &A, int K)
    {
        int n = A.size();
        int delta = 0;
        reverse(A.begin(), A.end());
        int i = 0;
        while (K > 0 || delta != 0)
        {
            if (i >= n)
            {
                A.emplace_back(0);
                n++;
            }
            int s = A[i] + K % 10 + delta;
            if (s >= 10)
            {
                A[i] = s % 10;
                delta = 1;
            }else{
                A[i]=s;
                delta=0;
            }
            K/=10;
            i++;
        }
        reverse(A.begin(),A.end());
        return A;
    }
};
// @lc code=end
