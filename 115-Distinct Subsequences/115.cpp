#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Given a string S and a string T, count the number of distinct subsequences of T in S.
A subsequence of a string is a new string which is formed from the original string by 
deleting some (can be none) of the characters without disturbing the relative positions 
of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
Here is an example:
S = "rabbbit", T = "rabbit"
Return 3.
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size())return false;
        if (s.size() == t.size())return s == t;
        vector<vector<int>> dp(t.size(), vector<int>(s.size()));
        for (int i = 0; i < t.size(); ++i) {
            for (int j = 0; j < s.size(); ++j) {
                if (i == 0) {
                    dp[i][j] = s[j] == t[i] ? 1 : 0;
                }
                else if (j > 0) {
                    if (s[j] == t[i])
                        dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                    else
                        dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[t.size() - 1][s.size() - 1];
    }
};
int main() {
    Solution s;
    cout << s.numDistinct("rabbbit", "rabbit") << endl;
}
