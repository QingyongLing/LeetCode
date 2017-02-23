#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Given an integer, return its base 7 string representation.
Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].
*/

class Solution {
public:
    string convertToBase7(int num) {
        string answer;
        if (num == 0)return "0";
        bool flag = num < 0 ? true : false;
        num = abs(num);
        while (num) {
            answer.push_back(num % 7 + '0');
            num /= 7;
        }
        if (flag)answer.push_back('-');
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
int main() {
    Solution s;
    cout << s.convertToBase7(7) << endl;
    return 0;
}
