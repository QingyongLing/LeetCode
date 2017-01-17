#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary
words. You may assume the dictionary does not contain duplicate words.
For example, given
s = "leetcode",
dict = ["leet", "code"].
Return true because "leetcode" can be segmented as "leet code".
UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings).
Please reload the code definition to get the latest changes.
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> flag(s.size() + 1, 0);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_set<int> len;
        for (auto &s : wordDict)len.insert(s.size());
        flag[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (flag[i]) {
                for (int j = 1; j + i - 1 < s.size(); ++j) {
                    if (len.find(j) != len.end()) {
                        if (dict.find(s.substr(i, j)) != dict.end())
                            flag[i + j] = 1;
                    }
                }
            }
        }
        return flag.back();
    }
};
int main() {
    Solution s;
    vector<string> vec{ "leet","code" };
    cout << s.wordBreak("leetcode", vec) << endl;
    return 0;
}
