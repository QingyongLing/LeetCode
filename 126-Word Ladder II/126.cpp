#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation
sequence(s) from beginWord to endWord, such that:
1.Only one letter can be changed at a time
2.Each intermediate word must exist in the word list
For example,
Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]
Note:
•All words have the same length.
•All words contain only lowercase alphabetic characters.
*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<string> strs(wordList.begin(), wordList.end());
        strs.push_back(beginWord);
        strs.push_back(endWord);
        vector<vector<int>> neighbour(strs.size());
        for (int i = 0; i < strs.size(); ++i) {
            for (int j = i + 1; j < strs.size(); ++j)
                if (oneletter(strs[i], strs[j])) {
                    neighbour[i].push_back(j);
                    neighbour[j].push_back(i);
                }
        }
        vector<int> flag(strs.size(), 0);
        vector<unordered_set<int>> path;
        vector<vector<string>> result;
        int start = strs.size() - 2, last = strs.size() - 1;
        flag[start] = 1;       
        path.push_back(unordered_set<int>());
        path.front().insert(start);
        while (!path.back().empty()) {
            unordered_set<int> level;
            bool findlast = false;
            for (int i : path.back()) {
                for (int j : neighbour[i]) {
                    if (flag[j] == 0) flag[j] = 1, level.insert(j);
                    if (j == last)findlast = true;
                }
            }
            if (findlast) {
                deque<vector<int>> index;
                index.push_back(vector<int>(1, last));
                while (!path.empty()) {
                    int num = index.size();
                    while (num--) {
                        int cur = index.front().back();
                        for (int i : neighbour[cur]) {
                            if (path.back().find(i) != path.back().end()) {
                                index.push_back(index.front());
                                index.back().push_back(i);
                            }
                        }
                        index.pop_front();
                    }
                    path.pop_back();
                }
                for (auto &vec : index) {
                    result.push_back(vector<string>());
                    for (int i = vec.size() - 1; i >= 0; --i)
                        result.back().push_back(strs[vec[i]]);
                }
                break;
            }
            else
                path.push_back(level);
        }
        return result;
    }
private:
    bool oneletter(string &s1, string &s2) {
        int dif = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i])++dif;
            if (dif > 1) return false;
        }
        return dif == 1;
    }
};
int main() {
    Solution s;
    vector<string> vec = { "hot","dot","dog","lot","log" };
    auto result = s.findLadders("hit", "cog", unordered_set<string>(vec.begin(), vec.end()));
    for (auto &v : result) {
        for (auto &s : v)
            cout << s << " ";
        cout << endl;
    }
}
