// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem17.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if(digits.length()==0){
            return res;
        }
        string combin;
        unordered_map<int, string> letterMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
        backtrack(res, combin, letterMap, digits, 0);
        return res;
    }

    void backtrack(vector<string> &res, string &combin, unordered_map<int, string> letterMap, string digits, int index){
        if(index==digits.length()){
            res.emplace_back(combin);
        }else{
            char digit = digits[index];
            string letter = letterMap.at(digit);
            for(char c : letter){
                combin.push_back(c);
                backtrack(res,combin,letterMap,digits,index+1);
                combin.pop_back();
            }
        }
    }
};
// @lc code=end
