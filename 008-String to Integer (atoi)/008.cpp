#include <iostream>
#include <string>
using namespace std;
class Solution2 {
public:
	//Runtime: 8 ms
	//Your runtime beats 67.28% of cppsubmissions
	int myAtoi(string str) {
		int index = 0;
		int result = 0;
		while (str[index] == ' '){ ++index; }
		bool positive = true;
		if (str[index] == '-' || str[index] == '+')
		{
			positive = str[index] == '-' ? false : true;
			++index;
		}
		while (str[index] == '0'){ ++index; }
		if ('0' <= str[index] && str[index] <= '9')
		{
			int start = index;
			while (index < str.size() && '0' <= str[index] && str[index] <= '9'){ ++index; }
			string numstr = str.substr(start, index - start);
			//-2147483648...2147483647
			if (numstr.size()>10)
				return positive ? 2147483647 : -1 - 2147483647;
			else if (numstr.size() == 10)
			{
				const string intmaxstr("2147483647");
				for (int i = 0; i < 10; ++i)
					if (numstr[i]>intmaxstr[i])
						return positive ? 2147483647 : -1 - 2147483647;
					else if (numstr[i]<intmaxstr[i])
						break;
			}
			int ten[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
			for (int i = 0; i < numstr.size(); ++i)
				result += (numstr[i] - '0')*(ten[numstr.size() - i - 1]);
		}
		return positive ? result : -result;
	}
};

int main()
{
	Solution2 s;
	cout << s.myAtoi("   +123445") << endl;
	cout << s.myAtoi("   +000022") << endl;
	cout << s.myAtoi("   +22ds3728") << endl;
	cout << s.myAtoi(" -2147483647") << endl;
	cout << s.myAtoi(" 2147483647") << endl;
	cout << s.myAtoi(" -2147483648") << endl;
	cout << s.myAtoi(" -2147483649") << endl;
	cout << s.myAtoi("1095502006p8") << endl;
}
