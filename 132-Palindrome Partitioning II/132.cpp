#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
class Solution {
public:
    //http://blog.csdn.net/dr_unknown/article/details/51939833
    int minCut(string s) {
        vector<int> dp(s.size() + 1);
        for (int i = 0; i < dp.size(); ++i)
            dp[i] = i - 1;
        for (int i = 1; i < s.size(); ++i) {
            for (int j = 0; i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]; ++j)
                dp[i + j + 1] = min(dp[i + j + 1], dp[i - j] + 1);
            for (int j = 0; i - j - 1 >= 0 && i + j < s.size() && s[i - j - 1] == s[i + j]; ++j)
                dp[i + j + 1] = min(dp[i + j + 1], dp[i - j - 1] + 1);
        }
        return dp.back();
    }
};
int main() {
    Solution s;
    cout << s.minCut("aaabbbbccaa") << endl;
    return 0;
}
