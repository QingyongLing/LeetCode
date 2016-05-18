//Given a roman numeral, convert it to an integer.
//Input is guaranteed to be within the range from 1 to 3999.
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
   //Runtime: 36 ms
   //Your runtime beats 79.77% of cppsubmissions.
    int romanToInt(string s) {
    static vector<vector<string>> romanstr= {
				{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
				{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
				{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
				{ "", "M", "MM", "MMM" }
		};
		int result = 0, index = 0;
		while (s[index] == 'M'){ result += 1000; ++index; }
		if (s[index] == 'C' || s[index] == 'D')
			findroman(romanstr[2], s, result, index, 100);
		if (s[index] == 'X' || s[index] == 'L')
			findroman(romanstr[1], s, result, index, 10);
		if (s[index] == 'I' || s[index] == 'V')
			findroman(romanstr[0], s, result, index, 1);
		return result;
	}
	void findroman(vector<string>& strs, string& s, int &result, int &index, int incre)
	{
		for (int i = strs.size() - 1; i > 0; --i)
		{
			if (s.find(strs[i], index) ==index)
			{
				result += i * incre;
				index += strs[i].size();
				break;
			}
		}
	}
};
int main()
{
  Solution s;
  cout<<s.romanToInt("MCCCXCIV")<<endl;
  return 0;
}
