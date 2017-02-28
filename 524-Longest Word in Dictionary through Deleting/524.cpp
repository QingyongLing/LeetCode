#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]
Output:
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]
Output:
"a"
Note:
1.All the strings in the input will only contain lower-case letters.
2.The size of the dictionary won't exceed 1,000.
3.The length of all the strings in the input won't exceed 1,000.
*/

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end());
        int maxlen = -1, index = -1;
        for (int i = 0; i < d.size(); ++i) {
            if (canbeformed(s, d[i])) {
                int len = d[i].size();
                if (len > maxlen) {
                    maxlen = d[i].size();
                    index = i;
                }
            }
        }
        return index == -1 ? "" : d[index];
    }
private:
    bool canbeformed(string &s, string &d) {
        int indexs = 0, indexd = 0;
        while (indexs < s.size() && indexd < d.size()) {
            if (s[indexs] == d[indexd])
                ++indexs, ++indexd;
            else
                ++indexs;
        }
        return indexd == d.size();
    }
};
int main() {
    Solution s;
    return 0;
}
