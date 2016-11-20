#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Write a function that takes a string as input and returns the string reversed.
Example:
Given s = "hello", return "olleh".
*/
class Solution {
public:
    string reverseString(string s) {
        int lo = 0, hi = s.size() - 1;
        while (lo<hi) {
            swap(s[lo++], s[hi--]);
        }
        return s;
    }
};
int main() {
    Solution s;
    return 0;
}