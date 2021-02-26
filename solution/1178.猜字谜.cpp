#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
{

} // namespace std;

/*
 * @lc app=leetcode.cn id=1178 lang=cpp
 *
 * [1178] 猜字谜
 */

// @lc code=start
class Solution
{
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
    {
        unordered_map<int, int> frequency;
        for (auto &word : words)
        {
            int mask = 0;
            for (auto &c : word)
            {
                mask |= (1 << (c - 'a'));
            }
            if (__builtin_popcount(mask) <= 7)
            {
                frequency[mask]++;
            }
        }

        vector<int> ans;
        for (auto &puzzle : puzzles)
        {
            int total = 0;

            // 方法一 遍历枚举
            // for (int choose = 0; choose < (1 << 6); choose++)
            // {
            //     int mask = 0;
            //     for (int i = 1; i < 7; i++)
            //     {
            //         if (choose & (1 << (i - 1)))
            //         {
            //             mask |= (1 << (puzzle[i] - 'a'));
            //         }
            //     }
            //     mask |= (1 << (puzzle[0] - 'a'));
            //     if(frequency.count(mask)==1){
            //         total+=frequency[mask];
            //     }
            // }

            // 方法二 枚举子集
            int mask = 0;
            for (int i = 1; i < 7; i++)
            {
                mask |= (1 << (puzzle[i] - 'a'));
            }
            int subset = mask;
            do
            {
                int s = subset | (1 << (puzzle[0] - 'a'));
                if (frequency.count(s))
                {
                    total += frequency[s];
                }
                subset = (subset - 1) & mask;
                // 最后subset=0时，减1 就是全1，自然会等于mask
            } while (subset != mask);

            ans.emplace_back(total);
        }
        return ans;
    }
};
// @lc code=end
