// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem767.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */

// @lc code=start
class Solution
{
public:
    string reorganizeString(string S)
    {
        int n = S.size();
        vector<pair<int, int>> letters(26, pair(0, 0));

        for(int i=0;i<26;i++){
            
        }

        for (auto &it : S)
        {
            letters[it - 'a'].second++;
        }

        sort(letters.begin(), letters.end(), [](const &pair<int, int> u, const &pair<int, int> v) {
            return u.second
        });

            vector<pair<char, int>>
                cs(n, pair(0, 0));

        for (int i = 0; i < 26; i++)
        {
        }

        return "";
    }
};
// @lc code=end
