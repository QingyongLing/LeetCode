#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Write a function that takes a string as input and reverse only the vowels of a string.
Example 1:
Given s = "hello", return "holle".
Example 2:
Given s = "leetcode", return "leotcede".
Note:
The vowels does not include the letter "y".
*/
class Solution {
public:
    string reverseVowels(string s) {
        if (s.length() < 2) return s;
        string vowels("aeiouAEIOU");
        int lo = 0, hi = s.length() - 1;
        while (lo < hi)
        {
            while (vowels.find(s[lo]) == string::npos && lo<hi) lo++;
            while (vowels.find(s[hi]) == string::npos && lo<hi) hi--;
            swap(s[lo++], s[hi--]);
        }
        return s;
    }
};
int main() {
    Solution s;
    cout << s.reverseVowels("Leetcode");
    return 0;
}