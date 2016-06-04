/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.
Note: The sequence of integers will be represented as a string.

Author=Ling
Date=2016.6.4
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
         const char* s[] = { "1", "11", "21", "1211", "111221" };
        string str(s[4]);
        if (n <= 5)
            return s[n - 1];
        else
            iteration(str, n - 5);
        return str;
    }
    void iteration(string& str, int n)
    {
        if (n == 0)
            return;
        string temp;
        int i = 0;
        while (1)
        {
            int count = 1;
            char c = str[i];
            while (i < str.size() - 1 && str[++i] == c){ ++count; };
            temp.push_back('0' + count);
            temp.push_back(c);
            if (i == str.size() - 1)
            {
                if (str[i] != str[i - 1])
                {
                    temp.push_back('1');
                    temp.push_back(str[str.size() - 1]);
                }
                break;
            }
        };
        str = temp;
        iteration(str, n - 1);
    }
};

int main()
{
    Solution s;
    cout<<s.countAndSay(7)<<endl;
    return 0;
}
