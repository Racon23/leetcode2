// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <list>
#include "commoncppproblem705.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

// @lc code=start
class MyHashSet
{
private:
    static const int base = 769;
    vector<list<int>> data;

    static int hash(int key)
    {
        return key % base;
    }

public:
    /** Initialize your data structure here. */
    MyHashSet() : data(base)
    {
    }

    void add(int key)
    {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++)
        {
            if ((*it) == key)
            {
                return;
            }
        }
        data[h].emplace_back(key);
    }

    void remove(int key)
    {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++)
        {
            if ((*it) == key)
            {
                data[h].erase(it);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++)
        {
            if ((*it) == key)
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
