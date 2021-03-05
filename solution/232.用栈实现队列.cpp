// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem232.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue
{
    stack<int> instk;
    stack<int> outstk;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        instk.emplace(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int ret = peek();
        outstk.pop();

        return ret;
    }

    /** Get the front element. */
    int peek()
    {
        if (outstk.empty())
        {
            while (!instk.empty())
            {
                outstk.emplace(instk.top());
                instk.pop();
            }
        }
        int ret = outstk.top();

        return ret;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        if (instk.empty() && outstk.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
