#include <iostream>
#include <string>
using namespace std;

/*
Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        bool add = false;       
        int size = max(a.size(), b.size());
        string result(size, '0');
        for (int i = 0; i < size; ++i)
        {
            int temp = add ? 1 : 0;
            if (i < a.size())
                temp += a[i] - '0';
            if (i < b.size())
                temp += b[i] - '0';
            result[i] = temp % 2 + '0';
            add = temp / 2 == 1 ? true : false;
        }
        if (add)
            result.push_back('1');
        reverse(result.begin(), result.end());
        return result;
    }
};
int main()
{    
    Solution s;  
    cout << s.addBinary("111", "1");
    system("pause");
}
