// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem204.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution
{
public:
    int isPrime(int n)
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n)
    {
        int ans = 0;
        for (int i = 2; i < n; i++)
        {
            ans += isPrime(i);
        }
        return ans;
    }
};
// @lc code=end
