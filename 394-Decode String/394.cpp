#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Given an encoded string, return it's decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets 
is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; No extra white spaces, square brackets 
are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and that digits
are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
Examples:
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

class Solution {
public:
    string decodeString(string s) {
        string result;
        if (s.empty()) return result;
        decodeimpl(s, result, 0, s.size() - 1);
        return result;
    }
private:
    void decodeimpl(string &s, string &result, int left, int right) {
        if (isalpha(s[left])) {
            while (left <= right&&isalpha(s[left]))
                result.push_back(s[left++]);
            if (left <= right&&isalnum(s[left]))
                decodeimpl(s, result, left, right);
        }
        else {
            int index = s.find('[', left);
            int repeat = stoi(s.substr(left, index - left));
            string subleft, subright;
            int num = 1, next = index;
            while (num != 0) {
                ++next;
                if (s[next] == '[')++num;
                else if (s[next] == ']')--num;
            }
            decodeimpl(s, subleft, index + 1, next - 1);
            if (next < right) decodeimpl(s, subright, next + 1, right);
            for (int i = 0; i < repeat; ++i) {
                result.append(subleft);
            }
            result.append(subright);
        }
    }
};

int main() {
    Solution s;
    cout << s.decodeString("3[a2[c]ss]") << endl;
    return 0;
}