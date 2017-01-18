#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
For example,
•Given numerator = 1, denominator = 2, return "0.5".
•Given numerator = 2, denominator = 1, return "2".
•Given numerator = 2, denominator = 3, return "0.(6)".
Hint:
1.No scary math, just apply elementary math knowledge. Still remember how to perform a long division?
2.Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?
3.Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.
Credits:
Special thanks to @Shangrila for adding this problem and creating all test cases.
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long llnumerator = numerator, lldenominator = denominator;
        llnumerator = abs(llnumerator);
        lldenominator = abs(lldenominator);
        string str;
        if (numerator && ((numerator^denominator)&(1 << 31)))
            str.push_back('-');
        str.append(to_string(llnumerator / lldenominator));
        llnumerator %= lldenominator;
        if (llnumerator == 0)return str;
        str.push_back('.');
        unordered_map<long long, size_t> index;
        while (llnumerator) {
            index.insert(make_pair(llnumerator, str.size()));
            llnumerator *= 10;
            long long n = llnumerator / lldenominator;
            str.push_back('0' + n);
            llnumerator %= lldenominator;
            auto iter = index.find(llnumerator);
            if (iter != index.end()) {
                str.insert(str.begin() + iter->second, '(');
                str.push_back(')');
                return str;
            }
        }
        return str;
    }
};
int main() {
    Solution s;
    cout << s.fractionToDecimal(1, 3) << endl;
    return 0;
}
