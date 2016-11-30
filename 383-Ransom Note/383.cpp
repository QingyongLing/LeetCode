#include <iostream>
#include <string>
using namespace std;
/*
Given an arbitrary ransom note string and another string containing letters from all the 
magazines, write a function that will return true if the ransom note can be constructed 
from the magazines ; otherwise, it will return false.
Each letter in the magazine string can only be used once in your ransom note.
Note:
You may assume that both strings contain only lowercase letters.
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int rans[26] = {}, maga[26] = {};
        for (auto c : ransomNote) ++rans[c - 'a'];
        for (auto c : magazine) ++maga[c - 'a'];
        for (int i = 0; i < 26; ++i) {
            if (rans[i] > maga[i])
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.canConstruct("aa", "aab") << endl;
    return 0;
}