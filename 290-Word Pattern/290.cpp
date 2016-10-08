#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
/*
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
Examples:
1.pattern = "abba", str = "dog cat cat dog" should return true.
2.pattern = "abba", str = "dog cat cat fish" should return false.
3.pattern = "aaaa", str = "dog cat cat dog" should return false.
4.pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
Credits:
Special thanks to @minglotus6 for adding this problem and creating all test cases.
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> map('z' - 'a' + 1);
        unordered_set<string> strset;
        str.push_back(' ');
        int index = 0;
        for (int i = 0; i < pattern.size(); ++i) {
            if (index == str.size()) return false;
            int next = str.find_first_of(' ', index);
            string s = str.substr(index, next - index);
            index = ++next;
            if (map[pattern[i] - 'a'].empty()) {
                if (strset.find(s) == strset.end()) {
                    map[pattern[i] - 'a'] = s;
                    strset.insert(s);
                }
                else return false;
            }
            else if (map[pattern[i] - 'a'] != s)
                return false;
        }
        return index == str.size() ? true : false;
    }
};
int main() {
    Solution s;
    string pattern = "abba", str = "dog cat cat dog";
    cout << (s.wordPattern(pattern, str) ? "true" : "false") << endl;
    system("pause");
    return 0;
}