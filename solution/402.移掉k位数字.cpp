#include <queue>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> stk;
        char ctop;
        int n = num.size();
        int i = 0;
        while (i < n)
        {
            while (!stk.empty()&&k>0&&num[i]<stk.top())
            {
                stk.pop();
                k--;
            }
            if (num[i] != '0' || !stk.empty())
            {
                stk.emplace(num[i]);
            }
            i++;
        }
        while (!stk.empty()&&k > 0)
        {
            stk.pop();
            k--;
        }
        if (stk.empty())
            return "0";
        vector<char> vc;
        while (!stk.empty())
        {
            vc.emplace_back(stk.top());
            stk.pop();
        }
        reverse(vc.begin(), vc.end());
        string ret(vc.begin(), vc.end());
        return ret;
    }
};