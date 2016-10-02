#include <iostream>
using namespace std;
/*
Given an integer, write a function to determine if it is a power of two.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int i = 0; i < 31; ++i)
            if ((1 << i) == n) return true;
        return false;
    }
};
int main() {
    Solution s;
    system("pause");
    return 0;
}