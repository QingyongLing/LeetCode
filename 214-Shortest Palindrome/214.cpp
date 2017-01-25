#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it.
Find and return the shortest palindrome you can find by performing this transformation.
For example:
Given "aacecaaa", return "aaacecaaa".
Given "abcd", return "dcbabcd".
Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Thanks to @Freezen for
additional test cases.
*/

class Solution {
public:
    //From: https://discuss.leetcode.com/topic/21068/my-7-lines-recursive-java-solution/56
    //Brilliant and elegant solution.
    string shortestPalindrome(string s) {
        int j = 0;
        for (int i = s.size() - 1; i >= 0; i--)
            if (s[j] == s[i])  j++;
        if (j == s.size())  return s;
        string suffix = s.substr(j);
        return string(suffix.rbegin(), suffix.rend()).append(shortestPalindrome(s.substr(0, j))).append(suffix);
    }
};
int main() {
    Solution s;
    cout << s.shortestPalindrome("aacecaaa") << endl;
    return 0;
}