#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
class Solution {
public:
    //最多买两次那就划分成两部分，两部分的和的最大值就是总的最大值
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int minnum = prices.front();
        int maxpro = 0;
        vector<int> profitleft(prices.size(), 0);
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < minnum)
                minnum = prices[i];
            else
                maxpro = max(maxpro, prices[i] - minnum);
            profitleft[i] = maxpro;
        }

        int maxnum = prices.back();
        maxpro = 0;
        vector<int> profitright(prices.size(), 0);
        for (int i = prices.size() - 1; i >= 0; --i) {
            if (prices[i] > maxnum)
                maxnum = prices[i];
            else
                maxpro = max(maxpro, maxnum - prices[i]);
            profitright[i] = maxpro;
        }
        maxpro = 0;
        for (int i = 0; i < profitleft.size() - 1; ++i) {
            maxpro = max(profitleft[i] + profitright[i + 1], maxpro);
        }
        return max(profitleft.back(), maxpro);
    }
};
int main() {
    Solution s;
    vector<int> vec = { 1,2 };
    cout << s.maxProfit(vec) << endl;
    system("pause");
    return 0;
}