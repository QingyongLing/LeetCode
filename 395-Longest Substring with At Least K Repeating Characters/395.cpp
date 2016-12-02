#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Find the length of the longest substring T of a given string (consists of lowercase letters only) 
such that every character in T appears no less than k times.
Example 1:
Input:
s = "aaabb", k = 3
Output:
3
The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:
Input:
s = "ababbc", k = 2
Output:
5
The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k < s.size())
            return longestsubimpl(s, 0, s.size() - 1, k);
        else
            return 0;
    }
private:
    int longestsubimpl(string &s, int left, int right, int k) {
        if (right - left + 1 < k) return 0;
        deque<int> count[26] = {};
        for (int i = left; i <= right; ++i)
            count[s[i] - 'a'].push_back(i);
        vector<int> index(1, left - 1);
        for (int i = 0; i < 26; ++i) {
            if (count[i].size() < k) {
                for (int n : count[i]) index.push_back(n);
            }
        }
        index.push_back(right + 1);
        if (index.size() == 2) return right - left + 1;
        sort(index.begin(), index.end());
        int len = 0;
        for (int i = 0; i < index.size() - 1; ++i)
            len = max(len, longestsubimpl(s, index[i] + 1, index[i + 1] - 1, k));
        return len;
    }
};

int main() {
    Solution s;
    cout << s.longestSubstring("aaabbashdhsjsshggdjsgsjgdjsjj",3) << endl;
    return 0;
}