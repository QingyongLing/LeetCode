
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//Given a string S, find the longest palindromic substring in S.
//You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
class Solution6 {
public:
	//Runtime: 84 ms
	//Your runtime beats 38.28% of cppsubmissions
	string longestPalindrome(string s) {
		if (s.size() == 1)
			return s;
		int maxsub = 0;
		int maxsubindex = 0;
		vector<int> index;
		for (int i = 0; i + 2 < s.size(); ++i)
		{
			if (s[i] == s[i + 2])
				index.push_back(i+1);
		}
		for (int i = 0; i < index.size(); ++i)
		{
			int mid = index[i];
			int temp = 0;
			while (1)
			{
				++temp;
				int left = mid - temp;
				int right = mid + temp;
				if (left < 0 || right >= s.size()||s[left]!=s[right])
					break;
			}
			int num = 2 * temp - 1;
			if (num > maxsub)
			{
				maxsub = num;
				maxsubindex = mid;
			}
		}
		index.clear();
		for (int i = 0; i + 1 < s.size(); ++i)
		{
			if (s[i] == s[i + 1])
				index.push_back(i);
		}
		for (int i = 0; i < index.size(); ++i)
		{
			int mid = index[i];
			int temp = 0;
			while (1)
			{
				++temp;
				int left = mid - temp;
				int right =mid + temp +1;
				if (left < 0 || right >= s.size() || s[left] != s[right])
					break;
			}
			int num = 2 * temp;
			if (num > maxsub)
			{
				maxsub = num;
				maxsubindex = index[i];
			}
		}
		string ans;
		int left = 0, right = 0;
		if (maxsub % 2 == 0)
		{
			ans = s.substr(maxsubindex - maxsub / 2 + 1, maxsub);
		}
		else
		{
			ans = s.substr(maxsubindex - maxsub / 2 , maxsub);
		}
		return ans;
	}
	// 76 ms
	// Your runtime beats 47.98% of cppsubmissions.
	string longestPalindrome2(string s) {
		if (s.size() == 1)
			return s;
		int maxsublen = 1;
		int index = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			int len1 = 0, len2 = 0;
			if (i + 1 < s.size() && s[i] == s[i+1])
				len1 = maxsubPalindrome(s, i, i + 1);
			if (i - 1 >= 0 && i + 1 < s.size() && s[i - 1] == s[i + 1])
				len2 = maxsubPalindrome(s, i - 1, i + 1);
			int len = max(len1, len2);
			if (len > maxsublen)
			{
				maxsublen = len;
				index = i;
			}
		}
		if (maxsublen % 2 == 0)
		{
			return s.substr(index - maxsublen / 2 + 1, maxsublen);
		}
		else
		{
			return s.substr(index - maxsublen / 2, maxsublen);
		}
	}
	int maxsubPalindrome(string& s, int left, int right)
	{
		while (1)
		{
			--left;
			++right;
			if (left<0||right>=s.size()||s[left] != s[right])
				break;
		}
		return right - left - 1;
	}
	//Manacher算法，时间复杂度O(n), 空间复杂度O(n)
	//from: http://www.cnblogs.com/TenosDoIt/p/3675788.html
	//s：   $   #  1  #  2  #  2  #  1  #  2  #  3  #  2  #  1  #  ^
	//p：       1  2  1  2  5  2  1  4  1  2  1  6  1   2  1  2  1
	//         mx对称点         j         id         i           mx
	//             |           |          |         |            |
	//  str:  =============================================================
	//  j=2*id-i      关于id对称
	//当i < mx 时，可以得出一个结论p[i] >= min(p[2*id - i], mx - i)
	//(1)mx-i>p[j]  不可能 ,必定满足 p[i]==p[j]
	//(2)mx-i<=p[j] 如果mx-i<p[j]，此时p[i]必定是mx-i，否则可以两边扩展
	//当i >= mx, 无法对p[i]做更多的假设，只能p[i] = 1,然后再去匹配
	//8 ms
	//Your runtime beats 76.46% of cppsubmissions.
	string longestPalindrome3(string s) {
		if (s.size() == 1)
			return s;
		string prestr("#-");
		for_each(s.cbegin(), s.cend(), [&prestr](const char &c){prestr.push_back(c); prestr.push_back('-'); });
		prestr.push_back('*');
		int id = 0, mx = 0;
		vector<int> p(prestr.size(), 0);
		for (int i = 1; i < prestr.size() - 1; ++i)
		{
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
			while (prestr[i + p[i]] == prestr[i - p[i]])
				p[i]++;
			if (i + p[i] > mx)
			{
				mx = i + p[i];
				id = i;
			}
		}
		int maxLen = 0, index = 0;
		for (int i = 1; i < prestr.size() - 1; i++)
			if (p[i] > maxLen)
			{
			    maxLen = p[i];
			    index = i;
			}
		return s.substr((index - maxLen) / 2, maxLen - 1);
	}
};

int main()
{
	Solution6 s;
	cout << s.longestPalindrome3("aaa")<<endl;
	cout << s.longestPalindrome3("aa") << endl;
	cout << s.longestPalindrome3("abb") << endl;
	cout << s.longestPalindrome3("abcba") << endl;
	cout << s.longestPalindrome3("dddddddd") << endl;
	cout << s.longestPalindrome3("abcbe") << endl;
  return 0;
}
