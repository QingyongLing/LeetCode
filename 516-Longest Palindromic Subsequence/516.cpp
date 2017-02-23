#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
Example 1:
Input:
"bbbab"
Output: 4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:
"cbbd"
Output: 2
One possible longest palindromic subsequence is "bb".
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty())return 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        dp[0][0] = 1;
        for (int i = 1; i < s.size(); ++i) {
            dp[i][i] = 1;
            for (int j = i - 1; j > -1; --j) {
                if (s[j] == s[i]) {
                    dp[j][i] = max(dp[j][i], 2 + dp[j + 1][i - 1]);
                }  
                dp[j][i] = max(dp[j][i], dp[j][i - 1]);
                dp[j][i] = max(dp[j][i], dp[j + 1][i]);
            }
        }
        return dp[0].back();
    }
};
int main() {
    Solution s;
    cout << s.longestPalindromeSubseq("cbbd") << endl;
    return 0;
}
