/*
Implement strStr().
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Author=Ling
Date=2016.5.28
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    //Runtime: 4 ms
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        if (haystack.size() < needle.size())
            return -1;
        int left = 0, right = needle.size()-1;
        auto compare = [](string& hay, string &need, int index)->bool
        {
            int temp = 0;
            while (temp < need.size() && index < hay.size())
                if (hay[index++] != need[temp++])
                    return false;
            return temp == need.size() ? true : false;
        };
        for (int i = 0; i <= haystack.size() - needle.size(); ++i)
        {
            if (haystack[i] == needle[left] && haystack[i + right] == needle[right])
                if (compare(haystack, needle, i))
                    return i;
        }
        return -1;
    }
};
int main(int argc, char const *argv[]) {
    Solution s;
    string s1="abbbbbbbbbbbbbbbbbbbcd";
    string s2="bc";
    cout<<s.strStr(s1, s2)<<endl;
    return 0;
}
