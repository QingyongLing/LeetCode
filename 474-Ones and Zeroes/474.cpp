#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
In the computer world, use restricted resource you have to generate maximum benefit is what we 
always want to pursue.
For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is 
an array with strings consisting of only 0s and 1s.
Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. 
Each 0 and 1 can be used at most once.
Note:
1.The given numbers of 0s and 1s will both not exceed 100
2.The size of given string array won't exceed 600.
Example 1:
Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4
Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
Example 2:
Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2
Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if (strs.empty()) return 0;
        vector<int> zeros(strs.size()), ones(strs.size());
        for (int i = 0; i < strs.size(); ++i) {
            int zero = 0, one = 0;
            for (char c : strs[i])
                c == '0' ? ++zero : ++one;
            zeros[i] = zero;
            ones[i] = one;
        }
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int k = 0; k < strs.size(); ++k) {
            for (int i = n; i >= ones[k]; --i)
                for (int j = m; j >= zeros[k]; --j)
                    dp[i][j] = max(dp[i][j], dp[i - ones[k]][j - zeros[k]] + 1);
        }
        return dp[n][m];
    }
};
int main() {
    Solution s;
    vector<string> vec{ "10", "0001", "111001", "1", "0" };
    cout << s.findMaxForm(vec, 5, 3);
}
