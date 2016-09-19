#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:
1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB
Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases.
*/
class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n) {
            int temp = (n-1) % 26;
            result.push_back('A' + temp);
            n = (n - 1) / 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution s;
    cout << s.convertToTitle(28) << endl;
    system("pause");
    return 0;
}