
//Write a function to find the longest common prefix string amongst an array of strings
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
  //Runtime: 8ms  从竖的方向匹配，多次for循环反而慢
string longestCommonPrefix(vector<string>& strs) {
  if (strs.size() == 0)
    return string("");
  if (strs.size() == 1)
    return strs[0];
  int index = 0;
  while (index<strs[0].size())
  {
    char c = strs[0][index];
    for (int i = 1; i < strs.size(); ++i)
      if (index >= strs[i].size() || c != strs[i][index])
        return  strs[0].substr(0, index);
    ++index;
  }
  return strs[0];
}
//Runtime: 4 ms
string longestCommonPrefix3(vector<string>& strs) {
  if (strs.size() == 0)
    return string("");
  if (strs.size() == 1)
    return strs[0];
  int minstr = strs[0].size();
  for (int i = 1; i < strs.size(); ++i)
    minstr = strs[i].size() < minstr ? strs[i].size() : minstr;
  if (minstr==0)
    return string("");
  for (int i = 1; i < strs.size(); ++i)
  {
    int temp = 0;
    while (temp < minstr&&strs[0][temp] == strs[i][temp]){ ++temp; }
    minstr = temp;
  }
  return strs[0].substr(0,minstr);
}
//Runtime: 4ms  二分
string longestCommonPrefix2(vector<string>& strs) {
  if (strs.size() == 0)
    return string("");
  if (strs.size() == 1)
    return strs[0];
  int minstr=strs[0].size();
  for (int i = 1; i < strs.size(); ++i)
    minstr = strs[i].size() < minstr ? strs[i].size() : minstr;
  if (minstr==0)
    return string("");
  int left = 0;
  int right = minstr - 1;
  while (left <= right) {
    int middle = (left + right) / 2;
    if (isCommonPrefix(strs, left,middle))
      left = middle + 1;
    else
      right = middle - 1;
  }
  return strs[0].substr(0, min(right,left) + 1);
}
bool isCommonPrefix(vector<string>& strs, int &left, int right)
{
  for (int i = 1; i < strs.size(); ++i)
  {
    int index = left;
    do
    {
      if (strs[0][index] != strs[i][index])
        return false;
    } while (++index <= right);
  }
  return true;
}
};
int main()
{
	Solution s;
	vector<string> strs;
	strs.push_back("a");
	strs.push_back("b");
	cout << s.longestCommonPrefix2(strs);
  return 0;
}
