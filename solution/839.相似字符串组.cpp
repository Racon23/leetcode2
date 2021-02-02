// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem839.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=839 lang=cpp
 *
 * [839] 相似字符串组
 */

// @lc code=start
class Solution {
public:
    int find1(int x,vector<int> &parent){
        if(x!=parent[x]){
            parent[x] = find1(parent[x],parent);
        }
        return parent[x];
    }

    void union1(int x,int y,vector<int> &parent,vector<int> &rank){
        int x_root = find1(x,parent);
        int y_root = find1(y,parent);
        if(rank[x_root]>rank[y_root]){
            parent[y_root] = x_root;
        }else if(rank[x_root]<rank[y_root]){
            parent[x_root] = y_root;
        }else{
            rank[x_root]++;
            parent[y_root] = x_root;
        }
    }

    bool check1(const string &a, const string &b,int len){
        int num=0;
        for(int i=0;i<len;i++){
            if(a[i]!=b[i]){
                num++;
            }
            if(num>2)
            return false;
        }
        return true;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> parent(n,0);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i; 
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                if(check1(strs[i],strs[j],m)){
                    union1(i,j,parent,rank);
                }

            }
        }

        for(int i=0;i<n;i++){
            if(parent[i]==i) ans++;
        }

        return ans;

    }
};
// @lc code=end

