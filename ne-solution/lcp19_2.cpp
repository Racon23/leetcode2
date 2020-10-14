#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minimumOperations(string leaves)
    {
        int n = leaves.size();
        vector<int> f(n);
        f[0] = leaves[0] == 'y';
        int c0 = f[0], c1 = n + 1, c2 = n + 1;
        for (int i = 1; i < n; i++)
        {
            int isRed = leaves[i] == 'r';
            int isYellow = leaves[i] == 'y';
            if (i >= 2)
            {
                f[i] = c2 = min(c1, c2) + isYellow;
            }
            c1 = min(c0, c1) + isRed;
            c0 = c0 + isYellow;
        }
        return f[n - 1];
    }
};

int main()
{
    Solution s;
    string in1 = "rrryyyrryyyrr";
    // string in1 = "ryr";

    cout << s.minimumOperations(in1);
    cout << endl;

    system("pause");
    return 0;
}