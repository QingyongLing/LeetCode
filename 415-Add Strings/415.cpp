#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.
Note:
1.The length of both num1 and num2 is < 5100.
2.Both num1 and num2 contains only digits 0-9.
3.Both num1 and num2 does not contain any leading zero.
4.You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        size_t maxsize = max(num1.size(), num2.size());
        string sum(maxsize, '0');
        bool flag = false;
        int s1 = num1.size(), s2 = num2.size();
        for (int i = 0; i < maxsize; ++i) {
            char c = '0';
            if (i < s1)c += num1[s1 - i - 1] - '0';
            if (i < s2)c += num2[s2 - i - 1] - '0';
            sum[i] = c;
            if (flag) sum[i] += 1;
            if (sum[i] - '0' > 9)
                flag = true, sum[i] -= 10;
            else
                flag = false;
        }
        if (flag) sum.push_back('1');
        reverse(sum.begin(), sum.end());
        return sum;
    }
};

int main() {
    Solution s;
    cout << endl;
}