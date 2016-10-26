#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;
/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words 
do not share common letters. You may assume that each word will contain only lower case letters. If no such
two words exist, return 0.
Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".
Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".
Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> flag(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            for (auto c : words[i])
                flag[i] |= 1 << (c - 'a');
        }
        int result = 0;
        for (int i = 0; i < flag.size(); ++i) {
            for (int j = i + 1; j < flag.size(); ++j) {
                if ((flag[i] & flag[j]) == 0) {
                    int temp = words[i].size()*words[j].size();
                    result = max(result, temp);
                }
            }
        }
        return result;
    }
};
int main() {
    Solution s;
    vector<string> words = { "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
    cout << s.maxProduct(words) << endl;
    return 0;
}