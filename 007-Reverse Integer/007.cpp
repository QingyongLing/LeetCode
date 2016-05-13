#include <iostream>
#include <string>
using namespace std;
//Reverse digits of an integer.
//Example1: x = 123, return 321
//Example2 : x = -123, return -321
class Solution {
public:
	//8 ms
	int reverse(int x) {
		if (x == -1 - 2147483647)
			return 0;
		bool flag = x < 0 ? x = -x, true : false;
		string str = to_string(x);
		if (str.size() == 10)
		{
			string intmax = "2147483647";
			for (int i = str.size() - 1; i >= 0; --i)
				if (str[i] < intmax[9 - i])
					break;
				else if (str[i] > intmax[9 - i])
					return 0;
				else
					continue;
		}
		int num = 0;
		for (int i = str.size() - 1; i >= 0; --i)
		{
			num *= 10;
			num += str[i] - '0';
		}
		return flag ? -num : num;
	}
};

int main()
{
	Solution s;
	int num = -1 - 2147483647;
	cout << s.reverse(num) << endl;
  cout << s.reverse(123) << endl;
  cout << s.reverse(-123) << endl;
  return 0;
}
