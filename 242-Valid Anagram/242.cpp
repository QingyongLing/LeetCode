#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Given two strings s and t, write a function to determine if t is an anagram of s.
For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
Note:
You may assume the string contains only lowercase alphabets.
Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int snum[26] = { 0 };
        int tnum[26] = { 0 };
        for (auto c : s)
            snum[c - 'a']++;
        for (auto c : t)
            tnum[c - 'a']++;
        for (int i = 0; i<26; ++i)
            if (snum[i] != tnum[i]) return false;
        return true;
    }
};
int main() {    
    Solution s;
   
    system("pause");
    return 0;
}