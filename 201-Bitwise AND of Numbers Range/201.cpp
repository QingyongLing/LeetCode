#include <iostream>
using namespace std;
/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
For example, given the range [5, 7], you should return 4.
Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n) return m;
        int num = n - m + 1, result = 0;
        for (int i = 0; i < 31; ++i) {
            int temp = 1 << i;
            if (temp >= num) {
                if ((m / temp) % 2 && (n / temp) % 2)
                    result += temp;
            }
        }
        return result;
    }
};
int main() {
    Solution s; 
    cout << s.rangeBitwiseAnd(5, 7) << endl;
    system("pause");
    return 0;
}