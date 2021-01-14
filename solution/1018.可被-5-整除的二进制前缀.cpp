// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1018.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */

// @lc code=start
class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &A)
    {
        int n = A.size();
        vector<bool> ans(n, false);

        int temp= 0;
        for (int i = 0; i < n; i++)
        {
            temp = (temp << 1) + A[i];
            if(temp >=5 ){
                temp = temp-5;
            }
            if(temp==0) ans[i]=true;
            else ans[i] = false;
        }
        return ans;
    }
};
// @lc code=end
