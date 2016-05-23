/*
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
2->abc 3->def .... 9->wxyz
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
author=Ling
date=2016.5.23
*/
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    //Runtime: 0 ms 23333333
    vector<string> letterCombinations(string digits) {
        static vector<string> mappingdtol = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> result;
        if (digits.size() == 0)
            return result;
        vector<int> index(digits.size(), 0);
        const int flag = mappingdtol[digits[0] - '0'].size();
        while (index[0] < flag)
        {
            string temp(digits.size(), 0);
            for (int i = 0; i < digits.size(); ++i)
                temp[i] = mappingdtol[digits[i] - '0'][index[i]];
            result.push_back(temp);
            index[digits.size() - 1]++;
            for (int i = index.size() - 1; i > 0;--i)
                if (index[i] >= mappingdtol[digits[i] - '0'].size()){ ++index[i - 1]; index[i] = 0; }
        }
        return result;
    }
};
int main() {
    Solution s;
    string str = "23";
    auto result = s.letterCombinations(str);
    for (auto &c : result)
        cout << c << " ";
    cout << endl;
  return 0;
}
