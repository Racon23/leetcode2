// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem834.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=834 lang=cpp
 *
 * [834] 树中距离之和
 *
 * https://leetcode-cn.com/problems/sum-of-distances-in-tree/description/
 *
 * algorithms
 * Hard (53.24%)
 * Likes:    220
 * Dislikes: 0
 * Total Accepted:    11K
 * Total Submissions: 20.7K
 * Testcase Example:  '6\n[[0,1],[0,2],[2,3],[2,4],[2,5]]'
 *
 * 给定一个无向、连通的树。树中有 N 个标记为 0...N-1 的节点以及 N-1 条边 。
 * 
 * 第 i 条边连接节点 edges[i][0] 和 edges[i][1] 。
 * 
 * 返回一个表示节点 i 与其他所有节点距离之和的列表 ans。
 * 
 * 示例 1:
 * 
 * 
 * 输入: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
 * 输出: [8,12,6,10,10,10]
 * 解释: 
 * 如下为给定的树的示意图：
 * ⁠ 0
 * ⁠/ \
 * 1   2
 * ⁠  /|\
 * ⁠ 3 4 5
 * 
 * 我们可以计算出 dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5) 
 * 也就是 1 + 1 + 2 + 2 + 2 = 8。 因此，answer[0] = 8，以此类推。
 * 
 * 
 * 说明: 1 <= N <= 10000
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges)
    {
        vector<vector<int>> list(N);
        // 制作子节点表，由小到大排
        for (int i = 0; i < edges.size(); i++)
        {
            // edges[i][0] edges[i][1]小的做list的行，大的做列
            if (edges[i][0] < edges[i][1])
            {
                list[edges[i][0]].emplace_back(edges[i][1]);
            }
            else
            {
                list[edges[i][1]].emplace_back(edges[i][0]);
            }
        }
        vector<int> ans(N);
        //计算ans0


    }

    

};
// @lc code=end
