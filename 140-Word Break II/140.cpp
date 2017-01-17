#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
add spaces in s to construct a sentence where each word is a valid dictionary word. You may
assume the dictionary does not contain duplicate words.
Return all such possible sentences.
For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is ["cats and dog", "cat sand dog"].
UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). 
Please reload the code definition to get the latest changes.
*/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> flag(s.size() + 1);
        unordered_map<string, int> dict;
        unordered_set<int> len;
        for (int i = 0; i < wordDict.size(); ++i) {
            dict.insert(make_pair(wordDict[i], i));
            len.insert(wordDict[i].size());
        }
        flag[0] = vector<int>(1);
        for (int i = 0; i < s.size(); ++i) {
            if (!flag[i].empty()) {
                for (int j = 1; j + i - 1 < s.size(); ++j) {
                    if (len.find(j) != len.end()) {
                        auto iter = dict.find(s.substr(i, j));
                        if (iter != dict.end()) {
                            flag[i + j].push_back(iter->second);
                        }
                    }
                }
            }
        }
        vector<string> result;
        dfs(wordDict, flag, result, flag.size() - 1);
        return result;
    }
private:
    void dfs(vector<string>& wordDict, vector<vector<int>> &flag, vector<string> &result,int cur) {
        if (cur == 0) {
            result.push_back("");
            return;
        }
        int len = result.size();
        for (int i = 0; i < flag[cur].size(); ++i) {
            dfs(wordDict, flag, result, cur - wordDict[flag[cur][i]].size());
            for (int j = len; j < result.size(); ++j) {
                if (result[j].size())
                    result[j].push_back(' ');
                result[j].append(wordDict[flag[cur][i]]);
            }
            len = result.size();
        }
    }
};
int main() {
    Solution s;
    vector<string> vec{ "cat", "cats", "and", "sand", "dog" };
    auto result = s.wordBreak("catsanddog", vec);
    for (auto &c : result)
        cout << c << endl;
    return 0;
}
