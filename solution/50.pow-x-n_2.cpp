/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double quickMul(double x, long long n)
    {
        double ans = 1.0;
        // 最初值贡献了一个x
        double x_con = x;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                // 每当二进制对应位数是1,把x_con计入ans
                // ans = x^1 * x^4 * x^8 * x^64
                ans *= x_con;
            }
            x_con *=x_con;
            n /= 2;
        }
        return ans;
    }

    double myPow(double x, int n)
    {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
// @lc code=end
