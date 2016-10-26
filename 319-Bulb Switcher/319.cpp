#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.
Example:
Given n = 3.
At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off].
So you should return 1, because there is only one bulb is on.
Subscribe to see which companies asked this question
*/

class Solution {
public:
    //约数个数定理    只有某数平方开着
    int bulbSwitch(int n) {
        return sqrt(n);
    }
    int bulbSwitch2(int n) {
        vector<int> flag(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; j+=i)
                ++flag[j];
        }
        int result = 0;
        for (int i = 1; i <= n; ++i)
            if (flag[i] % 2 == 1) ++result;
        return result;
    }  
};
int main() {
    Solution s;
    int num = 999229;
    cout << s.bulbSwitch(num) << endl;
    cout << s.bulbSwitch2(num) << endl;
    return 0;
}