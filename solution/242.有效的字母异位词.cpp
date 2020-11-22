/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m) return false;
        vector<int> hm(26,0);
        for(auto &it: s){
            hm[it-'a']++;
        }
        for(auto &it:t){
            hm[it-'a']--;
            if(hm[it-'a']<0) return false;
        }
        return true;
    }
};
// @lc code=end

