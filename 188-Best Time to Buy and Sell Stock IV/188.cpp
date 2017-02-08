#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most k transactions.
Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

class Solution {
public:
    //From:http://blog.csdn.net/monkeyduck/article/details/47661017
    //智商捉急ORZ
    int maxProfit(int k, vector<int> &prices) {
        int len = prices.size();
        if (len < 2) return 0;
        if (k > len / 2) {
            int ans = 0;
            for (int i = 1; i < len; ++i) {
                ans += max(prices[i] - prices[i - 1], 0);
            }
            return ans;
        }
        vector<int> hold(k + 1, INT_MIN), sell(k + 1, 0);
        int cur;
        for (int i = 0; i < len; ++i) {
            cur = prices[i];
            for (int j = 1; j <= k; ++j) {
                sell[j] = max(sell[j], hold[j] + cur);
                hold[j] = max(hold[j], sell[j - 1] - cur);
            }
        }
        return sell[k];
    }
};
int main() {
    Solution s;
    return 0;
}
