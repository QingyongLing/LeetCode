#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you 
like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
•You may not engage in multiple transactions at the same time (ie, you must sell the stock before 
you buy again).
•After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:
prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

class Solution {
public:
    //From: http://www.cnblogs.com/grandyang/p/4997417.html
    int maxProfit(vector<int>& prices) {
        int last_buy = 0, last_sell = 0, buy = INT_MIN, sell = 0;
        for (int price : prices){
            last_buy = buy;
            buy = max(last_sell - price, last_buy);
            last_sell = sell;
            sell = max(last_buy + price, last_sell);
        }
        return sell;
    }
};
int main(){
    Solution s;
    
    return 0;
}