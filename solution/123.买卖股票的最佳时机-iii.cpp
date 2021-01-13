// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem123.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int stock1 = -prices[0];
        int stock2 = -prices[0];
        int money1 = 0;
        int money2 = 0;

        for(int i=1;i<n;i++){
            stock1 = max(stock1,-prices[i]);
            money1 = max(money1, stock1+prices[i]);
            stock2 = max(stock2, money1-prices[i]);
            money2 = max(money2, stock2+prices[i]);
        }
        return money2;
    }
};
// @lc code=end

