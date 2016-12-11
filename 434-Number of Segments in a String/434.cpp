#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Count the number of segments in a string, where a segment is defined to be a contiguous
sequence of non-space characters.
Please note that the string does not contain any non-printable characters.
Example:
Input: "Hello, my name is John"
Output: 5
*/
class Solution {
public:
    int countSegments(string s) {
        int size = s.size(), index = 0, count = 0;
        while (index < size) {
            if (s[index] != ' ') {
                ++count;
                while (index < size&&s[++index] != ' ');
            }
            else ++index;
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.countSegments("  Hello , my name is John ! ") << endl;
}