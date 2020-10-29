// @before-stub-for-debug-begin
#include <vector>
#include <string>
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
        TreeNode *p1 = root, *p2;
        vector<int> arr;
        int res = 0;
        int cur = 0;
        int prev = 0;
        while (p1)
        {
            p2 = p1->left;
            // prev = 0;
            if (p2)
            {
                prev = p2->val;
                while (p2->right && p2->right != p1)
                {
                    p2 = p2->right;
                    prev = prev*10 + p2->val;
                }
                if (p2->right)
                {
                    p2->right = nullptr;
                    cur = (cur - prev) / 10;
                    p1 = p1->right;
                }
                else
                {
                    cur = cur * 10 + p1->val;
                    p2->right = p1;
                    p1 = p1->left;
                }
            }
            else
            {
                // 最左节点
                cur = cur * 10 + p1->val;
                res += cur;
                // cur = (cur - p1->val) / 10;
                p1 = p1->right;
            }
        }

        return res;
    }
};
// @lc code=end
