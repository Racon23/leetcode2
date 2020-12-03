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
// 线性筛
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<int> prime;
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
            {
                prime.emplace_back(i);
            }
            for (int j = 0; j < prime.size() && i * prime[j] < n; j++)
            {
                isPrime[i*prime[j]]=0;
                if(i%prime[j]==0){
                    break;
                }
            }
        }

        return prime.size();
    }
};
// @lc code=end
