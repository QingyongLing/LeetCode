#include <iostream>
#include <string>
using namespace std;
/*
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method 
is used.
Note:
1.All letters in hexadecimal (a-f) must be in lowercase.
2.The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single 
zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
3.The given number is guaranteed to fit within the range of a 32-bit signed integer.
4.You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:
Input:
26
Output:
"1a"
Example 2:
Input:
-1
Output:
"ffffffff"
*/
class Solution {
public:
    string toHex(int num) {
        unsigned unum = static_cast<unsigned>(num);
        string str("00000000"), hex("0123456789abcdef");
        for (int i = 0; i < 8; ++i) {
            str[7 - i] = hex[unum % 16];
            unum /= 16;
        }
        auto index = str.find_first_not_of('0');
        if (index == str.npos) return string("0");
        return index == 0 ? str : str.substr(index);
    }
};

int main() {
    Solution s;
    cout << s.toHex(INT_MIN) << endl;
    cout << s.toHex(-1) << endl;
    cout << s.toHex(0) << endl;
    cout << s.toHex(18) << endl;
    return 0;
}