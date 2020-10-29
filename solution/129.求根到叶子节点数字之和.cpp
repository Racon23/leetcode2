// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include "commoncppproblem129.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        TreeNode *p1 = root, *p2, *p3;
        int res = 0;//结果
        int cur = 0;//当前的数
        int prev = 0;//记录遍历p2的前缀，回到根时要减掉
        int count = 0;//记录连接时遍历过的p2节点数
        while (p1)
        {
            p2 = p1->left;
            if (p2)
            {
                prev = 0;
                count = 0;
                while (p2->right && p2->right != p1)
                {
                    prev = prev * 10 + p2->val;
                    count++;
                    p2 = p2->right;
                }
                prev = prev * 10 + p2->val;
                count++;
                if (p2->right)
                {
                    // 抵达最左节点，并且回到根
                    // p1可能是叶子节点右移抵达的
                    // 如果p3左子树空，证明左右子树都空，所以是叶子
                    if (p3 && !p3->left)
                        res += cur;
                    cur = (cur - prev) / pow(10, count);
                    p2->right = nullptr;
                    p3 = p1;
                    p1 = p1->right;
                }
                else
                {
                    // 初次抵达，连接根
                    cur = cur * 10 + p1->val;
                    p2->right = p1;
                    p1 = p1->left;
                }
            }
            else
            {
                // 最左节点
                // 如果是叶子，下一步后，回到根，可知p3右节点空，此时判断p3左节点空，为叶子
                // 如果不是叶子，会抵达右子节点，然后连接根。
                cur = cur * 10 + p1->val;
                p3 = p1;
                p1 = p1->right;
            }
        }
        // 补充最底最右节点
        if (p3 && !p3->left)
            res += cur;

        return res;
    }
};
// @lc code=end
