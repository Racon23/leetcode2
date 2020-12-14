// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem649.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */

// @lc code=start
// 迭代
class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int len = senate.size();
        vector<char> vc(len);
        vc.assign(senate.begin(), senate.end());

        vector<char> next;
        int rb = 0, db = 0, rc = 0, dc = 0;
        int flag = 0;
        while (flag == 0 || (rc > 0 && dc > 0))
        {
            rc = dc = 0;
            flag = 1;
            for (auto &x : vc)
            {

                if (x == 'R')
                {
                    if (rb == 0)
                    {
                        db++;
                        rc++;
                        next.emplace_back('R');
                    }
                    else
                    {
                        rb--;
                    }
                }
                else
                {
                    if (db == 0)
                    {
                        rb++;
                        dc++;
                        next.emplace_back('D');
                    }
                    else
                    {
                        db--;
                    }
                }
            }

            // vc.clear();
            vc.swap(next);
            vector<char>().swap(next);
        }

        if (dc == 0)
            return "Radiant";
        else
            return "Dire";
    }
};
// @lc code=end
