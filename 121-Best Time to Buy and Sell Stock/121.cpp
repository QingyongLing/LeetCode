#include <iostream>
#include <vector>
using namespace std;
/*
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5
max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0
In this case, no transaction is done, i.e. max profit = 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int minnum = prices[0];
        int maxpro = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < minnum)
                minnum = prices[i];
            else
                maxpro = maxpro > (prices[i] - minnum) ? maxpro : (prices[i] - minnum);
        }
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
