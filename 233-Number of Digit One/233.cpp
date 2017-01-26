#include <iostream>
#include <algorithm>
using namespace std;
/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
Hint:
1.Beware of overflow.
*/

class Solution {
public:
    int countDigitOne(int n) {
        if (n < 0)return 0;
        int left = 0, cur = 0, tens = 1, result = 0;
        while (n){
            cur = n % 10;
            n /= 10;
            if (cur == 1)
                result += left + 1;
            else if (cur > 1)
                result += tens;
            result += tens*n;
            left += cur*tens;
            tens *= 10;
        }
        return result;
    }
};
int main() {
    Solution s;
    return 0;
}