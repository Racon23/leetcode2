// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include "commoncppproblem399.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int nvars = 0;
        unordered_map<string, int> variables;
        int n = equations.size();
        // 给每个点一个序号
        for (int i = 0; i < n; i++)
        {
            if (variables.find(equations[i][0]) == variables.end())
            {
                variables[equations[i][0]]=nvars++;
            }
            if (variables.find(equations[i][1]) == variables.end())
            {
                variables[equations[i][1]]=nvars++;
            }
        }

        // 记录点之间的距离 权值
        vector<vector<pair<int,double>>> edges(nvars);
        for(int i=0;i<n;i++){
            int va = variables[equations[i][0]],vb=variables[equations[i][1]];
            edges[va].push_back(make_pair(vb, values[i]));
            edges[vb].push_back(make_pair(va, 1.0/values[i]));
        }

        // 开始广度优先
        vector<double> ret;
        for(const auto &q:queries){
            double result = -1.0;
            int ia = q[0],ib=q[1];
            if(variables.find(ia)!=variables.end()&&variables.find(ib)!=variables.end()){
                if(ia==ib){
                    result = 1.0;
                }else{
                    // 记录搜索时的点
                    queue<int> points;
                    points.emplace(ia);
                    vector<double> 
                }

            }
        }
    }
};
// @lc code=end
