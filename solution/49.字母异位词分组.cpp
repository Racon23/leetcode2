// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem49.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (64.55%)
 * Likes:    556
 * Dislikes: 0
 * Total Accepted:    130.3K
 * Total Submissions: 201.9K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */

// @lc code=start
// 超时
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        vector<unordered_map<int, int>> hm(n, unordered_map<int, int>());
        vector<int> cc(n);
        for (int i = 0; i < n; i++)
        {
            int sl = strs[i].size();
            for (int j = 0; j < sl; j++)
            {
                if (hm[i].find(strs[i][j]) == hm[i].end())
                {
                    cc[i]++;
                }
                hm[i][strs[i][j]]++;
            }
        }

        vector<vector<string>> ret;
        vector<vector<int>> spt; // 辅助记录ret的字符串对应的原串下标
        int retl = 0;
        for (int i = 0; i < n; i++)
        {
            retl = ret.size();
            bool isInsert = false;
            for (int j = 0; j < retl; j++)
            {
                if (cc[spt[j][0]] == cc[i])
                {
                    bool isEqual = true;
                    for (auto &x : hm[i])
                    {
                        // 如果比对哈希表中两个值不同
                        if (hm[spt[j][0]][x.first] != x.second)
                        {
                            isEqual = false;
                            break;
                        }
                    }
                    if (isEqual)
                    {
                        ret[j].push_back(strs[i]);
                        spt[j].push_back(i);
                        isInsert = true;
                    }
                }
            }
            if (!isInsert)
            {
                ret.emplace_back(vector<string>());
                ret[retl].push_back(strs[i]);
                spt.emplace_back(vector<int>());
                spt[retl].push_back(i);
            }
        }

        return ret;
    }
};
// @lc code=end
