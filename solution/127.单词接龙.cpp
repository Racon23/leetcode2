// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
#include "commoncppproblem127.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int i = 0;
        int count = 0;
        int n = wordList.size();
        unordered_set<string> wdset;
        for(auto &it:wordList){
            wdset.emplace(it);
        }

        while (beginword != endword || count < n)
        {
            
        }
    }
};
// @lc code=end
