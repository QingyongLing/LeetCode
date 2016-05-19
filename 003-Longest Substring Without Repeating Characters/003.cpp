//Given a string, find the length of the longest substring without repeating characters.
//Examples:
//Given "abcabcbb", the answer is "abc", which the length is 3.
//Given "bbbbb", the answer is "b", with the length of 1.
//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

// 2016-5-7

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <time.h>
#include <hash_map>
#include <string>
#include <set>
using namespace std;

class Solution
{
public:
    //96 ms Your runtime beats 13.58% of cppsubmissions
    int lengthOfLongestSubstring(string s)
    {
        int maxlength = 0;
        bool flag[128] = { false };
        for (int i = 0; i < s.size(); ++i)
        {
            if (!flag[s[i]])
                flag[s[i]] = true;
            else
            {
                int temp = 0;
                for_each(flag + 32, flag + 128, [&temp](bool &b)
                {
                    b = b ? (++temp, false) : false;
                });
                maxlength = temp > maxlength ? temp : maxlength;
                //»ØËÝÖÁÖØ¸´×Ö·û
                char c = s[i];
                while (s[--i] != c) {};
            }
        }
        int temp = 0;
        for_each(flag + 32, flag + 128, [&temp](bool &b)
        {
            b = b ? (++temp, false) : false;
        });
        maxlength = temp > maxlength ? temp : maxlength;
        return maxlength;
    }
    //16 ms Your runtime beats  61.72% of cppsubmissions
    int lengthOfLongestSubstring2(string s)
    {
        int maxlength = 0, begin = 0;
        bool flag[128] = { false };
        int  index[128] = { 0 };
        for (int i = 0; i < s.size(); ++i)
        {
            if (!flag[s[i]])
            {
                flag[s[i]] = true;
                index[s[i]] = i;
            }
            else
            {
                int temp = i - begin;
                maxlength = temp>maxlength ? temp : maxlength;
                for (int j = begin; j < index[s[i]]; ++j)
                    flag[s[j]] = false;
                begin = index[s[i]] + 1;
                index[s[i]] = i;
            }
        }
        int temp = s.size() - begin;
        maxlength = temp>maxlength ? temp : maxlength;
        return maxlength;
    }
    //from leetcode  12ms  Your runtime beats 97.04% of cppsubmissions
    int lengthOfLongestSubstring3(string s)
    {
        int n = s.length(), ans = 0;
        int index[128] = { 0 };
        for (int j = 0, i = 0; j < n; ++j)
        {
            i = index[s[j]]>i ? index[s[j]] : i;
            ans = ans > j - i + 1 ? ans : j - i + 1;
            index[s[j]] = j + 1;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring3("abcabcbb");
    cout << s.lengthOfLongestSubstring3("aab");
    cout << s.lengthOfLongestSubstring3("a");
    cout << s.lengthOfLongestSubstring3("aa");
    cout << s.lengthOfLongestSubstring3("pwwkew");
    cout << s.lengthOfLongestSubstring3("dvdf");
    cout << s.lengthOfLongestSubstring3("abba");
    system("pause");
}