// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem173.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator
{

private:
    TreeNode *p1;
    TreeNode *p2;

    void link()
    {
        while (p1)
        {
            p2 = p1->left;
            if (p2)
            {
                while (p2->right && p2->right != p1)
                {
                    p2 = p2->right;
                }
                if (!p2->right)
                {
                    // 找到左子树最右节点，连接到根
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                }
                else
                {
                    // p2已经遍历过一次
                    p2->right = nullptr;
                    return ;
                }
            }
            else
            {
                // exe 最左节点
                return;
            }
            p1 = p1->right;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        p1 = root;
        p2 = p1->left;
        link();
    }

    int next()
    {
        int ans = p1->val;
        p1=p1->right;
        link();
        return ans;
    }

    bool hasNext()
    {
        return p1 != nullptr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
