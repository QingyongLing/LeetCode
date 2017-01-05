#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
Given a string, sort it in decreasing order based on the frequency of characters.
Example 1:
Input:
"tree"
Output:
"eert"
Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:
Input:
"cccaaa"
Output:
"cccaaa"
Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:
Input:
"Aabb"
Output:
"bbAa"
Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for (char c : s)++map[c];
        vector<pair<char, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), [](pair<char, int> &a, pair<char, int> &b) {return b.second < a.second; });
        string result;
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i].first == 0) break;
            result.append(string(vec[i].second, vec[i].first));
        }
        return result;
    }
};
int main() {
    Solution s;
    cout << s.frequencySort("Aabb              aabdbsbbsdjb") << endl;
}
