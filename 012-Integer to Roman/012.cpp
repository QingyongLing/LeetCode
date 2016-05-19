//Given an integer, convert it to a roman numeral.
//Input is guaranteed to be within the range from 1 to 3999.
//Runtime: 28 ms
//Your runtime beats 88.37% of cppsubmissions
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string intToRoman(int num)
    {
        static char* romanstr[4][10] =
        {
            { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
            { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
            { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
            { "", "M", "MM", "MMM" }
        };
        string result;
        result.append(romanstr[3][num / 1000]);
        result.append(romanstr[2][num / 100 % 10]);
        result.append(romanstr[1][num / 10 % 10]);
        result.append(romanstr[0][num % 10]);
        return result;
    }
};
int main()
{
    Solution s;
    cout<<s.intToRoman(3999)<<endl;
    return 0;
}
