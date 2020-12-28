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
        vector<vector<int>> stock(n, vector<int>(k + 1));
        vector<vector<int>> money(n, vector<int>(k + 1));
        stock[0][0] = -prices[0];
        money[0][0] = 0;
        for (int i = 1; i <= k; i++)
        {
            // money有加减操作，除以防止溢出
            stock[0][i] = money[0][i] = INT_MIN / 2;
        }
        for (int i = 1; i < n; i++)
        {
            // stock[i][j] = stock[i-1][j];
            // stock[i][j] = money[i-1][j] - prices[i];
            stock[i][0] = max(stock[i - 1][0], money[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; j++)
            {
                stock[i][j] = max(stock[i - 1][j], money[i - 1][j] - prices[i]);
                money[i][j] = max(stock[i - 1][j - 1] + prices[i], money[i - 1][j]);
            }
        }

        return *max_element(money[n - 1].begin(), money[n - 1].end());
    }
};
// @lc code=end
