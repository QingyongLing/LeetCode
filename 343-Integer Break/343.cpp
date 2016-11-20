#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize
the product of those integers. Return the maximum product you can get.
For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
Note: You may assume that n is not less than 2 and not larger than 58.
Hint:
1.There is a simple O(n) solution to this problem.
2.You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2 || n == 3)
            return n - 1;
        int res = n % 3;
        int div = n / 3;
        if (res == 0) {
            return static_cast<int>(pow(3, div));
        }
        else {
            if (res == 1)
                return static_cast<int>(pow(3, div - 1)) * 4;
            else
                return static_cast<int>(pow(3, div)) * 2;
        }
    }
};
int main() {
    Solution s;
    cout << s.integerBreak(20) << endl;
    return 0;
}