#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
Given an input string, reverse the string word by word.
For example,
Given s = "the sky is blue",
return "blue is sky the".
Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.
Clarification:
•What constitutes a word?
A sequence of non-space characters constitutes a word.
•Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
•How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/
class Solution {
public:
    void reverseWords(string &s) {
        if (s.empty())return;
        reverse(s.begin(), s.end());
        int lo = 0, hi = 0;
        while (lo < s.size()) {
            while (lo < s.size() && s[lo] == ' ')
                ++lo;
            hi = lo;
            while (hi < s.size() && s[hi] != ' ')
                ++hi;
            reverse(s.begin() + lo, s.begin() + hi);
            lo = hi;
        }  
        lo = 0, hi = 0;
        while (hi < s.size()) {
            if (s[hi] == ' ' && (hi == 0 || s[hi - 1] == ' '))
                ++hi;
            else
                s[lo++] = s[hi++];
        }
        if (s[lo - 1] == ' ')lo--;
        s.resize(lo);
    }
};
int main() {
    Solution s;
    string str = "  abs cdef   s sdw ss  ";
    s.reverseWords(str);
    cout << str <<"|"<< endl;
    system("pause");
    return 0;
}