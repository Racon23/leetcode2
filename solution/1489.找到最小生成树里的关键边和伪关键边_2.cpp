#include <vector>
#include <algorithm>
#include <numeric>
#include<unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=1489 lang=cpp
 *
 * [1489] 找到最小生成树里的关键边和伪关键边
 */

// @lc code=start
// 并查集 tarjan找桥边
class UnionFind
{

public:
    vector<int> parent; // 祖先
    vector<int> size;   // 该祖先下的点个数
    int setCount;       // 连通量
    int n;              //点个数

    UnionFind(int _n) : n(_n), setCount(_n), parent(_n), size(_n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int findset(int x)
    {
        return x == parent[x] ? x : parent[x] = findset(parent[x]);
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
            if (size[x] < size[y])
            {
                swap(x, y);
            }
            parent[y] = x;
            size[x] += size[y];
            --setCount;
            return true;
        }
    }

    bool connected(int x, int y)
    {
        return findset(x) == findset(y);
    }
};

class TarjanSCC
{
private:
    const vector<vector<int>> edges;   // 记录点u拥有的边连接的点
    const vector<vector<int>> edgesId; // 记录点u拥有的边的id
    vector<int> low;                   //记录回溯时间点
    vector<int> dfn;                   //记录遍历时间点
    vector<int> ans;                   //记录找到的桥边
    int n;                             // 本次图G的点数
    int ts;                            // 时间戳

    void getCuttingEdge_(int u, int parentEdgeId)
    {
        low[u] = dfn[u] = ++ts;
        int usize = edges[u].size();
        for (int i = 0; i < usize; i++)
        {
            int v = edges[u][i];
            int id = edgesId[u][i];
            if (dfn[v] == -1){
                getCuttingEdge_(v,id);
                low[u]=min(low[u],low[v]);
                if(low[u]>dfn[v]){
                    ans.emplace_back(id);
                }
            }else if(id!=parentEdgeId){
                // 回溯时间，比如a->b->c,如果此时有一条ac边，更新low[c]=dfn[a]
                // 为什么不是low[c]=low[a]。因为low[a]受其他边影响
                low[u]=min(low[u],dfn[v]);
            }
        }
    }
public:
    TarjanSCC(int _n, vector<vector<int>> &edges_, vector<vector<int>> &edgesId_) : n(_n), low(_n, -1), dfn(_n, -1), edges(edges_), edgesId(edgesId_), ts(-1)
    {
    }

    vector<int> getCuttingEdge(){
        for(int i=0;i<n;i++){
            if(dfn[i]==-1){
                getCuttingEdge_(i,-1);
            }
        }
        return ans;
    }

};

class Solution
{
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        int m = edges.size();
        for (int i = 0; i < m; i++)
        {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](auto &u, auto &v) {
            return u[2] < v[2];
        });
        UnionFind uf(n);
        vector<vector<int>> ans(2, vector<int>());
        vector<int> label(m, 0); //标记边类型，-1自环边，1桥边，0非桥边

        for(int i=0;i<m;){
            // 找出权值为w的边，范围[i,j)
            int w = edges[i][2];
            int j=i;
            while(j<m&&edges[j][2]==w){
                j++;
            }

            // 存储每个连通分量在G中的编号
            unordered_map<int,int> compToId;
            // 图G点个数
            int gn=0;

            for(int k=i;k<j;k++){
                int x = uf.findset(edges[k][0]);
                int y = uf.findset(edges[k][1]);
                if(x!=y){
                    if(!compToId.count(x)){
                        compToId[x]=gn++;
                    }
                    if(!compToId.count(y)){
                        compToId[y]=gn++;
                    }
                }else{
                    // 将自环边标记为-1
                    label[edges[k][3]]=-1;
                }
            }

            // 图G的边
            vector<vector<int>> gm(gn),gmid(gn);

            for(int k=i;k<j;k++){
                int x = uf.findset(edges[k][0]);
                int y = uf.findset(edges[k][1]);
                if(x!=y){
                    int idx = compToId[x],idy=compToId[y];
                    gm[idx].emplace_back(idy);
                    gm[idy].emplace_back(idx);
                    gmid[idx].emplace_back(edges[k][3]);
                    gmid[idy].emplace_back(edges[k][3]);
                }
            }

            

        }
        
        return ans;
    }
};
// @lc code=end
