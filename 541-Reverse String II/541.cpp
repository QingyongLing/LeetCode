#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from
the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k
but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions: 
1. The string consists of lower English letters only.
2. Length of the given string and k will in the range [1, 10000]
*/

class Solution {
public:
    string reverseStr(string s, int k) {
        if (k == 1)return s;
        int num = (s.size() + (2 * k - 1)) / (2 * k);
        for (int i = 0; i < num; ++i) {
            int right = min((i + 1) * 2 * k, (int)s.size());
            reversestr(s, i * 2 * k, right, k);
        }
        return s;
    }
private:
    void reversestr(string &s, int left, int right, int k) {
        if (right - left > k - 1) {
            reverse(s.begin() + left, s.begin() + left + k);
        }
        else {
            reverse(s.begin() + left, s.begin() + right);
        }
    }
};

int main() {
    Solution s;
    cout << s.reverseStr("abcdefg", 1) << endl;
    cout << s.reverseStr("abcdefi", 2) << endl;
    cout << s.reverseStr("abcdefghi", 2) << endl;
    return 0;
}