#include <iostream>
#include <vector>
#include <string> 
using namespace std;
/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending
multiple copies of the substring together. You may assume the given string consists of lowercase 
English letters only and its length will not exceed 10000.
Example 1:
Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"
Output: False
Example 3:
Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

class Solution {
public:
    bool repeatedSubstringPattern(string str){
        int size = str.size();
        int num = size / 2;
        for (int i = 1; i <= num; ++i) {
            if (size % i == 0) {
                int times = size / i;
                bool equal = true;
                for (int j = 0; j < i && equal; ++j) {
                    for (int k = 1; k < times && equal; ++k)
                        if (str[j + k*i] != str[j + (k - 1)*i])
                            equal = false;
                }
                if (equal) return true;
            }
        }
        return false;
    }
};
int main() {
    Solution s;
    cout << s.repeatedSubstringPattern("abcabc") << endl;
}
