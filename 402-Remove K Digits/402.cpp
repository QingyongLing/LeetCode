#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Given a non-negative integer num represented as a string, remove k digits from the number so that
the new number is the smallest possible.
Note:
•The length of num is less than 10002 and will be ≥ k.
•The given num does not contain any leading zero.
Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == 0) return num;
        if (k >= num.size()) return string("0");
        string result;
        for (int i = 0; i < num.size(); ++i) {
            while (k && !result.empty() && num[i] < result.back())
                --k, result.pop_back();
            result.push_back(num[i]);
        }
        while (k && !result.empty())--k, result.pop_back();
        auto index = result.find_first_not_of('0');
        if (index == result.npos)
            return string("0");
        else
            return index == 0 ? result : result.substr(index);
    }
};

int main() {
    Solution s;
    cout << s.removeKdigits("10200", 2) << endl;
    return 0;
}