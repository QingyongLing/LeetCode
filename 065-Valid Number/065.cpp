#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Validate if a given string is numeric.
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/

class Solution {
public:
    bool isNumber(string s) {
        if (s.size() == 0)
            return false;
        vector<int> finde;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'e')
                finde.push_back(i);
        }
        int numstart = 0;
        while (numstart < s.size() && s[numstart] == ' ')++numstart;
        int numend = s.size();
        while (numend > 0 && s[numend - 1] == ' ')--numend;
        if (finde.size() > 1)
            return false;
        else if (finde.size() == 0)
            return validnum(s, numstart, numend, true);
        else if (finde[0] != 0)
            return validnum(s, numstart, finde[0], true) && validnum(s, finde[0] + 1, numend, false);
        return false;
    }
    bool validnum(string &s, int start, int end, bool point)
    {
        int num1 = 0, num2 = 0;
        if (start >= end)
            return false;
        for (int i = start; i < end; ++i)
        {
            if (s[i] == '+' || s[i] == '-')
            {
                if (i != start || i == end - 1)
                    return false;
                ++num1;
                if (num1 > 1)
                    return false;
            }
            else if (point&&s[i] == '.')
            {
                if (i == start &&i + 1 < end && (s[i + 1] < '0' || s[i + 1] > '9'))
                    return false;
                if (i == start &&i + 1 == end)
                    return false;
                if (i == end - 1 && (s[i - 1] < '0' || s[i - 1] > '9'))
                    return false;
                ++num2;
                if (num2 > 1)
                    return false;
            }
            else if (s[i]<'0' || s[i]>'9')
                return false;
        }
        return true;
    }
};
int main()
{    
    Solution s;  
    vector<string> vec = { "   ","0 ", " 0.1", "abc", "1 a", "2e10" };
    for (auto &c : vec)
        cout << (s.isNumber(c) ?"true" : "false") << endl;
    system("pause");
}
