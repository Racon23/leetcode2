// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include "commoncppproblem765.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */

// @lc code=start

class UnionFind
{
public:
    vector<int> parent;
    vector<int> size;
    int setCount;
    int n;

    UnionFind(int n_) : n(n_), setCount(n_), parent(vector<int>(n_)), size(vector<int>(n_, 1))
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int findset(int x)
    {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }

    bool unite(int x, int y)
    {
        x = findset(x);
        y = findset(y);
        if (x == y)
        {
            return false;
        }
        if (size[x] < size[y])
        {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        setCount--;
        return true;
    }

};

class Solution
{
public:
    int minSwapsCouples(vector<int> &row)
    {
        int n = row.size();
        int n2 = n/2;
        UnionFind uf(n2);
        for(int i=0;i<n;i+=2){
            uf.unite(row[i]/2,row[i+1]/2);
        }
        int ans=0;
        for(int i=0;i<n2;i++){
            int x = uf.findset(i);
            if(x==i){
                ans+=uf.size[i]-1;
            }
        }
        return ans;
    }
};
// @lc code=end
