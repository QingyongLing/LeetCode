#include <iostream>
using namespace std;
/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).
Example 1:
Input:
3
Output:
3
Example 2:
Input:
11
Output:
0
Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/

class Solution {
public:
    int findNthDigit(int n) {
        int num = 9, i = 1;
        for (i = 1; n > num*i&&i <= 8; ++i) {
            n -= num*i;
            num *= 10;
        }
        int start = num / 9;
        int select = start + (n - 1) / i;
        int unit = i - (n - (select - start)*i);
        while (unit)--unit, select /= 10;
        return select % 10;
    }
};

int main() {
    Solution s;
    cout << s.findNthDigit(2147483647) << endl;
    return 0;
}