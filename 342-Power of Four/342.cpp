#include <iostream>
using namespace std;
/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
Example:
Given num = 16, return true. Given num = 5, return false.
Follow up: Could you solve it without loops/recursion?
Credits:
Special thanks to @yukuairoy  for adding this problem and creating all test cases.
*/
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 0) return false;
        else {
            int flag = 0x55555555;
            return ((num & (num - 1)) == 0) && ((flag & num) != 0);
        }
    }
};
int main() {
    Solution s;
    cout << s.isPowerOfFour(8) << endl;
    return 0;
}