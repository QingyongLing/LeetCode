#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <deque>
using namespace std;
/*
Given a string S and a string T, find the minimum window in S which will contain 
all the characters in T in complexity O(n).
For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
Note:
If there is no such window in S that covers all characters in T, return the empty string "".
If there are multiple such windows, you are guaranteed that there will always be only one
unique minimum window in S.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> count;
        for (char c : t)++count[c];
        deque<int> index;
        int num = 0, len = INT_MAX, start = -1;
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); ++i) {
            if (count.find(s[i]) != count.end()) {
                index.push_back(i);
                ++map[s[i]];
                if (map[s[i]] == count[s[i]])
                    ++num;
                while (num == count.size()) {
                    if (len > index.back() - index.front() + 1) {
                        len = index.back() - index.front() + 1;
                        start = index.front();
                    }
                    char c = s[index.front()];
                    index.pop_front();
                    --map[c];
                    if (map[c] < count[c])
                        --num;
                }
            }
        }
        return start == -1 ? "" : s.substr(start, len);
    }
    //more effective
    string minWindow2(string s, string t) {
        int count[128] = {};
        int kinds = 0;
        for (char c : t) {
            ++count[c];
            if (count[c] == 1)++kinds;
        }
        deque<int> index;
        int num = 0, len = INT_MAX, start = -1;
        int map[128] = {};
        for (int i = 0; i < s.size(); ++i) {
            if (count[s[i]]) {
                index.push_back(i);
                ++map[s[i]];
                if (map[s[i]] == count[s[i]])
                    ++num;
                while (num == kinds) {
                    if (len > index.back() - index.front() + 1) {
                        len = index.back() - index.front() + 1;
                        start = index.front();
                    }
                    char c = s[index.front()];
                    index.pop_front();
                    --map[c];
                    if (map[c] < count[c])
                        --num;
                }
            }
        }
        return start == -1 ? "" : s.substr(start, len);
    }

    string minWindow3(string s, string t) {
        int count[128] = {};
        int kinds = 0;
        for (char c : t) {
            ++count[c];
            if (count[c] == 1)++kinds;
        }
        int num = 0, len = INT_MAX, start = -1, index = 0;
        int map[128] = {};
        for (int i = 0; i < s.size(); ++i) {
            if (count[s[i]]) {
                if (++map[s[i]] == count[s[i]])
                    ++num;
                while (num == kinds) {
                    while (count[s[index]] == 0) ++index;
                    if (len > i - index + 1) {
                        len = i - index + 1;
                        start = index;
                    }
                    char c = s[index++];
                    if (--map[c] < count[c])
                        --num;
                }
            }
        }
        return start == -1 ? "" : s.substr(start, len);
    }
};
int main() {
    Solution s;
    cout << s.minWindow3("A", "A") << endl;
}
