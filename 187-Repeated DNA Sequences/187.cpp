#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> vec;
        if (s.size() < 10) return vec;
        unordered_map<string, pair<int, int>> map;
        for (int i = 0; i < s.size() - 9; ++i) {
            string temp(s.begin() + i, s.begin() + i + 10);
            auto iter = map.find(temp);
            if (iter == map.end()) {
                map.insert(make_pair(temp, make_pair(i, 1)));
            }else{
                int num = ++iter->second.second;
                if (num == 2)
                    vec.push_back(temp);
            }
        }
        return vec;
    }
    //自己写一个编码
    //A: 0100 0001　　C: 0100 0011　　G: 0100 0111　　T: 0101 0100
    //取最后三位
    vector<string> findRepeatedDnaSequences2(string s) {
        vector<string> vec;
        if (s.size() < 10) return vec;
        unordered_map<int, int> map;
        int bithash = 0, num = 9, index = 0;
        while (num--) {
            bithash = (bithash << 3) | (s[index++] & 7);
        }
        for (int i = 9; i < s.size(); ++i) {
            bithash = ((bithash & 0x7ffffff) << 3)|(s[i] & 7);
            auto iter = map.find(bithash);
            if (iter == map.end()) {
                map.insert(make_pair(bithash, 1));
            }
            else {
                if (++iter->second==2)
                    vec.push_back(string(s.begin() + i - 9, s.begin() + i + 1));
            }
        }
        return vec;
    }
};
int main() {
    Solution s;
    string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    for (auto &s : s.findRepeatedDnaSequences2(str))
        cout << s << endl;
    system("pause");
    return 0;
}