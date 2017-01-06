#include <iostream>
using namespace std;
/*
The Hamming distance between two integers is the number of positions at which the 
corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
Note:
0 ≤ x, y < 2^31.
Example:
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
↑   ↑
The above arrows point to positions where the corresponding bits are different.
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int num = x^y, result = 0;
        for (int i = 0; i < 31; ++i) {
            if (num & 1)++result;
            num >>= 1;
        }
        return result;
    }
};
int main() {
    Solution s;
    cout << s.hammingDistance(1, 4) << endl;
}
