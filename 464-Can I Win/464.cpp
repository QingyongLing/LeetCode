#include <iostream>
#include <vector>
using namespace std;
/*
In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes 
the running total to reach or exceed 100 wins.
What if we change the game so that players cannot re-use integers?
For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they 
reach a total >= 100.
Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a 
win, assuming both players play optimally.
You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.
Example
Input:
maxChoosableInteger = 10
desiredTotal = 11
Output:
false
Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.
*/

class Solution {
public:
    //https://discuss.leetcode.com/topic/68896/java-solution-using-hashmap-with-detailed-explanation
    //https://discuss.leetcode.com/topic/69330/quick-c-dp-solution-with-bit-maniplutaion-only-49ms
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (1 + maxChoosableInteger)*maxChoosableInteger / 2;
        if (desiredTotal > sum) return false;
        if (desiredTotal <= 0) return true;
        maxchoint = maxChoosableInteger;
        state = 0;
        vec = vector<int>(1 << maxChoosableInteger, -1);
        return helper(desiredTotal);
    }
private:
    vector<int> vec;
    int state;
    int maxchoint;
    bool helper(int desiresTotal) {
        if (desiresTotal <= 0)return false;
        if (vec[state] != -1)return vec[state];
        int mask = 1;
        for (int i = 0; i < maxchoint; ++i) {
            if (!(state&mask)) {
                state |= mask;
                if (!helper(desiresTotal - i - 1)) {
                    state &= ~mask;
                    vec[state] = 1;
                    return true;
                }
                state &= ~mask;
            }
            mask <<= 1;
        }
        vec[state] = 0;
        return false;
    }
};
int main() {
    Solution s;
    cout << s.canIWin(10, 54) << endl;
    return 0;
}
