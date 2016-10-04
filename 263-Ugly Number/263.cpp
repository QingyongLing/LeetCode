#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
Note that 1 is typically treated as an ugly number.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
class Solution {
public:
    bool isUgly(int num) {
        int value[] = { 2,3,5 };
        while (num != 1) {
            int temp = num;
            for (auto c : value)
                if (num%c == 0) num /= c;
            if (temp == num) return false;
        }
        return true;
    }
};
int main() {    
    Solution s;
    system("pause");
    return 0;
}