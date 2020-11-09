// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
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
        int count = 0;
        int n = wordList.size();
        unordered_set<string> visited;
        queue<string> q;
        int len;
        q.emplace(beginWord);
        visited.emplace(beginWord);
        len = q.size();
        while (len > 0)
        {
            count++;
            for (int i = 0; i < len; i++)
            {
                string s = q.front();
                q.pop();
                for (auto &it : wordList)
                {
                    if (visited.find(it) != visited.end())
                    {
                        continue;
                    }
                    if (!canConvert(s, it))
                    {
                        continue;
                    }
                    if (endWord == it)
                    {
                        return count + 1;
                    }
                    q.emplace(it);
                    visited.emplace(it);
                }
            }
            len = q.size();
        }
        return 0;
    }

    bool canConvert(string s1, string s2)
    {
        if (s1.length() != s2.length())
            return false;
        int count = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
            {
                count++;
            }
        }
        return count == 1;
    }
};
// @lc code=end
