#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Given a string s1, we may represent it as a binary tree by partitioning it to 
two non-empty substrings recursively.
Below is one possible representation of s1 = "great":
      great
     /    \
    gr    eat
   / \    /  \
  g   r  e   at
            / \
           a   t
To scramble the string, we may choose any non-leaf node and swap its two children.
For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
          / \
         a   t
We say that "rgeat" is a scrambled string of "great".
Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
      / \
     t   a
We say that "rgtae" is a scrambled string of "great".
Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

class Solution {
public:
    //if s1 and s1 is too long ,may TLE
    bool isScramble(string s1, string s2) {
        if (s1 == s2)return true;
        char c1[128] = {}, c2[128] = {};
        for (int i = 0; i < s1.size(); ++i) {
            ++c1[s1[i]];
            ++c2[s2[i]];
        }
        for (int i = 0; i < 128; ++i)
            if (c1[i] != c2[i])
                return false;
        for (int i = 1; i < s1.size(); ++i) {
            string s11 = s1.substr(0, i), s12 = s1.substr(i, s1.size() - i);
            string s21 = s2.substr(0, i), s22 = s2.substr(i, s2.size() - i);
            if (isScramble(s11, s21) && isScramble(s12, s22))
                return true;
            s21 = s2.substr(0, s2.size() - i), s22 = s2.substr(s2.size() - i, i);
            if (isScramble(s11, s22) && isScramble(s12, s21))
                return true;
        }
        return false;
    }
    //using DP  http://blog.sina.com.cn/s/blog_b9285de20101gy6n.html
    bool isScramble2(string s1, string s2) {
        const int size = s1.size(), len = size*size*size;
        if (size == 0)return true;
        if (size == 1)return s1 == s2;
        bool *dp = new bool[len];
        for (int i = 0; i < len; ++i)
            dp[i] = false;
        for (int i = size - 1; i >= 0; --i) {
            for (int j = size - 1; j >= 0; --j) {
                for (int k = 1; k <= size - max(i, j); ++k) {
                    if (s1.substr(i, k) == s2.substr(j, k))                       
                        dp[i*size*size + j*size + k] = true;  //dp[i][j][k]
                    else {
                        for (int l = 1; l < k; ++l) {
                            if (dp[i*size*size + j*size + l] && dp[(i + l)*size*size + (j + l)*size + k - l])
                                dp[i*size*size + j*size + k] = true;
                            if (dp[i*size*size + (j + k - l)*size + l] && dp[(i + l)*size*size + j*size + k - l])
                                dp[i*size*size + j*size + k] = true;
                        }
                    }
                }
            }
        }
        bool result = dp[size];
        delete dp;
        return result;
    }
};
int main() {
    Solution s;
    cout << s.isScramble2("rgtae", "great") << endl;
}
