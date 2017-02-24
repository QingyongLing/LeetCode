#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Implement wildcard pattern matching with support for '?' and '*'.
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(const char *s, const char *p)
Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

class Solution {
public:
    //From: https ://discuss.leetcode.com/topic/21577/my-three-c-solutions-iterative-16ms-dp-180ms-modified-recursion-88ms
    bool isMatch(string s, string p) {
        int  slen = s.size(), plen = p.size(), i, j, iStar = -1, jStar = -1;
        for (i = 0, j = 0; i<slen; ++i, ++j)
        {
            if (p[j] == '*')
            { //meet a new '*', update traceback i/j info
                iStar = i;
                jStar = j;
                --i;
            }
            else
            {
                if (p[j] != s[i] && p[j] != '?')
                {  // mismatch happens
                    if (iStar >= 0)
                    { // met a '*' before, then do traceback
                        i = iStar++;
                        j = jStar;
                    }
                    else return false; // otherwise fail
                }
            }
        }
        while (p[j] == '*') ++j;
        return j == plen;
    }
};
int main() {
    Solution s;
    cout << boolalpha << s.isMatch("acc", "acc") << endl;
    cout << boolalpha << s.isMatch("acc", "a*c") << endl;
    cout << boolalpha << s.isMatch("", "?") << endl;
    cout << boolalpha << s.isMatch("", "*") << endl;
    cout << boolalpha << s.isMatch("a", "a**") << endl;
    cout << boolalpha << s.isMatch("acdcdcd", "*c*d") << endl;
    cout << boolalpha << s.isMatch("", "**") << endl;
    cout << boolalpha << s.isMatch("ssssssss", "sss") << endl;
    return 0;
}
