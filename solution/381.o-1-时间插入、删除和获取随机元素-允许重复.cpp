// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "commoncppproblem381.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=381 lang=cpp
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 */

// @lc code=start
class RandomizedCollection
{
public:
    unordered_map<int, unordered_set<int>> idx;
    vector<int> nums;
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        nums.push_back(val);
        idx[val].insert(nums.size() - 1);
        return idx[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        if (idx.find(val) == idx.end())
        {
            return false;
        }
        int i = *(idx[val].begin()); //begin返回指针，加*返回值
        nums[i] = nums.back();       //调换末尾，记得更新hm

        idx[val].erase(i);
        idx[nums[i]].erase(nums.size() - 1); //如果是末尾元素，erase返回0
        if (i < nums.size() - 1)
        {
            idx[nums[i]].insert(i);
        }
        if (idx[val].size() == 0)
        {
            idx.erase(val);
        }
        nums.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
