#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
American keyboard
Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
1.You may use one character in the keyboard more than once.
2.You may assume the input string will only contain letters of alphabet.
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> strs{ "qwertyuiop","asdfghjkl","zxcvbnm" };
        int flag[26] = {};
        for (int i = 0; i < strs.size(); ++i) {
            for (char c : strs[i])flag[c - 'a'] = i;
        }
        vector<string> answer;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].size() < 2) {
                answer.push_back(words[i]);
                continue;
            }
            bool oneline = true;
            for (int j = 1; j < words[i].size(); ++j) {
                int n = tolower(words[i][j]) - 'a';
                int m = tolower(words[i][j - 1]) - 'a';
                if (flag[n] != flag[m]) {
                    oneline = false;
                    break;
                }
            }
            if (oneline)answer.push_back(words[i]);
        }
        return answer;
    }
};
int main() {
    Solution s;
    return 0;
}
