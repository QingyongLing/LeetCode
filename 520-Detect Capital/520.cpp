#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Given a word, you need to judge whether the usage of capitals in it is right or not.
We define the usage of capitals in a word to be right when one of the following cases holds:
1.All letters in this word are capitals, like "USA".
2.All letters in this word are not capitals, like "leetcode".
3.Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.empty())return true;
        if (word.size() == 1)
            return  true;
        int index = 1;
        if (islower(word[0])) {
            return find_if(word, 1, word.size(), isupper);
        }
        else {
            if (islower(word[1]))
                return find_if(word, 2, word.size(), isupper);
            else
                return find_if(word, 2, word.size(), islower);
        }
    }
private:
    bool find_if(string &word, int left, int right, int(*fun)(int)) {
        for (int i = left; i < right; ++i) {
            if (fun(word[i]))return false;
        }
        return true;
    }
};
int main() {
    Solution s;
    cout << s.detectCapitalUse("abC") << endl;
    return 0;
}
