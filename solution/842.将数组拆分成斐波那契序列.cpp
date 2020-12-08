// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem842.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=842 lang=cpp
 *
 * [842] 将数组拆分成斐波那契序列
 */

// @lc code=start
class Solution
{
public:
    vector<int> splitIntoFibonacci(string S)
    {
        vector<int> ans;
        int len = S.size();
        // i是切点后的位置
        int flag = 0;
        for (int i = 1; i < len - i; i++)
        {
            // 判断a是否超长
            long long a = atoll(S.substr(0, i).c_str());
            if(a>INT_MAX) break;
            int a32 = (int) a;
            ans.emplace_back(a32);
            // i alen
            // j-i blen
            // j<= len-i alen>blen，保证c有i位
            // j-i<= len-j blen>alen,保证c有j位
            for (int j = i + 1; j <= len - i && j - i <= len - j; j++)
            {
                // 判断a是否超长

                long long b = atoll(S.substr(i, j - i).c_str());
                if(b>INT_MAX) break;
                int b32 = (int)b;
                ans.emplace_back(b32);
                if (backtrace(S, len, j, a32, b32, ans))
                {
                    return ans;
                }
                else
                {
                    ans.pop_back();
                }
            }
            ans.pop_back();
        }
        return ans;
    }

    int calcLen(int num)
    {
        if (num == 0)
            return 1;
        int len = 0;
        while (num != 0)
        {
            num /= 10;
            len++;
        }
        return len;
    }

    bool backtrace(string &S, int len, int cut, int a, int b, vector<int> &ans)
    {
        if (cut == len)
        {
            return true;
        }
        else if (cut > len)
        {
            return false;
        }
        else
        {

            if (INT_MAX - b < a)
                return false; // 过长
            int c = a + b;
            int cl = calcLen(c);
            string cs = S.substr(cut, cl);
            if (atoi(cs.c_str()) == c)
            {
                ans.emplace_back(c);
                bool next = backtrace(S, len, cut + cl, b, c, ans);
                if (next)
                {
                    return true;
                }
                ans.pop_back();
            }
            return false;
        }
    }
};
// @lc code=end
