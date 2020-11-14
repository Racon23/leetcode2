#include <vector>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> m1;
        int n = arr1.size();
        int m = arr2.size();
        vector<int> ret(n);
        vector<int> spt(1001, 0);
        for (auto &it : arr1)
        {
            spt[it]++;
        }
        int i = 0;
        for (int j = 0; j < m; j++)
        {
            while (spt[arr2[j]] > 0)
            {
                arr1[i++] = arr2[j];
                spt[arr2[j]]--;
            }
        }
        for (int k = 0; k < 1001; k++)
        {
            while (spt[k] > 0)
            {
                arr1[i++] = k;
                spt[k]--;
            }
        }
        return arr1;
    }
};
// @lc code=end
