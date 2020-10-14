// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "commoncppproblem1002.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 *
 * https://leetcode-cn.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (68.97%)
 * Likes:    106
 * Dislikes: 0
 * Total Accepted:    16.8K
 * Total Submissions: 24.3K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * 给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3
 * 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
 * 
 * 你可以按任意顺序返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：["bella","label","roller"]
 * 输出：["e","l","l"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：["cool","lock","cook"]
 * 输出：["c","o"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 100
 * 1 <= A[i].length <= 100
 * A[i][j] 是小写字母
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<string> commonChars(vector<string> &A)
    {
        int len = A.size();
        vector<unordered_map<char, int>> maps(len);
        vector<string> res;
        for (int i = 0; i < len; i++)
        {
            for (char c : A[i])
            {
                auto iter = maps[i].find(c);
                if (iter == maps[i].end())
                {
                    maps[i].insert(pair<char, int>(c, 1));
                }
                else
                {
                    iter->second++;
                }
            }
        }
        int count;
        char cc;
        auto iter = maps[0].begin();
        while (iter != maps[0].end())
        {
            cc = iter->first;
            count = iter->second;
            for (int j = 1; j < len; j++)
            {
                count = min(count, maps[j][cc]);
            }
            for (int k = 0; k < count; k++)
            {
                res.emplace_back(1,cc);
            }
            iter++;
        }

        return res;
    }
};
// @lc code=end
