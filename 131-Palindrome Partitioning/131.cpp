#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.
For example, given s = "aab",
Return
[
["aa","b"],
["a","a","b"]
]
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if (s.empty())
            return result;
        vector<string> split;
        splitstrpalindrome(result, split, s, 0);
        return result;
    }
private:
    void splitstrpalindrome(vector<vector<string>>& result, vector<string> &split, string &s, int start) {
        if (start == s.size()) {
            result.push_back(split);
        }else{
            for (int i = start; i < s.size(); ++i) {
                if (ispalindrome(s, start, i)) {
                    split.push_back(string(s.begin() + start, s.begin() + i + 1));
                    splitstrpalindrome(result, split, s, i + 1);
                    split.pop_back();
                }
            }
        }
    }
    bool ispalindrome(string &s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo++] != s[hi--])
                return false;
        }
        return true;
    }
};
int main() {
    Solution s;
    string str = "aab";
    auto result = s.partition(str);
    for (auto &strs : result) {
        for (auto &str : strs) {
            cout << str << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}