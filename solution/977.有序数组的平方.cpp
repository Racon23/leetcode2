// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem977.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        int neg, opt;
        int n = A.size();
        vector<int> res;
        if (n == 0)
        {
            return res;
        }
        for (int i = 0; i < n; i++)
        {
            if (A[i] >= 0)
            {
                opt = i;
                neg = i - 1;
                break;
            }
            if(i==n-1&&A[i]<0){
                neg = n-1;
                opt = n;
            }
        }
        int tn, to;
        while (neg >= 0 && opt < n)
        {
            tn = A[neg] * A[neg];
            to = A[opt] * A[opt];
            if (tn >= to)
            {
                res.emplace_back(to);
                opt++;
            }
            else
            {
                res.emplace_back(tn);
                neg--;
            }
        }
        while (neg >= 0)
        {
            tn = A[neg] * A[neg];
            res.emplace_back(tn);
            neg--;
        }
        while (opt < n)
        {
            to = A[opt] * A[opt];
            res.emplace_back(to);
            opt++;
        }
        return res;
    }
};
// @lc code=end
