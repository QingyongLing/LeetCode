#include <iostream>
using namespace std;
/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Note: Do not use any built-in library function such as sqrt.
Example 1:
Input: 16
Returns: True
Example 2:
Input: 14
Returns: False
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        if (num == 0 || num == 1) return true;
        int lo = 1, hi = num / 2;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid < num / mid)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo*lo == num;
    }
};

int main() {
    Solution s;
    cout << s.isPerfectSquare(4) << endl;
    return 0;
}