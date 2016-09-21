#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
/*
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
For example,
Given "egg", "add", return true.
Given "foo", "bar", return false.
Given "paper", "title", return true.
Note:
You may assume both s and t have the same length.
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, vector<int>> smap, tmap;
        for (int i = 0; i < s.size(); ++i)
            smap[s[i]].push_back(i);
        for (int i = 0; i < t.size(); ++i)
            tmap[t[i]].push_back(i);
        auto compare = [](vector<int> &a, vector<int> &b) {
            if (a.size() > b.size())
                return true;
            else if (a.size() < b.size())
                return false;
            else return a > b;
        };
        vector<vector<int>> stemp, ttemp;
        for (auto &iter : smap) stemp.push_back(iter.second);
        for (auto &iter : tmap) ttemp.push_back(iter.second);
        sort(stemp.begin(), stemp.end(), compare);
        sort(ttemp.begin(), ttemp.end(), compare);
        return stemp == ttemp;
    }
    //From: https://discuss.leetcode.com/topic/49613/8ms-c-simple-solution
    bool isIsomorphic2(string s, string t) {
        int cs[128] = { 0 }, ct[128] = { 0 };
        for (int i = 0; i < s.size(); i++) {
            if (cs[s[i]] != ct[t[i]]) return false;
            else if (!cs[s[i]]) {//only record once
                cs[s[i]] = i + 1;
                ct[t[i]] = i + 1;
            }
        }
        return true;
    }
};
int main() {
    Solution s; 
    cout << s.isIsomorphic("paper", "title") << endl;
    system("pause");
    return 0;
}