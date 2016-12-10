#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Given a non-empty string containing an out-of-order English representation of digits 0-9, 
output the digits in ascending order.
Note:
1.Input contains only lowercase English letters.
2.Input is guaranteed to be valid and can be transformed to its original digits. That means 
invalid inputs such as "abc" or "zerone" are not permitted.
3.Input length is less than 50,000.
Example 1:
Input: "owoztneoer"
Output: "012"
Example 2:
Input: "fviefuro"
Output: "45"
*/
class Solution {
public:
    string originalDigits(string s) {
        int count[26] = {};
        for (int i = 0; i < s.size(); ++i)
            ++count[s[i] - 'a'];
        string strs[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
        vector<int> numbers(10, 0);
        string first("zwuxg"), second("otfsi"), result;
        for (int i = 0; i < 5; ++i)
            remove(count, strs[i * 2], count[first[i] - 'a'], numbers, 2 * i);
        for (int i = 0; i < 5; ++i)
            remove(count, strs[i * 2 + 1], count[second[i] - 'a'], numbers, 2 * i + 1);
        for (int i = 0; i < 10; ++i) 
            result.append(string(numbers[i], '0' + i));
        return result;
    }
private:
    void remove(int *count, string &str, int times, vector<int> &numbers, int n) {
        if (times == 0) return;
        numbers[n] += times;
        for (int j = 0; j < str.size(); ++j)
            count[str[j] - 'a'] -= times;
    }
};

int main() {
    Solution s;
    cout << s.originalDigits("owoztneoer") << endl;
}