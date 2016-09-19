#include <iostream>
using namespace std;
/*
Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
class Solution {
public:
    //注意：用i*5*5*5....的方法可能导致int溢出
    int trailingZeroes(int n) {
        int result = 0;
        for (int i = 5; i <= n; n /= 5) {
            result += n / i;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.trailingZeroes(1808548329) << endl;
    system("pause");
    return 0;
}