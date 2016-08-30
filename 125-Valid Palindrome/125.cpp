#include <iostream>
#include <string>
using namespace std;
/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int charnum = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (alphorcharacters(s[i]))
                ++charnum;
        }
        if (charnum <= 1)
            return true;
        else {
            int left = 0, right = s.size() - 1;
            while (left < right) {
                while (!alphorcharacters(s[left]))
                    ++left;
                while(!alphorcharacters(s[right]))
                    --right;
                if (!compare(s[left++], s[right--]))
                    return false;
            }
            return true;
        }
    }
    bool alphorcharacters(char c) {
        if ((c <= 'Z'&&c >= 'A') || (c <= 'z'&&c >= 'a') || (c <= '9'&&c >= '0'))
            return true;
        return false;
    }
    bool compare(char a, char b) {
        if (a <= '9'&&a >= '0'&&b <= '9'&&b >= '0')
            return a == b;
        else {
            a = (a <= 'Z'&&a >= 'A') ? (a + 'a' - 'A') : a;
            b = (b <= 'Z'&&b >= 'A') ? (b + 'a' - 'A') : b;
            return a == b;
        }
    }
};
int main()
{  
    Solution s;    
    cout << (s.isPalindrome("A man, a plan, a canal: Panama") ? "true" : "false") << endl;
    system("pause");
    return 0;
}
