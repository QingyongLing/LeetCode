#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
You are given coins of different denominations and a total amount of money amount. Write a function to 
compute the fewest number of coins that you need to make up that amount. If that amount of money cannot 
be made up by any combination of the coins, return -1.
Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)
Example 2:
coins = [2], amount = 3
return -1.
Note:
You may assume that you have an infinite number of each kind of coin.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    //dp
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto c : coins) {
                if (i - c >= 0 && dp[i - c] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
    //dfs https://discuss.leetcode.com/topic/47774/8-ms-15-lines-concise-dfs-solution-c
    int coinChange2(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int result = INT_MAX;
        return searchchangedfs(coins, coins.size() - 1, amount, 0, result);
    }
    int searchchangedfs(vector<int>& coins, int index, int amount, int cur, int& result) {
        if (amount == 0) return result=cur;
        if (index < 0 ) return -1;
        int n = amount / coins[index];
        if (n + cur >= result) return -1;
        bool flag = false;
        for (int i = n; i >= 0; i--)
            if (searchchangedfs(coins, index - 1, amount - coins[index] * i, cur + i, result) != -1)
                flag = true;
        return flag ? result : -1;
    }
};
int main() {
    Solution s;
    vector<int> vec = { 1,2,5 };
    cout << s.coinChange2(vec, 11) << endl;
    return 0;
}