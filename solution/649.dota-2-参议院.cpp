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
// 递归
class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int len = senate.size();
        vector<char> vc(len);
        vc.assign(senate.begin(), senate.end());
        return nextSenate(vc, 0, 0);
    }

    string nextSenate(vector<char> &vc, int rb, int db)
    {
        vector<char> next;
        int rc = 0, dc = 0;
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
        if (dc == 0)
            return "Radiant";
        else if (rc == 0)
            return "Dire";
        else
            return nextSenate(next,rb,db);
    }
};
// @lc code=end
