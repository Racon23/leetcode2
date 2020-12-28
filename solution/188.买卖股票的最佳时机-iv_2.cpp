// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem188.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        k = min(k, n / 2);
        if (k == 0 || n < 2)
            return 0;
        vector<int> stock(k + 1);
        vector<int> money(k + 1);
        stock[0] = -prices[0];
        money[0] = 0;
        for (int i = 1; i <= k; i++)
        {
            // money有加减操作，除以防止溢出
            stock[i] = money[i] = INT_MIN / 2;
        }
        for (int i = 1; i < n; i++)
        {
            stock[0] = max(stock[0], money[0] - prices[i]);
            for (int j = 1; j <= k; j++)
            {
                stock[j] = max(stock[j], money[j] - prices[i]);
                money[j] = max(stock[j - 1] + prices[i], money[j]);
            }
        }

        return *max_element(money.begin(), money.end());
    }
};
// @lc code=end
