#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. 
The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned 
in the top-left room and must fight his way through the dungeon to rescue the princess.
The knight has an initial health point represented by a positive integer. If at any point his health point 
drops to 0 or below, he dies immediately.
Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these 
rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive 
integers).
In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward
in each step.
Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the 
optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
-2(K) -3     3
-5    -10    1
10    30     -5(P)
Notes:
•The knight's health has no upper bound.
•Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room
where the princess is imprisoned.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
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
