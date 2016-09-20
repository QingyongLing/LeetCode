#include <iostream>
using namespace std;
/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t flag = 1;
        int num = 0;
        for (int i = 0; i < 32; ++i) {
            if (flag&(n >> i))
                ++num;
        }
        return num;
    }
};
int main() {
    Solution s;
    cout << s.hammingWeight(11) << endl;
    system("pause");
    return 0;
}