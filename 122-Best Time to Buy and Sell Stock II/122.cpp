#include <iostream>
#include <vector>
using namespace std;
/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as
you like (ie, buy one and sell one share of the stock multiple times). However, you may 
not engage in multiple transactions at the same time (ie, you must sell the stock before
you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int minnum = prices[0];
        int maxpro = 0;
        for (int i = 1; i < prices.size() - 1; ++i) {
            if (prices[i] < minnum)
                minnum = prices[i];
            else if (prices[i + 1] < prices[i]) {                
                maxpro += prices[i] - minnum;
                minnum = prices[i];
            }
        }
        if (prices[prices.size() - 1] > minnum)
            maxpro += prices[prices.size() - 1] - minnum;
        return maxpro;
    }
};
int main()
{  
    Solution s;
    vector<int> vec = { 7, 1, 5, 3, 6, 4 };
    cout << s.maxProfit(vec) << endl;
    system("pause");
    return 0;
}
