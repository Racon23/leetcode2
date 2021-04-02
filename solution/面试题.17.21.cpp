#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> water(n, 0);
        int left = 0;
        for (int i = 0; i < n; i++)
        {
            if (height[i] <= left)
            {
                water[i] = left - height[i];
            }
            else
            {
                left = height[i];
                water[i]=0;
            }
        }
        int right = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (height[i] <= right)
            {
                water[i] = min(water[i], right - height[i]);
            }
            else
            {
                right = height[i];
                water[i]=0;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += water[i];
        }
        return res;
    }
};