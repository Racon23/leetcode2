#include <vector>
#include <string>
#include <queue>

using namespace std;

/*
 * @lc app=leetcode.cn id=1203 lang=cpp
 *
 * [1203] 项目管理
 */

// @lc code=start
// 官方解
class Solution
{
public:
    vector<int> topSort(vector<int> &deg, vector<vector<int>> &graph, vector<int> &items)
    {

        queue<int> Q;

        for (auto &item : items)
        {
            if (deg[item] == 0)
            {
                Q.emplace(item);
            }
        }

        vector<int> res;
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            res.emplace_back(u);
            for (auto &v : graph[u])
            {
                if (--deg[v] == 0)
                {
                    Q.emplace(v);
                }
            }
        }

        return res.size() == items.size() ? res : vector<int>{};
    }

    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
    {
        // 记录小组分配的项目，有可能所有小组都没有分配项目，所以是m + n
        vector<vector<int>> groupItem(n + m);
        // 组间建图，针对小组
        vector<vector<int>> groupGraph(n + m);
        // 组内项目建图
        vector<vector<int>> itemGraph(n);
        // 组间入度
        vector<int> groupDegree(n + m, 0);
        // 组内入度
        vector<int> itemDegree(n, 0);

        // 给没有分配小组的临时分配一个虚拟小组，并记录小组分配的项目
        int leftId = m;
        for (int i = 0; i < n; i++)
        {
            if (group[i] == -1)
            {
                group[i] = leftId++;
            }
            groupItem[group[i]].emplace_back(i);
        }

        // 建图
        for (int i = 0; i < n; i++)
        {
            int curGroupId = group[i];
            for (auto &item : beforeItems[i])
            {
                int beforeGroupId = group[item];
                if (curGroupId == beforeGroupId)
                {
                    // 组内建图
                    itemDegree[i]++;
                    itemGraph[item].emplace_back(i);
                }
                else
                {
                    // 组间建图
                    groupDegree[curGroupId]++;
                    groupGraph[beforeGroupId].emplace_back(curGroupId);
                }
            }
        }

        vector<int> id(n + m);
        for (int i = 0; i < n + m; i++)
        {
            id[i] = i;
        }

        // 组间拓扑排序
        vector<int> groupTopSort = topSort(groupDegree, groupGraph, id);
        if (groupTopSort.size() == 0)
        {
            return vector<int>{};
        }

        vector<int> ans;

        for (auto &curGroupId : groupTopSort)
        {
            int size = groupItem[curGroupId].size();
            if (size == 0)
            {
                continue;
            }
            if (curGroupId >= m)
            {
                ans.emplace_back(groupItem[curGroupId][0]);
            }
            else
            {
                vector<int> itemTopSort = topSort(itemDegree, itemGraph, groupItem[curGroupId]);
                if (itemTopSort.size() == size)
                {
                    for (auto &item : itemTopSort)
                    {
                        ans.emplace_back(item);
                    }
                }
                else
                {
                    return vector<int>{};
                }
            }
        }

        return ans;
    }
};
// @lc code=end
