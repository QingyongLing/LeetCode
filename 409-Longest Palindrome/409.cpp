#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Given a string which consists of lowercase or uppercase letters, find the length of the 
longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.
Note:
Assume the length of given string will not exceed 1,010.
Example:
Input:
"abccccdd"
Output:
7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/
class Solution {
public:
    int longestPalindrome(string s) {
        int map['z' - 'A' + 1] = {};
        for (char c : s) map[c - 'A']++;
        int len = 0;
        bool flag = false;
        for (int &i : map) {
            if (i % 2)
                flag = true, len += i - 1;
            else
                len += i;
        }
        return flag ? len + 1 : len;
    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("zeusnile") << endl;
    return 0;
}