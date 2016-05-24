/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

author=Ling
date=2016.5.24
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    //Runtime: 0 ms
    bool isValid(string s) {
         if (s.size() < 2)
            return false;
        stack<char> mystack;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                mystack.push(s[i]);
            else
            {
                if (mystack.size() == 0)
                    return false;
                if ((s[i] == ')'&&mystack.top() == '(')
                    || (s[i] == ']'&&mystack.top() == '[')
                    || (s[i] == '}'&&mystack.top() == '{'))
                    mystack.pop();
                else
                    return false;
            }
        }
        return mystack.size() == 0 ? true : false;
    }
};
int main()
{
    Solution s;
    cout<<s.isValid("()]")<<endl;
    return 0;
}
