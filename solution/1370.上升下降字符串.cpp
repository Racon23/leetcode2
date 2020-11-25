/*
 * @lc app=leetcode.cn id=1370 lang=cpp
 *
 * [1370] 上升下降字符串
 */

// @lc code=start
class Solution
{
public:
    string sortString(string s)
    {
        vector<char> letters(26, 0);
        int n = s.size();
        for (auto &it : s)
        {
            letters[it - 'a']++;
        }
        string ret;
        int count = n;
        while (count > 0)
        {
            for (int i = 0; i < 26; i++)
            {
                if (letters[i] > 0)
                {
                    ret += (char)(i + 'a');
                    letters[i]--;
                    count--;
                }
            }
            for (int i = 25; i >= 0; i--)
            {
                if (letters[i] > 0)
                {
                    ret += (char)(i + 'a');
                    letters[i]--;
                    count--;
                }
            }
        }

        return ret;
    }
};
// @lc code=end
