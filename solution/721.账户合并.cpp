// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include<unordered_map>
#include <algorithm>
#include <numeric>

#include "commoncppproblem721.h"

using namespace std;
// @before-stub-for-debug-end

# include<vector>

/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */

// @lc code=start

class UnionFind
{
public:
    vector<int> parent;
    vector<int> rank;
    int n;
    int setCount;

    UnionFind(int n_) : n(n_), setCount(n_), parent(n_), rank(n_, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int findset(int x)
    {
        return x == parent[x] ? x : findset(parent[x]);
    }

    bool unite(int x, int y)
    {
        x = findset(x);
        y = findset(y);
        if (x == y)
        {
            return false;
        }
        else
        {
            if (rank[x] < rank[y])
            {
                swap(x, y);
            }
            parent[y] = x;
            rank[x] += rank[y];
            setCount--;
            return true;
        }
    }

    bool connected(int x, int y)
    {
        return findset(x) == findset(y);
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n =accounts.size();
        unordered_map<string,vector<int>> map;
        for(int i=0;i<n;i++){
            int esize = accounts[i].size();
            for(int j=1;j<esize;j++){
                if(!map.count(accounts[i][j])){
                    map[accounts[i][j]] = vector<int>();
                }
                map[accounts[i][j]].emplace_back(i);
            }
        }

        UnionFind uf(n);
        for(auto &e:map){
            vector<int> &vec = e.second;
            int size = vec.size();
            for(int i=1;i<size;i++){
                uf.unite(vec[0],vec[i]);
            }
        }
        
        vector<int> ansid(n);
        vector<vector<string>> ans;
        int count=0;
        for(int i=0;i<n;i++){
            int x = uf.findset(i);
            if(x==i){
                ans.push_back(vector<string>());
                ans[count].emplace_back(accounts[i][0]);
                ansid[i]=count++;
            }
        }
        for(int i=0;i<n;i++){
            int x = uf.findset(i);
            if(x!=i){
                ansid[i]=ansid[x];
            }
        }

        for(auto &e:map){
            string email = e.first;
            vector<int> &vec = e.second;
            int i = vec[0];
            ans[ansid[i]].emplace_back(email);
        }

        for(int i=0;i<count;i++){
            sort(ans[i].begin()+1,ans[i].end());
        }
        
        return ans;
    }
};
// @lc code=end

