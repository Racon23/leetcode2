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
        vector<int> arr;
        int res = 0;
        int cur = 0;
        int prev = 0;
        int count = 0;
        while (p1)
        {
            p2 = p1->left;
            // prev = 0;
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
                    // cur = cur * 10 + p3->val;

                    res += cur;
                    cur = (cur - prev) / pow(10, count);
                    p2->right = nullptr;
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
                cur = cur * 10 + p1->val;
                // res += cur;
                p3 = p1;
                // cur = (cur - p1->val) / 10;
                p1 = p1->right;
            }
        }
        if (p3&&p3->left && p3->right)
            res += cur;

        return res;
    }
};
// @lc code=end
